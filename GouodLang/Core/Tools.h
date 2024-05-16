#include <iostream>
#include <stdlib.h>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include "TokenType.h"

/*
    NUMBER,
	IDENTIFIER,
	LEFTPARAN,
	RIGHTPARAN,
	LEFTBRACK,
	RIGHTBRACK,
	ASSIGN,
	PLUS,
	MINUS,
	MULTIPLY,
	DIVIDE,
	FUNCTION,
	COMMA,
	SEMICOLON,
	WHILE,
	RETURN,
	GREATER,
	SMALLER,
	IF
 */

class Tools {
public:
    static std::string createStringFromTokens(std::vector<std::pair<TokenType, std::string>> tokens) {
        std::string out = "";
        for(auto const t : tokens) {
            out += t.second + " ";
        }
        return out;
    }
    static std::string getStringFromTokenType(TokenType t) {
        switch(t) {
            case TokenType::NUMBER:
                return "NUMBER";

            case TokenType::LEFTPARAN:
                return "LEFTPARAN";

            case TokenType::RIGHTPARAN:
                return "RIGHTPARAN";

            case TokenType::LEFTBRACK:
                return "LEFTBRACK";

            case TokenType::RIGHTBRACK:
                return "RIGHTBRACK";

            case TokenType::ASSIGN:
                return "ASSIGN";

            case TokenType::PLUS:
                return "PLUS";

            case TokenType::MINUS:
                return "MINUS";

            case TokenType::MULTIPLY:
                return "MULTIPLY";

            case TokenType::DIVIDE:
                return "DIVIDE";

            case TokenType::FUNCTION:
                return "FUNCTION";

            case TokenType::COMMA:
                return "COMMA";

            case TokenType::SEMICOLON:
                return "SEMICOLON";

            case TokenType::WHILE:
                return "WHILE";

            case TokenType::RETURN:
                return "RETURN";

            case TokenType::GREATER:
                return "GREATER";

            case TokenType::SMALLER:
                return "SMALLER";

            case TokenType::IF:
                return "IF";

            default:
                return "UNKNOWN";
        }
    }
};
