
#include "sdlbase.h"
#include "util.h"

#include "gl/buffer.h"
#include "gl/shader.h"
#include "gl/pipeline.h"

struct VertexArray {

    VertexArray() {}
    GLuint id;
    gl::Buffer* vertbuf;
    gl::Buffer* elembuf;

};

struct World {

    World(){}
    World(const glm::vec2 bounds)
    : bounds(bounds) {}

    glm::vec2 bounds;

};

struct Shape {

    Shape() {}
    Shape(GLint offset, GLsizei vert_count)
    : offset(offset), vert_count(vert_count) {}
    
    GLint offset;
    GLsizei vert_count;

};

struct Ball {

    Ball() {}
    Ball(const glm::vec2& pos, float radius, Shape* shape)
    : pos(pos), radius(radius) {
      this->shape = shape;
    }

    Shape* shape;

    glm::vec2 pos;
    glm::vec2 dx;
    glm::vec2 dv;

    float radius;
};

struct Paddle {

    Paddle() {}
    Paddle(const glm::vec2& pos, Shape* shape, float speed)
    : pos(pos), speed(speed) {
      this->shape = shape;
    }

    glm::vec2 pos;
    float speed;
    Shape* shape;
};

struct Brick {

    Brick() {}
    Brick(const glm::vec2& pos, Shape* shape)
    : pos(pos) {
      this->shape = shape;
    }

    glm::vec2 pos;
    Shape* shape;

};

// constants
static const glm::vec4 BALL_COLOR   (0.75f,0.25f, 0.0f ,1.0f);
static const glm::vec4 BRICK_COLOR  (0.0f ,0.75f, 0.5f ,1.0f);
static const glm::vec4 PADDLE_COLOR (0.5f ,0.5f , 0.75f,1.0f);

static const int NUM_SHAPES = 4;
static Shape __shapes[NUM_SHAPES];

static const int WORLD_WIDTH = 10;
static const int WORLD_HEIGHT = 10;

static const float BALL_RADIUS = 0.125f;
static const float PADDLE_SPEED = 5.0f;

static Ball* __ball;
static Paddle* __paddle;
static World __world(glm::vec2(WORLD_WIDTH, WORLD_HEIGHT));
static std::vector<Brick> __bricks;

static int mousedx;

// paddle controls
enum Keys {
  LEFT = 0,
  RIGHT,
  MAX_CONTROLS
};

static bool __controls[MAX_CONTROLS];

static VertexArray __vao;

static gl::Shader*    __vert_shader;
static gl::Shader*    __frag_shader;
static gl::Pipeline*  __pipeline;

static glm::mat4 __proj_mat;
static GLint __proj_mat_uniform;
static GLint __mat_color_uniform;
static GLint __mat_intensity_uniform;


void sphere_AABB_intersect() {




}

void create_rect(float x_size, float y_size) {



}


// ===============================================
// helper init functions
// ===============================================

bool init_shaders(void) {

  std::string vertsource = string_from_file("shaders/shader.vert");
  std::string fragsource = string_from_file("shaders/shader.frag");

  __vert_shader = new gl::Shader(GL_VERTEX_SHADER, vertsource);
  __frag_shader = new gl::Shader(GL_FRAGMENT_SHADER, fragsource);

  if (!__vert_shader->link_flag()) {
    std::cout << "Shader compile error: ";
    std::cout << __vert_shader->link_log() << std::endl;
  }

  if (!__frag_shader->link_flag()) {
    std::cout << "Shader compile error: ";
    std::cout << __frag_shader->link_log() << std::endl;
  }

  __pipeline = new gl::Pipeline();
  __pipeline->useProgramStage(GL_VERTEX_SHADER_BIT, __vert_shader->id());
  __pipeline->useProgramStage(GL_FRAGMENT_SHADER_BIT, __frag_shader->id());
  // bind uniforms
  __proj_mat_uniform = __vert_shader->getUniformLocation("mvp_mat");
  __mat_color_uniform = __frag_shader->getUniformLocation("mat_color");
  __mat_intensity_uniform = __frag_shader->getUniformLocation("mat_intensity");
  // init uniforms
  __frag_shader->uniform1f(__mat_intensity_uniform, 1.0f);

  return true;
}

