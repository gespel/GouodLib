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

}

void Lexer::printTokens(std::vector<std::pair<TokenType, std::string>> tokens) {
    for (std::pair<TokenType, std::string> token : tokens) {
        if (token.first == TokenType::IDENTIFIER) {
            std::cout << "Identifier with Value: " << token.second << std::endl;
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
        else {
            std::cout << "Unknown Token" << std::endl;
        }
    }
}

std::vector<std::pair<TokenType, std::string>> Lexer::tokenize(std::string input) {
    std::vector<std::pair<TokenType, std::string>> out;
    //std::cout << "Tokenizing src: " << input << std::endl;
    std::vector<std::string> inputLines = splitString(input, ';');

    for (std::string line : inputLines) {
        //std::cout << "Tokenizing line: " << line << std::endl;
        std::vector<std::pair<TokenType, std::string>> lineTokens = this->tokenizeLine(line);
        printTokens(lineTokens);
    }

	return out;
}

std::vector<std::pair<TokenType, std::string>> Lexer::tokenizeLine(std::string line) {
    std::vector<std::pair<TokenType, std::string>> out;
    std::vector<std::string> tokenStrings = splitString(line, ' ');
    for (std::string tokenString : tokenStrings) {
        for (int i = 0; i < tokenString.length(); i++) {
            if (isalpha(tokenString[i])) {
                std::string tokenValue = "";
                while (i < tokenString.length()) {
                    if (isalpha(tokenString[i]) || tokenString[i] == '_') {
                        tokenValue += tokenString[i];
                        i++;
                    }
                    else {
                        break;
                    }
                }
                out.push_back(std::pair(TokenType::IDENTIFIER, tokenValue));
            }
            if (tokenString[i] == '(') {
                out.push_back(std::pair(TokenType::LEFTPARAN, "NULL"));
            }
            if (tokenString[i] == ')') {
                out.push_back(std::pair(TokenType::RIGHTPARAN, "NULL"));
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
                tokens[i].second = "NULL";
            }
        }
    }
}