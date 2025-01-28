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

    try {
        // Step 1: Lexical analysis
        std::vector<Token> tokens;
        try {
            tokens = lexicalAnalyzer(input);
        } catch (const std::runtime_error& e) {
            std::cerr << "Lexical Analysis Error: " << e.what() << std::endl;
            return 1; // Exit with error code
        }

        // Step 2: Print tokens
        printTokens(tokens);

        // Step 3: Build token table
        buildTokenTable(tokens);
        printTokenTable();

        // Step 4: Parsing
        try {
            predictiveParser(tokens);
        } catch (const std::runtime_error& e) {
            std::cerr << "Parsing Error: " << e.what() << std::endl;
            return 1; // Exit with error code
        }

        // Step 5: Build parse tree
        ParseTreeNode* root = nullptr;
        try {
            root = buildParseTree(tokens);
        } catch (const std::runtime_error& e) {
            std::cerr << "Parse Tree Construction Error: " << e.what() << std::endl;
            return 1; // Exit with error code
        }

        // Step 6: Print parse tree
        try {
            printParseTree(root);
        } catch (const std::runtime_error& e) {
            std::cerr << "Parse Tree Printing Error: " << e.what() << std::endl;
            return 1; // Exit with error code
        }

        // Clean up parse tree (if applicable)
        // deleteParseTree(root); // Uncomment if you have a function to free the parse tree memory

    } catch (const std::exception& e) {
        std::cerr << "Unexpected Error: " << e.what() << std::endl;
        return 1; // Exit with error code
    }

    return 0; // Success
}