bool init_world(void) {
  // sphere
  const int num_verts = 16;
  vertex sphere[num_verts];
  float angle = 0;
  float step = (M_PI * 2) / num_verts;
  for (int i = 0; i < num_verts; ++i) {
    sphere[i].position = glm::vec2(cosf(angle) * BALL_RADIUS, sinf(angle) * BALL_RADIUS);
    angle += step;
  }

  // square ( for bricks )
  vertex rect[4];
  float rect_x_size = 0.25f;
  float rect_y_size = 0.25f;
  rect[0] = glm::vec2(-1.0f * rect_x_size, -1.0f * rect_y_size);
  rect[1] = glm::vec2(1.0f * rect_x_size, -1.0f * rect_y_size);
  rect[2] = glm::vec2(1.0f * rect_x_size, 1.0f * rect_y_size);
  rect[3] = glm::vec2(-1.0f * rect_x_size, 1.0f * rect_y_size);

  // triangle
  //  vertex triangle[3];

  // create shapes
  __shapes[0] = Shape(0, num_verts);
  __shapes[1] = Shape(num_verts, 4);
  
  Shape* brick_shape = &__shapes[1];
  Shape* ball_shape = &__shapes[0];
  
  // create entities
  __ball = new Ball(glm::vec2(0.0f, 5.0f), BALL_RADIUS, ball_shape);
  __ball->dx = glm::vec2(1.0f, 2.0f);
  //__ball->dv = glm::vec2(0.5f, 0.5f);

  __paddle = new Paddle(glm::vec2(__world.bounds.x * 0.5f, 1.0f), brick_shape, PADDLE_SPEED);

  __bricks.push_back(Brick(glm::vec2(9.0f, 5.0f), brick_shape));
  __bricks.push_back(Brick(glm::vec2(8.0f, 5.0f), brick_shape));
  __bricks.push_back(Brick(glm::vec2(7.0f, 5.0f), brick_shape));
  __bricks.push_back(Brick(glm::vec2(6.0f, 5.0f), brick_shape));
  __bricks.push_back(Brick(glm::vec2(5.0f, 5.0f), brick_shape));
  __bricks.push_back(Brick(glm::vec2(4.0f, 5.0f), brick_shape));
  __bricks.push_back(Brick(glm::vec2(3.0f, 5.0f), brick_shape));
  __bricks.push_back(Brick(glm::vec2(2.0f, 5.0f), brick_shape));
  __bricks.push_back(Brick(glm::vec2(1.0f, 5.0f), brick_shape));

  // vertex array creation
  size_t bufsize = sizeof(sphere) + sizeof(rect);
  __vao.vertbuf = new gl::Buffer(GL_ARRAY_BUFFER, bufsize, GL_STATIC_DRAW);
  __vao.vertbuf->bufferData(reinterpret_cast<const GLvoid*>(&sphere), 0, sizeof(sphere));
  __vao.vertbuf->bufferData(reinterpret_cast<const GLvoid*>(&rect), sizeof(sphere), sizeof(rect));

  glGenVertexArrays(1, &__vao.id);
  GL_CHECK_ERROR;
  glBindVertexArray(__vao.id);
  glBindBuffer(GL_ARRAY_BUFFER, __vao.vertbuf->id());
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(vertex), 0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);
  GL_CHECK_ERROR;
  return true;
}

// ===============================================
// render functions
// ===============================================

void render_shape(const Shape& shape, const glm::vec2& pos, const glm::vec4 & color) {
  glm::mat4 model_mat;
  __vert_shader->uniformMatrix4f(__proj_mat_uniform, __proj_mat *
                                 glm::translate(model_mat, glm::vec3(pos, 0.0f)));
  __frag_shader->uniform4f(__mat_color_uniform, color);
  glDrawArrays(GL_LINE_LOOP, shape.offset, shape.vert_count);
}

// ===============================================
// callbacks
// ===============================================

bool init(void) {
  init_shaders();
  init_world();
  return true;
}

void render(float alpha) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glBindProgramPipeline(__pipeline->id());
  glBindVertexArray(__vao.id);

  for (std::vector<Brick>::iterator i = __bricks.begin(); i != __bricks.end(); ++i) {
    Brick b = *i;
    render_shape(*b.shape, b.pos, BRICK_COLOR);
  }
  render_shape(*__ball->shape, __ball->pos, BALL_COLOR);
  render_shape(*__paddle->shape, __paddle->pos - glm::vec2(0.0f, 0.25f), PADDLE_COLOR);

  glBindVertexArray(0);
  glBindProgramPipeline(0);
  GL_CHECK_ERROR;
}

