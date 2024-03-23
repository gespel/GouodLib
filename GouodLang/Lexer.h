#pragma once
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
	MINUS,
	MULTIPLY,
	DIVIDE,
	FUNCTION,
	COMMA,
	SEMICOLON,
	RETURN
};


class Lexer {
public:
	Lexer();
	std::vector<std::pair<TokenType, std::string>> tokenize(std::string input);
	void printTokens(std::vector<std::pair<TokenType, std::string>> tokens);
	void tokenizeKeywords(std::vector<std::pair<TokenType, std::string>> &tokens);
private:
};