#ifndef _TOKENIZER_H_
#define _TOKENIZER_H_

#include <string>
#include <vector>

/*
 * Simple tokenizer class 
 */
class Tokenizer
{
  public:
    Tokenizer();
    Tokenizer(std::string line);
    /* return a vector of strings based on a delimeter */
    std::vector<std::string> tokenize(char delim);

  private:
    std::string line;
};

#endif
