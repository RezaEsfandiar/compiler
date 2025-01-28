#include <iostream>
#include <string>
#include "../include/lexical_analyzer.h"
#include "../include/parser.h"
#include "../include/parse_tree.h"

int main() {
    std::string input;
    std::string line;

    std::cout << "Enter your code (press Enter on an empty line to finish):" << std::endl;
    while (true) {
        std::getline(std::cin, line);
        if (line.empty()) {
            break;
        }
        input += line + "\n";
    }

    // Step 1: Lexical analysis
    auto tokens = lexicalAnalyzer(input);

    // Step 2: Print tokens
    printTokens(tokens);

    // Step 3: Build token table
    buildTokenTable(tokens);
    printTokenTable();

    // Step 4: Parsing
    predictiveParser(tokens);

    // Step 5: Build parse tree
    auto root = buildParseTree(tokens);

    // Step 6: Print parse tree
    std::cout << 1 << std::endl;
    printParseTree(root);

    return 0;
}
