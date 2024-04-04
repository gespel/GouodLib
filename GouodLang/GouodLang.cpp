#include "GouodLang.h"

GouodLang::GouodLang() {

}

void GouodLang::interpretString(std::string input) {
    std::cout << interpreter.interpret(lexer.tokenize(input));
}