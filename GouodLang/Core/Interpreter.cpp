#include "Interpreter.h"

Interpreter::Interpreter(std::map<std::string, double> initVariables) {
    //std::cout << std::endl << "Interpreter Initialized..." << std::endl << "==================" << std::endl;
    variables.insert(initVariables.begin(), initVariables.end());
}

double Interpreter::interpret(std::vector<std::pair<TokenType, std::string>> tokens) {
    for (int i = 0; i < tokens.size(); i++) {
        //std::cout << "Current token: " << tokens[i].second << std::endl;
        if(tokens[i].first == TokenType::RETURN) {
            return terminal(tokens, i + 1);
        }
        else if (tokens[i].first == TokenType::FUNCTION) {
            i++;
            std::string functionName = tokens[i].second;
            i += 2;

            //ARGUMENTS
            std::vector<std::string> args;
            while(tokens[i].first != TokenType::RIGHTPARAN) {
                args.push_back(tokens[i].second);
                i += 2;
            }
            i += 2;
            
            std::vector<std::pair<TokenType, std::string>> functionTokens;
            while (tokens[i].first != TokenType::RIGHTBRACK) {
                functionTokens.push_back(tokens[i]);
                i++;
            }
            Function *f = new Function(functionName, functionTokens, args);

            //functions[functionName] = functionTokens;
            newFunctions[functionName] = f;
        }
        else if(tokens[i].first == TokenType::IDENTIFIER) {
            if(tokens[i+1].first != TokenType::ASSIGN) {
                std::vector<std::pair<TokenType, std::string>> expression;
                while(tokens[i].first != TokenType::SEMICOLON) {
                    expression.push_back(tokens[i]);  
                    i++;
                }
                //printTokens(expression);
                std::cout << Tools::createStringFromTokens(expression) << "= " << evaluate(expression) << std::endl;
                index = 0;
            }
            else {
                std::string variableName = tokens[i].second;
                if(tokens[i + 1].first == TokenType::ASSIGN) {
                    i++;
                    std::vector<std::pair<TokenType, std::string>> expression;
                    while(tokens[i+1].first != TokenType::SEMICOLON) {
                        i++;
                        expression.push_back(tokens[i]);
                        
                    }
                    variables[variableName] = evaluate(expression);
                    index = 0;
                }
            }
        }
        else if(tokens[i].first == TokenType::NUMBER) {
            std::vector<std::pair<TokenType, std::string>> expression;
            while(tokens[i].first != TokenType::SEMICOLON) {
                expression.push_back(tokens[i]);  
                i++;
            }
            //printTokens(expression);
            std::cout << Tools::createStringFromTokens(expression) << "= " << evaluate(expression) << std::endl;
            index = 0;
        }
    }
    //std::cerr << "ERROR HIT END OF INTERPRETATION" << std::endl;
    return 0;
}

double Interpreter::evaluate(std::vector<std::pair<TokenType, std::string>> tokens) {
    if(tokens.size() == 1) {
        return terminal(tokens, 0);
    }
    /*for (auto const& x : tokens) {
        std::cout << x.second << std::endl;
    }
    std::cout << "==================" << std::endl;*/
    double out = expression(tokens);
    /*if(tokens[1].first == TokenType::LEFTPARAN) {
        std::cout << "Function called!" << std::endl;
        //callFunction(tokens[0], )
    }
    else {
        out = expression(tokens);
    }*/
    while(index < tokens.size()) {
        if(tokens[index].first == TokenType::PLUS) {
            incIndex();
            double right = expression(tokens);
            out += right;
        }
        else if(tokens[index].first == TokenType::MINUS) {
            incIndex();
            double right = expression(tokens);
            out -= right;
        }
        else if(tokens[index].first == TokenType::RIGHTPARAN) {
            return out;
        }
        else {
            incIndex();
        }
    }
    
    return out;
}

void Interpreter::incIndex() {
    index++;
}

double Interpreter::expression(std::vector<std::pair<TokenType, std::string>> tokens) {
    if(tokens.size() == 1) {
        return terminal(tokens, 0);
    }
    double out = terminal(tokens, index);
    while(index < tokens.size()) {
        incIndex();
        if(tokens[index].first == TokenType::MULTIPLY) {
            incIndex();            
            double right = terminal(tokens, index);
            out *= right;
        }
        else if(tokens[index].first == TokenType::DIVIDE) {
            incIndex();
            double right = terminal(tokens, index);
            out /= right;
        }

        else {
            return out;
        }
    }
    //std::cerr << "ERROR HIT EXPRESSION END" << std::endl;
    //exit(-1);
    return 0;
}

double Interpreter::terminal(std::vector<std::pair<TokenType, std::string>> tokens, int sindex) {
    if(tokens[sindex].first == TokenType::NUMBER) {
        return std::stod(tokens[sindex].second);
    }
    else if(tokens[sindex].first == TokenType::IDENTIFIER) {
        if(tokens[sindex + 1].first == TokenType::LEFTPARAN) {
            //FUNCTION CALL
            incIndex();
            incIndex();
            std::vector<std::tuple<TokenType, std::string>> args;
            while(tokens[index].first != TokenType::RIGHTPARAN) {
                args.push_back(tokens[index]);
                incIndex();
            }
            return callFunction(tokens[sindex].second, args);
        }
        else {  
            return variables[tokens[sindex].second];
        }
    }
    else if(tokens[sindex].first == TokenType::LEFTPARAN) {
        incIndex();
        return evaluate(tokens);
    }
    else {
        std::cout << "Error: Expected number or identifier and got " << tokens[sindex].second << std::endl;
        exit(1);
    
    }
}

void Interpreter::printDebug() {
    for (auto const x : newFunctions) {
        std::cout << "\tFunction: " << x.second->getName() << std::endl;
        for (int i = 0; i < x.second->getTokens().size(); i++) {
            std::cout << "\t\t" << x.second->getTokens()[i].second << std::endl;
        }
    }
    for(auto const& x : variables) {
        std::cout << "\tVariable: " << x.first << "\tValue: " << x.second << std::endl;
    }
}

double Interpreter::callFunction(std::string functionName, std::vector<std::tuple<TokenType, std::string>> args) {
    Function* f = newFunctions[functionName];
    //std::vector<std::pair<TokenType, std::string>> functionTokens = functions[functionName];
    std::vector<std::pair<TokenType, std::string>> functionTokens = f->getTokens();
    std::map<std::string, double> vars;
    Interpreter i(vars);
    //std::cout << "Calling function: " << functionName << std::endl;
    for(int i = 0; i < functionTokens.size(); i++) {
        //std::cout << functionTokens[i].second << std::endl;
        //incIndex();
    }
    //printTokens(functionTokens);
    return i.interpret(functionTokens);
}

void Interpreter::printTokens(std::vector<std::pair<TokenType, std::string>> tokens) {
    std::cout << "Printing tokens: " << std::endl;
    for(auto const& token : tokens) {
        std::cout << token.second << std::endl;
    }
}
