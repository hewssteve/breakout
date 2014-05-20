#include "breakout/sdlbase.h"
#include "breakout/util.h"

/*
struct World
{

    World()
    {
    }
    World(const glm::vec2 bounds) :
        bounds(bounds)
    {
    }

    glm::vec2 bounds;

};

struct AABB
{

    AABB()
    {
    }
    AABB(float xsize, float ysize) :
        xsize(xsize), ysize(ysize)
    {
    }
    float xsize, ysize;

};

struct Polygon
{

    Polygon()
    {
    }
    Polygon(glm::vec2* points, int num_verts) :
        points(points), num_verts(num_verts)
    {
    }
    glm::vec2* points;
    int num_verts;

};

struct Shape
{

    Shape()
    {
    }
    Shape(GLint offset, GLsizei vert_count) :
        offset(offset), vert_count(vert_count)
    {
    }

    GLint offset;
    GLsizei vert_count;

};

struct Ball
{

    Ball()
    {
    }
    Ball(const glm::vec2& pos, float radius, Shape* shape) :
        pos(pos), radius(radius)
    {
      this->shape = shape;
      this->caught = false;
    }

    Shape* shape;

    glm::vec2 pos;
    glm::vec2 dx;
    glm::vec2 dv;

    float radius;
    bool caught;

};

struct Paddle
{

    Paddle()
    {
    }
    Paddle(const glm::vec2& pos, Shape* shape, float speed) :
        pos(pos), speed(speed)
    {
      this->shape = shape;
    }

    glm::vec2 pos;
    float speed;
    Shape* shape;
};

struct Brick
{

    Brick()
    {
    }
    Brick(const glm::vec2& pos, Shape* shape, AABB box) :
        pos(pos), box(box)
    {
      this->shape = shape;
    }

    glm::vec2 pos;
    AABB box;
    Shape* shape;

};

*/
// paddle controls
enum Keys
{
  LEFT = 0, RIGHT, MAX_CONTROLS
};

namespace
{

// constants
const glm::vec4 BALL_COLOR(0.75f, 0.25f, 0.0f, 1.0f);
const glm::vec4 BRICK_COLOR(0.0f, 0.75f, 0.5f, 1.0f);
const glm::vec4 PADDLE_COLOR(0.5f, 0.5f, 0.75f, 1.0f);

const int WORLD_WIDTH = 10;
const int WORLD_HEIGHT = 10;

const float BALL_RADIUS = 0.125f;
const float PADDLE_SPEED = 15.0f;

// world entities
/*
std::vector<Shape> __shapes;
Ball* __ball;
Paddle* __paddle;
World __world(glm::vec2(WORLD_WIDTH, WORLD_HEIGHT));
std::vector<Brick> __bricks;
*/
int mousedx;

bool mouse1down;
bool mouse2down;

bool __controls[MAX_CONTROLS];
}

/*
Polygon create_rect(float x_size, float y_size)
{
  glm::vec2* points = new glm::vec2[4];
  points[0] = glm::vec2(-1.0f * x_size, -1.0f * y_size);
  points[1] = glm::vec2(1.0f * x_size, -1.0f * y_size);
  points[2] = glm::vec2(1.0f * x_size, 1.0f * y_size);
  points[3] = glm::vec2(-1.0f * x_size, 1.0f * y_size);
  return Polygon(points, 4);
}

Polygon create_circle(float radius, int segments)
{
  glm::vec2* points = new glm::vec2[segments];
  float angle = 0;
  float step = (M_PI * 2) / segments;
  for (int i = 0; i < segments; ++i)
  {
    points[i] = glm::vec2(cosf(angle) * radius, sinf(angle) * radius);
    angle += step;
  }
  return Polygon(points, segments);
}
*/
// ===============================================
// collisions/physics functions
// ===============================================

void integrate(glm::vec2& pos, glm::vec2& dx, glm::vec2& dv, float dt)
{
  pos += dx * dt;
  dx += dv * dt;
}

