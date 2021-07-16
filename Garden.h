#include <string>
#include <vector>
#include "Symbol.h"
#include "Tokens.h"

class Garden
{
public:
	std::vector<Symbol*> garden;

	void loadFromFile(std::string file);
	void loadFromString(std::string code);
	~Garden();
private:
	void loadFromTokens(Tokens* tokens);

};