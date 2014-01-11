#include <iostream>
#include <fstream>
#include <sstream>

#include <vector>
#include <map>
#include <iterator>

#include "SDLBase.h"

#include "ShaderProgram.h"
#include "Shader.h"
#include "Tokenizer.h"
#include "VertexArray.h"

static VertexArray terrain;
static ShaderProgram program;

static glm::mat4 proj;

/******************************************************************************
 *
 *	Misc Functions
 *
 ******************************************************************************/
const std::string getShaderSource(const char* filename)
{
  std::ifstream in(filename, std::ios::in);
  if (!in.is_open())
  {
    std::cout << "Could not read " << filename << " ." << std::endl;
  }

  std::string content;
  std::string line;
  while (!in.eof())
  {
    std::getline(in, line);
    content.append(line + "\n");
  }

  return content;
}

VertexArray loadOBJModelFromFile(const char* filename)
{
  std::ifstream file(filename);
  std::string line;

  std::vector<vec3_t> vertices;
  std::vector<vec3_t> normals;
  std::vector<GLushort> indices;

  while (std::getline(file, line))
  {
    Tokenizer tok(line);
    std::vector<std::string> tokens = tok.tokenize(' ');
    if (tokens.size() == 4)
    {
      std::string indentifer = tokens[0];
      if (indentifer == "v")
      {
        float x = std::strtof(tokens[1].c_str(), NULL);
        float y = std::strtof(tokens[2].c_str(), NULL);
        float z = std::strtof(tokens[3].c_str(), NULL);

        vertices.push_back(vec3_t(x, y, z));

      } else if (indentifer == "vn")
      {

        float x = std::strtof(tokens[1].c_str(), NULL);
        float y = std::strtof(tokens[2].c_str(), NULL);
        float z = std::strtof(tokens[3].c_str(), NULL);

        normals.push_back(vec3_t(x, y, z));

      } else if (indentifer == "f")
      {
        for (int i = 0; i < 4; i++)
        {
          Tokenizer facesplit(tokens[i]);
          std::vector<std::string> face = facesplit.tokenize('/');
          if (face.size() == 3)
          {
            GLushort indice = static_cast<GLushort>(std::strtoul(
                face[0].c_str(), NULL, 0)) - 1;
            indices.push_back(indice);
          }
        }
      }
    }
  }

  std::vector<Vertex3_3_2> vertex_list(vertices.size());

  std::vector<vec3_t>::iterator v;
  std::vector<Vertex3_3_2>::iterator v1;

  for (v = vertices.begin(), v1 = vertex_list.begin(); v < vertices.end();
      v++, v1++)
  {
    v1->position = *v;
  }

  return VertexArray(GL_TRIANGLES,
      reinterpret_cast<GLvoid*>(vertex_list.data()), vertex_list.size(),
      indices.data(), indices.size());
}

/******************************************************************************
 *
 *	Init Functions
 *
 ******************************************************************************/
bool compileShader(Shader* shader, const std::string& source)
{

  shader->loadSource(source.c_str());

  if (!shader->compile())
  {
    std::cout << "=======================================" << std::endl;
    std::cout << "Shader compile error: (" << shader->getID() << ")"
        << std::endl;
    std::cout << shader->getCompileLog() << std::endl;
    std::cout << "=======================================" << std::endl;
    return false;
  }

  return true;
}

void initShaders()
{
  std::vector<Shader> shaders;

  Shader v_shader(GL_VERTEX_SHADER);
  Shader f_shader(GL_FRAGMENT_SHADER);

  std::string v_shader_source = getShaderSource("shaders/shader.vert");
  std::string f_shader_source = getShaderSource("shaders/shader.frag");

  compileShader(&v_shader, v_shader_source);
  compileShader(&f_shader, f_shader_source);

  shaders.push_back(v_shader);
  shaders.push_back(f_shader);

  if (!program.link(shaders))
  {
    std::cout << "=======================================" << std::endl;
    std::cout << "Program compile error: " << std::endl;
    std::cout << program.getLinkLog() << std::endl;
    std::cout << "=======================================" << std::endl;
  }

}
/******************************************************************************
 *
 *	Callbacks
 *
 ******************************************************************************/
void init()
{
  initShaders();

  terrain = loadOBJModelFromFile("models/terrain.obj");

  glEnable(GL_DEPTH_TEST);
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glUseProgram(program.getID());

  glm::mat4 view_mat;
  glm::mat4 model_mat;

  view_mat = glm::translate(view_mat, glm::vec3(0.0f, -50.0f, -100.0f));
  view_mat = glm::rotate(view_mat, 45.0f, glm::vec3(1.0f, 0.0f, 0.0f));

  GLuint loc = program.getUniformLocation("mvp_mat");

  program.uniformMatrix4f(loc, proj * view_mat * model_mat);

  glBindVertexArray(terrain.getID());

  glDrawElements(terrain.getPrimitive(), terrain.getIndexCount(),
  GL_UNSIGNED_SHORT, 0);

  glBindVertexArray(0);

  glUseProgram(0);
}

void resize(int width, int height)
{
  glViewport(0, 0, width, height);

  proj = glm::perspective(75.0f, (float) width / height, 0.01f, 2000.0f);

}

void update(int frame_time)
{
  //float dt = frame_time * 0.001f;

}

void cleanup()
{

}

void keyDown(SDL_Keycode key)
{
  switch (key)
  {
    default:
      break;
  }
}

void keyUp(SDL_Keycode key)
{
  switch (key)
  {
    default:
      break;
  }
}

void event(SDL_Event *event)
{
  switch (event->type)
  {
    case SDL_KEYDOWN:
      keyDown(event->key.keysym.sym);
      break;
    case SDL_KEYUP:
      keyUp(event->key.keysym.sym);
      break;
    default:
      break;
  }
}
