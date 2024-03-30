#include "Lexer.h"


std::vector<std::string> splitString(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);

    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}

Lexer::Lexer() {
    std::cout << "==================" << std::endl << "Lexer Initialized...";
}

void Lexer::printTokens(std::vector<std::pair<TokenType, std::string>> tokens) {
    for (std::pair<TokenType, std::string> token : tokens) {
        if (token.first == TokenType::IDENTIFIER) {
            std::cout << "Identifier(" << token.second << ")" << std::endl;
        }
        else if (token.first == TokenType::LEFTPARAN) {
            std::cout << "LeftParanthesis" << std::endl;
        }
        else if (token.first == TokenType::RIGHTPARAN) {
            std::cout << "RightParanthesis" << std::endl;
        }
        else if(token.first == TokenType::FUNCTION) {
            std::cout << "Function" << std::endl;
        }
        else if(token.first == TokenType::NUMBER) {
            std::cout << "Number(" << token.second << ")" << std::endl;
        }
        else if(token.first == TokenType::ASSIGN) {
            std::cout << "Assign" << std::endl;
        }
        else if(token.first == TokenType::PLUS) {
            std::cout << "Plus" << std::endl;
        }
        else if(token.first == TokenType::MINUS) {
            std::cout << "Minus" << std::endl;
        }
        else if(token.first == TokenType::MULTIPLY) {
            std::cout << "Multiply" << std::endl;
        }
        else if(token.first == TokenType::DIVIDE) {
            std::cout << "Divide" << std::endl;
        }
        else if(token.first == TokenType::COMMA) {
            std::cout << "Comma" << std::endl;
        }
        else if(token.first == TokenType::LEFTBRACK) {
            std::cout << "LeftBrack" << std::endl;
        }
        else if(token.first == TokenType::RIGHTBRACK) {
            std::cout << "RightBrack" << std::endl;
        }
        else if(token.first == TokenType::SEMICOLON) {
            std::cout << "Semicolon" << std::endl;
        }        
        else if(token.first == TokenType::RETURN) {
            std::cout << "Return" << std::endl;
        }
        else {
            std::cout << "Unknown Token" << std::endl;
        }
    }
}

std::vector<std::pair<TokenType, std::string>> Lexer::tokenize(std::string input) {
    std::vector<std::pair<TokenType, std::string>> out;
    std::vector<std::string> tokenStrings = splitString(input, ' ');
    for (std::string tokenString : tokenStrings) {
        for (int i = 0; i < tokenString.length(); i++) {
            if (isalpha(tokenString[i])) {
                std::string tokenValue = "";
                while (i < tokenString.length()) {
                    if (isalpha(tokenString[i]) || tokenString[i] == '_' || isdigit(tokenString[i])) {
                        tokenValue += tokenString[i];
                        i++;
                    }
                    else {
                        break;
                    }
                }
                out.push_back(std::pair(TokenType::IDENTIFIER, tokenValue));
            }
            if (isdigit(tokenString[i])) {
                std::string tokenValue = "";
                while (i < tokenString.length()) {
                    if (isdigit(tokenString[i])) {
                        tokenValue += tokenString[i];
                        i++;
                    }
                    else {
                        break;
                    }
                }
                out.push_back(std::pair(TokenType::NUMBER, tokenValue));
            }
            if (tokenString[i] == '(') {
                out.push_back(std::pair(TokenType::LEFTPARAN, "LEFTPARAN"));
            }
            if (tokenString[i] == ')') {
                out.push_back(std::pair(TokenType::RIGHTPARAN, "RIGHTPARAN"));
            }
            if (tokenString[i] == ',') {
                out.push_back(std::pair(TokenType::COMMA, "COMMA"));
            }
            if (tokenString[i] == '=') {
                out.push_back(std::pair(TokenType::ASSIGN, "ASSIGN"));
            }
            if (tokenString[i] == '+') {
                out.push_back(std::pair(TokenType::PLUS, "PLUS"));
            }
            if (tokenString[i] == '-') {
                out.push_back(std::pair(TokenType::MINUS, "MINUS"));
            }
            if (tokenString[i] == '*') {
                out.push_back(std::pair(TokenType::MULTIPLY, "MULTIPLY"));
            }
            if (tokenString[i] == '/') {
                out.push_back(std::pair(TokenType::DIVIDE, "DIVIDE"));
            }
            if (tokenString[i] == '{') {
                out.push_back(std::pair(TokenType::LEFTBRACK, "LEFTBRACK"));
            }
            if (tokenString[i] == '}') {
                out.push_back(std::pair(TokenType::RIGHTBRACK, "RIGHTBRACK"));
            }
            if(tokenString[i] == ';') {
                out.push_back(std::pair(TokenType::SEMICOLON, "SEMICOLON"));
            }
        }
    }

    tokenizeKeywords(out);
    return out;
}

void Lexer::tokenizeKeywords(std::vector<std::pair<TokenType, std::string>> &tokens) {
    for (int i = 0; i < tokens.size(); i++) {
        if (tokens[i].first == TokenType::IDENTIFIER) {
            if (tokens[i].second == "function") {
                tokens[i].first = TokenType::FUNCTION;
                tokens[i].second = "FUNCTION";
            }
        }
        else if(tokens[i].first == TokenType::IDENTIFIER) {
            if(tokens[i].second == "return") {
                tokens[i].first = TokenType::RETURN;
                tokens[i].second = "RETURN";
            }
        }
    }
}