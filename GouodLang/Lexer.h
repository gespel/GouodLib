#include <string>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <sstream>

enum class TokenType {
	NUMBER,
	IDENTIFIER,
	LEFTPARAN,
	RIGHTPARAN,
	LEFTBRACK,
	RIGHTBRACK,
	ASSIGN,
	PLUS,
	FUNCTION


};


class Lexer {
public:
	Lexer();
	std::vector<std::pair<TokenType, std::string>> tokenize(std::string input);
	std::vector<std::pair<TokenType, std::string>> tokenizeLine(std::string input);
	void printTokens(std::vector<std::pair<TokenType, std::string>> tokens);
	void tokenizeKeywords(std::vector<std::pair<TokenType, std::string>> &tokens);
private:
};