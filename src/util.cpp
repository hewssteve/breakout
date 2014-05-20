#include "breakout/util.h"

#include <fstream>
// TODO manage errors more meaningfully
std::string string_from_file(const std::string& filename)
{
  std::ifstream in(filename.c_str(), std::ios::in);
  if (!in.is_open())
  {
    fprintf(stderr, "unable to open '%s'\n", filename.c_str());
    return "";
  }
  std::string contents;
  in.seekg(0, std::ios::end);
  int length = in.tellg();
  contents.resize(length);
  in.seekg(0, std::ios::beg);
  in.read(&contents[0], contents.size());
  return contents;
}