//bool circle_AABB_intersect(const glm::vec2& circlepos, float radius,
//    const glm::vec2& boxpos, const AABB& box)
//{
//  float d = 0;
//
//  float xmin = boxpos.x - box.xsize;
//  float xmax = boxpos.x + box.xsize;
//
//  float ymin = boxpos.y - box.ysize;
//  float ymax = boxpos.y + box.ysize;
//
//  if (circlepos.x < xmin)
//  {
//    d += pow((circlepos.x - xmin), 2.0f);
//  } else if (circlepos.x > xmax)
//  {
//    d += pow((circlepos.x - xmax), 2.0f);
//  }
//  if (circlepos.y < ymin)
//  {
//    d += pow((circlepos.y - ymin), 2.0f);
//  } else if (circlepos.y > ymax)
//  {
//    d += pow((circlepos.y - ymax), 2.0f);
//  }
//  if (d < pow(radius, 2.0f))
//  {
//    return true;
//  }
//  return false;
//}
//
//void collision_wall(Ball& ball, const World& world)
//{
//
//  if (ball.pos.x)
//
//    if (ball.pos.x < 0.0f + ball.radius)
//    {
//      ball.pos.x -= 2.0f * (ball.pos.x - ball.radius);
//      ball.dx = glm::reflect(ball.dx, glm::vec2(1.0f, 0.0f));
//    }
//  if (ball.pos.x > world.bounds.x - ball.radius)
//  {
//    ball.pos.x -= 2.0f * (ball.pos.x - world.bounds.x + ball.radius);
//    ball.dx = glm::reflect(ball.dx, glm::vec2(-1.0f, 0.0f));
//  }
//  if (ball.pos.y >= world.bounds.y - ball.radius)
//  {
//    ball.pos.y -= 2.0f * (ball.pos.y - world.bounds.y + ball.radius);
//    ball.dx = glm::reflect(ball.dx, glm::vec2(0.0f, -1.0f));
//  }
//  if (ball.pos.y < 0.0f + ball.radius)
//  {
//    ball.pos.y -= 2.0f * (ball.pos.y - ball.radius);
//    ball.dx = glm::reflect(ball.dx, glm::vec2(0.0f, 1.0f));
//  }
//}
//
//void collision_reaction(Ball& ball, Brick& brick)
//{
//
//}
//
//void collision_bruteForce(const std::vector<Brick>& bricks, Ball& ball,
//    World& world, float dt)
//{
//  for (std::vector<Brick>::const_iterator i = bricks.begin(); i != bricks.end();
//      ++i)
//  {
//    Brick brick = *i;
//    if (circle_AABB_intersect(ball.pos, ball.radius, brick.pos, brick.box))
//    {
//      // go back in time
//      integrate(ball.pos, ball.dx, ball.dv, -dt);
//      collision_reaction(ball, brick);
//      // move ball again
//      integrate(ball.pos, ball.dx, ball.dv, dt);
//      // check wall collisions
//      collision_wall(ball, world);
//    }
//  }
//}

// ===============================================
// helper init functions
// ===============================================

bool init_world(void)
{

  return true;
}

// ===============================================
// render functions
// ===============================================

void render_shape(void)
{

}

// ===============================================
// callbacks
// ===============================================

bool init(void)
{
  init_world();
  return true;
}

void render(float alpha)
{

}

void update(float t, float dt)
{
//  integrate(__ball->pos, __ball->dx, __ball->dv, dt);
//  collision_wall(*__ball, __world);
//
//  float xpos = (static_cast<float>(mousedx) / (768.0f)) * (__world.bounds.x);
//  __paddle->pos.x = xpos;
//
//  if (__paddle->pos.x < 0.0f)
//  {
//    __paddle->pos.x = 0.0f;
//  }
//  if (__paddle->pos.x > __world.bounds.x)
//  {
//    __paddle->pos.x = __world.bounds.x;
//  }
//  float paddle_xsize = 1.0f;
//  if (__ball->pos.x > __paddle->pos.x - paddle_xsize * 0.5f
//      && __ball->pos.x < __paddle->pos.x + paddle_xsize * 0.5f
//      && __ball->pos.y < __paddle->pos.y + __ball->radius
//      && __ball->pos.y > __paddle->pos.y)
//  {
//    __ball->pos.y += 2.0f * (__paddle->pos.y + __ball->radius - __ball->pos.y);
//
//    glm::vec2 norm = glm::normalize(glm::vec2(0.0f, 1.0f));
//    __ball->dx = glm::reflect(__ball->dx, norm);
//  }
//  collision_bruteForce(__bricks, *__ball, __world, dt);
}

void cleanup(void)
{

}

void resize(int width, int height)
{

}

void key_press(SDL_Keycode code, bool state)
{
  switch (code)
  {
    case SDLK_LEFT:
      __controls[LEFT] = state;
      break;
    case SDLK_RIGHT:
      __controls[RIGHT] = state;
      break;
    case SDLK_ESCAPE:
      quit();
      break;
  }
}

void mouse_button(Uint8 button, bool state)
{
  if (button == SDL_BUTTON_LEFT)
  {
    mouse1down = state;
  } else if (button == SDL_BUTTON_RIGHT)
  {
    mouse2down = state;
  }
}

void window_event(SDL_Event* event)
{
  switch (event->type)
  {
    case SDL_KEYUP:
      key_press(event->key.keysym.sym, false);
      break;
    case SDL_KEYDOWN:
      key_press(event->key.keysym.sym, true);
      break;
    case SDL_MOUSEMOTION:
      mousedx = event->motion.x;
      break;
    case SDL_MOUSEBUTTONDOWN:
      mouse_button(event->button.button, true);
      break;
    case SDL_MOUSEBUTTONUP:
      mouse_button(event->button.button, false);
      break;

  }
}