void update(float t, float dt) {

  if(__ball->pos.x < 0.0f + __ball->radius) {
    __ball->pos.x -= 2.0f * (__ball->pos.x - __ball->radius);
    __ball->dx = glm::reflect(__ball->dx, glm::vec2(1.0f, 0.0f));
   //__ball->dv = glm::reflect(__ball->dv, glm::vec2(1.0f, 0.0f));
  }

  if(__ball->pos.x > __world.bounds.x - __ball->radius) {
    __ball->pos.x -= 2.0f * (__ball->pos.x - __world.bounds.x + __ball->radius);
    __ball->dx = glm::reflect(__ball->dx, glm::vec2(-1.0f, 0.0f));
   // __ball->dv = glm::reflect(__ball->dv, glm::vec2(-1.0f, 0.0f));
  }

  if (__ball->pos.y >= __world.bounds.y - __ball->radius ) {
    __ball->pos.y -= 2.0f * (__ball->pos.y - __world.bounds.y + __ball->radius);
    __ball->dx = glm::reflect(__ball->dx, glm::vec2(0.0f, -1.0f));
//    __ball->dv = glm::reflect(__ball->dv, glm::vec2(0.0f, -1.0f));
  }

  if (__ball->pos.y < 0.0f + __ball->radius) {
    __ball->pos.y -= 2.0f * (__ball->pos.y - __ball->radius);
    __ball->dx = glm::reflect(__ball->dx, glm::vec2(0.0f, 1.0f));
    //__ball->dv = glm::reflect(__ball->dv, glm::vec2(0.0f, 1.0f));
  }

  __ball->pos += __ball->dx * dt;
  //__ball->dx += __ball->dv * dt;
  /*
  float paddle_vel;
  if (__controls[LEFT]) {
    paddle_vel = -__paddle->speed;
  } else if (__controls[RIGHT]) {
    paddle_vel = __paddle->speed;
  } else {
    paddle_vel = 0.0f;
  }
  __paddle->pos.x += paddle_vel * dt;
  */
  float xpos = (static_cast<float>(mousedx) / (768.0f)) * (__world.bounds.x);
  __paddle->pos.x = xpos;
  //mousedx = 0;
  
  if (__paddle->pos.x < 0.0f) {
    __paddle->pos.x = 0.0f;
  }
  if (__paddle->pos.x > __world.bounds.x) {
    __paddle->pos.x = __world.bounds.x;
  }

  if (__ball->pos.x > __paddle->pos.x - 0.5f * 0.5f && __ball->pos.x < __paddle->pos.x + 0.5f * 0.5f
      && __ball->pos.y < __paddle->pos.y + __ball->radius && __ball->pos.y > __paddle->pos.y) {
    __ball->pos.y += 2.0f * (__paddle->pos.y + __ball->radius - __ball->pos.y);
    glm::vec2 norm = glm::normalize(glm::vec2(0.0f, 1.0f));
    __ball->dx = glm::reflect(__ball->dx, norm);
  }

}

void cleanup(void) {

  delete __vert_shader;
  delete __frag_shader;
  delete __pipeline;

  GL_CHECK_ERROR;
}

void resize(int width, int height) {
  glViewport(0, 0, width, height);
  std::cout << "w,h : " << width << "," << height << std::endl;
  __proj_mat = glm::ortho(0.0f, __world.bounds.x, 0.0f, __world.bounds.y, -1.0f, 1.0f);
  GL_CHECK_ERROR;
}
/*
void key_up(SDL_Keycode code) {

  switch(code) {
    case SDLK_LEFT:
      __controls[LEFT] = false;
      break;
    case SDLK_RIGHT:
      __controls[RIGHT] = false;
      break;
  }

}

void key_down(SDL_Keycode code) {

  switch(code) {
    case SDLK_LEFT:
      __controls[LEFT] = true;
      break;
    case SDLK_RIGHT:
      __controls[RIGHT] = true;
      break;
  }

}
*/
void key_press(SDL_Keycode code, bool state) {

  switch(code) {
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

void window_event(SDL_Event* event) {

  switch(event->type) {
    case SDL_KEYUP:
      key_press(event->key.keysym.sym, false);
      break;
    case SDL_KEYDOWN:
      key_press(event->key.keysym.sym, true);
      break;
    case SDL_MOUSEMOTION:
      mousedx = event->motion.x;
      break;
      
  }

}
