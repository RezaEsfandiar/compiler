#ifndef PARSE_TREE_H
#define PARSE_TREE_H

#include <string>
#include <vector>
#include "token.h"

struct ParseTreeNode {
    std::string value;
    std::vector<ParseTreeNode*> children;

    ParseTreeNode(const std::string& val) : value(val) {}
};

ParseTreeNode* buildParseTree(const std::vector<Token>& tokens);
void printParseTree(ParseTreeNode* root, int depth = 0);

#endif // PARSE_TREE_H
