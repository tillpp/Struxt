#pragma once
#include <iostream>
#include <vector>
#include <string>

class Tokens
{
public:

	enum Type
	{
		NUMBER = 0, LETTER = 1, SPECIAL = 2, STRING = 3, BRACKET = 4
	};

	Tokens* parent = nullptr;
	std::vector<Tokens*> children;
	Type type;
	std::string value;
	size_t line = 0;

	Tokens(size_t line = 0);
	Tokens(Tokens& original);
	~Tokens();

	void loadFromFile(std::string path);
	void loadFromString(std::string code);

	std::string information(std::string);

	bool isChildType(size_t position,Tokens::Type type);
	std::string getChildValue(size_t position);
	size_t size();

private:
	void loadFromString(std::string& code, size_t& position);
	bool loadNumber(std::string& code, size_t& position);
	bool loadLetter(std::string& code, size_t& position);
	bool loadSpecial(std::string& code, size_t& position);
	bool loadBracket(std::string& code, size_t& position);
	bool loadString(std::string& code, size_t& position);
	bool loadWhite(std::string& code, size_t& position);

	
	
	bool contain(char str, std::string keys);
	unsigned int toHex(std::string s);
};
