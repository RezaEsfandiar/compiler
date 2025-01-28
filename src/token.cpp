#include "../include/token.h"
#include <iostream>
#include <unordered_map>
#include <vector>

// Mapping TokenType to readable string for printing
std::unordered_map<TokenType, std::string> tokenTypeToString = {
    {RESERVED_WORD, "RESERVED_WORD"},
    {IDENTIFIER, "IDENTIFIER"},
    {NUMBER, "NUMBER"},
    {SYMBOL, "SYMBOL"},
    {STRING, "STRING"}
};

// Function to print a single token
void printToken(const Token& token) {
    std::cout << "[" << tokenTypeToString[token.type] << ", " << token.value << "]" << std::endl;
}

// Function to print a list of tokens
void printTokens(const std::vector<Token>& tokens) {
    for (const auto& token : tokens) {
        printToken(token);
    }
}
