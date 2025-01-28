#include "../include/lexical_analyzer.h"
#include <unordered_map>
#include <iostream>
#include <cctype>
#include <stdexcept>

// Reserved words and symbols
std::unordered_map<std::string, bool> reservedWords = {
    {"int", true}, {"float", true}, {"void", true}, {"return", true},
    {"while", true}, {"cin", true}, {"cout", true}, {"include", true},
    {"using", true}, {"namespace", true}, {"std", true}, {"main", true}
};

std::unordered_map<char, bool> symbols = {
    {'+', true}, {'-', true}, {'*', true}, {'/', true}, {'=', true},
    {'<', true}, {'>', true}, {'(', true}, {')', true}, {'{', true},
    {'}', true}, {';', true}, {',', true}, {'"', true}
};

std::vector<Token> lexicalAnalyzer(const std::string& input) {
    std::vector<Token> tokens;
    std::string buffer;

    for (size_t i = 0; i < input.size(); ++i) {
        char ch = input[i];

        // Handle whitespace
        if (isspace(ch)) {
            if (!buffer.empty()) {
                if (reservedWords.find(buffer) != reservedWords.end()) {
                    tokens.push_back({RESERVED_WORD, buffer});
                } else if (isdigit(buffer[0])) {
                    tokens.push_back({NUMBER, buffer});
                } else if (isalpha(buffer[0]) || buffer[0] == '_') {
                    tokens.push_back({IDENTIFIER, buffer});
                } else {
                    throw std::runtime_error("Invalid identifier: " + buffer);
                }
                buffer.clear();
            }
            continue;
        }

        // Handle symbols
        if (symbols.find(ch) != symbols.end()) {
            if (!buffer.empty()) {
                if (reservedWords.find(buffer) != reservedWords.end()) {
                    tokens.push_back({RESERVED_WORD, buffer});
                } else if (isdigit(buffer[0])) {
                    tokens.push_back({NUMBER, buffer});
                } else if (isalpha(buffer[0]) || buffer[0] == '_') {
                    tokens.push_back({IDENTIFIER, buffer});
                } else {
                    throw std::runtime_error("Invalid identifier: " + buffer);
                }
                buffer.clear();
            }
            tokens.push_back({SYMBOL, std::string(1, ch)});
            continue;
        }

        // Handle strings
        if (ch == '"') {
            if (!buffer.empty()) {
                tokens.push_back({IDENTIFIER, buffer});
                buffer.clear();
            }
            std::string str;
            while (i + 1 < input.size() && input[++i] != '"') {
                str += input[i];
            }
            if (i >= input.size()) {
                throw std::runtime_error("Unterminated string literal");
            }
            tokens.push_back({STRING, str});
            continue;
        }

        // Handle invalid characters
        if (!isalnum(ch) && ch != '_') {
            throw std::runtime_error("Unrecognized character: " + std::string(1, ch));
        }

        buffer += ch;
    }

    // Handle any remaining buffer content
    if (!buffer.empty()) {
        if (reservedWords.find(buffer) != reservedWords.end()) {
            tokens.push_back({RESERVED_WORD, buffer});
        } else if (isdigit(buffer[0])) {
            tokens.push_back({NUMBER, buffer});
        } else if (isalpha(buffer[0]) || buffer[0] == '_') {
            tokens.push_back({IDENTIFIER, buffer});
        } else {
            throw std::runtime_error("Invalid identifier: " + buffer);
        }
    }

    return tokens;
}

void printTokens(const std::vector<Token>& tokens) {
    for (const auto& token : tokens) {
        std::string type;
        switch (token.type) {
            case RESERVED_WORD: type = "RESERVED_WORD"; break;
            case IDENTIFIER: type = "IDENTIFIER"; break;
            case NUMBER: type = "NUMBER"; break;
            case SYMBOL: type = "SYMBOL"; break;
            case STRING: type = "STRING"; break;
        }
        std::cout << "[" << type << ", " << token.value << "]" << std::endl;
    }
}

void buildTokenTable(const std::vector<Token>& tokens) {
    // Define and populate token table logic
}

void printTokenTable() {
    // Print token table logic
}

int main() {
    std::string input = "int main() { return 0; }";
    try {
        std::vector<Token> tokens = lexicalAnalyzer(input);
        printTokens(tokens);
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}