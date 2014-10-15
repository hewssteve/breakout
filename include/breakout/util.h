#ifndef BREAKOUT_UTIL_H_
#define BREAKOUT_UTIL_H_

#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <cstdio>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
  TypeName(const TypeName&);               \
  void operator=(const TypeName&)

std::string string_from_file(const std::string& filename);

#endif // BREAKOUT_UTIL_H_
