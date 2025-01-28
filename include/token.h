#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum TokenType {
    RESERVED_WORD,
    IDENTIFIER,
    NUMBER,
    SYMBOL,
    STRING
};

struct Token {
    TokenType type;
    std::string value;
};

#endif // TOKEN_H
