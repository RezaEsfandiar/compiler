#include "../include/parser.h"
#include <iostream>

void predictiveParser(const std::vector<Token>& tokens) {
    std::cout << "Parsing the tokens..." << std::endl;
    for (const auto& token : tokens) {
        std::cout << "Processing token: " << token.value << std::endl;
    }
}
