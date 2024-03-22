#include "Interpreter.h"


Interpreter::Interpreter() {
    std::cout << "==================" << std::endl << "Interpreter Initialized" << std::endl << "==================" << std::endl;

}

void Interpreter::interpret(std::vector<std::pair<TokenType, std::string>> tokens) {
    for (int i = 0; i < tokens.size(); i++) {
        if (tokens[i].first == TokenType::FUNCTION) {
            if(tokens[i + 1].first != TokenType::IDENTIFIER) {
                std::cout << "Error: Expected identifier after function keyword" << std::endl;
                exit(1);
            }
            std::string functionName = tokens[i + 1].second;
            if(tokens[i + 2].first != TokenType::LEFTPARAN) {
                std::cout << "Error: Expected left paran after function name" << std::endl;
                exit(1);
            }
            //ARGUMENTS
            if(tokens[i + 3].first != TokenType::RIGHTPARAN) {
                std::cout << "Error: Expected right paran after function arguments" << std::endl;
                exit(1);
            }
            if(tokens[i + 4].first != TokenType::LEFTBRACK) {
                std::cout << "Error: Expected left bracket after function arguments" << std::endl;
                exit(1);
            }
            std::vector<std::pair<TokenType, std::string>> functionTokens;
            i += 5;
            while (tokens[i].first != TokenType::RIGHTBRACK) {
                functionTokens.push_back(tokens[i]);
                i++;
            }
            functions[functionName] = functionTokens;
        }
    }
}

void Interpreter::printDebug() {
    for (auto const& x : functions) {
        std::cout << "Function: " << x.first << std::endl;
        for (int i = 0; i < x.second.size(); i++) {
            std::cout << x.second[i].second << std::endl;
        }
    }
}