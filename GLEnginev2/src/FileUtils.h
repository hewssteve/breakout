#ifndef _FILEUTILS_H_
#define _FILEUTILS_H_

#include <string>

std::string getShaderSource(const std::string& filename);

MeshComponent loadOBJModelFromFile(const std::string& filename);



#endif
