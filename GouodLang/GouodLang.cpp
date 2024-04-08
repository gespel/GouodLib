#include "GouodLang.h"

GouodLang::GouodLang() {
    std::map<std::string, double> vars;
    interpreter = new Interpreter(vars);
    lexer = new Lexer();
}

void GouodLang::interpretString(std::string input) {
    std::cout << interpreter->interpret(lexer->tokenize(input));
}

void GouodLang::interpretFile(std::string filePath) {
    std::ifstream inFile;
    inFile.open(filePath); 

    std::stringstream strStream;
    strStream << inFile.rdbuf(); 
    std::cout << interpreter->interpret(lexer->tokenize(strStream.str())) << std::endl; 
}
