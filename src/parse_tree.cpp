#include "../include/parse_tree.h"
#include <iostream>

ParseTreeNode* buildParseTree(const std::vector<Token>& tokens) {
    ParseTreeNode* root = new ParseTreeNode("Program");
    for (const auto& token : tokens) {
        root->children.push_back(new ParseTreeNode(token.value));
    }
    return root;
}

void printParseTree(ParseTreeNode* root, int depth) {
    if (!root) return;
    for (int i = 0; i < depth; ++i) std::cout << "  ";
    std::cout << root->value << std::endl;
    for (const auto& child : root->children) {
        printParseTree(child, depth + 1);
    }
}
