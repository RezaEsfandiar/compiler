#ifndef LEXICAL_ANALYZER_H
#define LEXICAL_ANALYZER_H

#include <vector>
#include <string>
#include "token.h"

std::vector<Token> lexicalAnalyzer(const std::string& input);
void printTokens(const std::vector<Token>& tokens);
void buildTokenTable(const std::vector<Token>& tokens);
void printTokenTable();

#endif // LEXICAL_ANALYZER_H
