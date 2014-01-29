#include <fstream>

#include "MeshComponent.h"
#include "FileUtils.h"

std::string getShaderSource(const std::string& filename)
{
  std::cout << "Loading shader source \'" << filename << "\'." << std::endl;
  std::ifstream in(filename.c_str(), std::ios::in);
  if (!in.is_open())
  {
    std::cout << "Could not read " << filename << " ." << std::endl;
  }

  std::string content;
  std::string line;
  while (!in.eof())
  {
    std::getline(in, line);
    content.append(line);
  }

  return content;
}

MeshComponent loadOBJModelFromFile(const std::string& filename)
{
  std::cout << "Loading model \'" << filename << "\'." << std::endl;

  std::ifstream file(filename.c_str());
  std::string line;

  std::vector<std::string> vert_lines;
  std::vector<std::string> norm_lines;
  std::vector<std::string> face_lines;

  while (std::getline(file, line))
  {
    Tokenizer tok(line);
    std::vector<std::string> tokens = tok.tokenize(' ');
    if (tokens.size() == 4)
    {
      std::string indentifer = tokens[0];
      if (indentifer == "v")
      {
        vert_lines.push_back(line);
      }
      else if (indentifer == "vn")
      {
        /*
        float x = std::strtof(tokens[1].c_str(), NULL);
        float y = std::strtof(tokens[2].c_str(), NULL);
        float z = std::strtof(tokens[3].c_str(), NULL);
        
        normals.push_back(glm::vec3(x, y, z));
        */
        norm_lines.push_back(line);
      }
      else if (indentifer == "f")
      {
        face_lines.push_back(line);
        /*
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
        */
      }
    }
  }
  std::vector<Vertex4_3_2> vertex_list(vert_lines.size());

  for(std::vector<std::string>::iterator i = vert_lines.begin(); i != vert_lines.end();
      ++i)
  {
    Tokenizer tok(*i);
    std::vector<std::string> tokens = tok.tokenize(' ');

    float x = std::strtof(tokens[1].c_str(), NULL);
    float y = std::strtof(tokens[2].c_str(), NULL);
    float z = std::strtof(tokens[3].c_str(), NULL);

    Vertex4_3_2 vert;
    vert.position = glm::vec4(x, y, z, 1.0f);
    vertex_list.push_back(vert); 
  }
  
  MeshComponent comp;
  
  return comp; 
}
