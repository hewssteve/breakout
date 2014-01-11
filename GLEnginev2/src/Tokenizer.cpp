/*
 COSC1254 Programming using C++
 Assignment 3
 Stephen Hewson s3286016
 */

#include "Tokenizer.h"

Tokenizer::Tokenizer()
{

}

Tokenizer::Tokenizer(std::string line)
{
  this->line = line;
}

std::vector<std::string> Tokenizer::tokenize(char delim)
{
  std::vector<std::string> ret_val;

  while (!line.empty())
  {
    size_t found = line.find(delim);
    /* 
     * If the delimeter has been found, add it to the return vector
     * */
    if (found != std::string::npos)
    {

      ret_val.push_back(line.substr(0, found));

      line = line.substr(found + 1);
    } else
    {
      /*
       * Otherwise add the rest of the line to the vector, and 
       * then clear it. This will end the loop and the last element 
       * in the vector will be the remainder of the string
       */
      ret_val.push_back(line);

      line.clear();

    }

  }
  return ret_val;
}
