#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include "token.h"

void predictiveParser(const std::vector<Token>& tokens);

#endif // PARSER_H
