#include "GouodLang.h"

GouodLang::GouodLang() {

}

void GouodLang::interpretString(std::string input) {
    std::cout << interpreter.interpret(lexer.tokenize(input));
}

void GouodLang::interpretFile(std::string filePath) {
    std::ifstream inFile;
    inFile.open(filePath); 

    std::stringstream strStream;
    strStream << inFile.rdbuf(); 
    std::cout << interpreter.interpret(lexer.tokenize(strStream.str())) << std::endl; 
}