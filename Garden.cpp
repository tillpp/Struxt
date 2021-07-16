#include "Garden.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>


Garden::~Garden(){
	for(auto& x:garden)
		delete x;
	garden.clear();
}

void Garden::loadFromFile(std::string path){
	Tokens tokens;
	tokens.loadFromFile(path);
	loadFromTokens(&tokens);
}

void Garden::loadFromString(std::string code){
	Tokens tokens;
	tokens.loadFromString(code);
	loadFromTokens(&tokens);

}
Symbol x(std::map<std::string,Symbol*>& ){

}
void Garden::loadFromTokens(Tokens* tokens){
	size_t pos = 0;
	std::map<std::string,Symbol*> globalnames;

	while(tokens->children.size()>pos)
	{
		if(tokens->isChildType(pos,Tokens::LETTER)
		&&tokens->getChildValue(pos)=="Symbol"){
			do{
				pos++;
				//symbolname
				Symbol* symbol = new Symbol;
				globalnames[tokens->getChildValue(pos)]=symbol;
				garden.push_back(symbol);
				if(!tokens->isChildType(pos,Tokens::LETTER)	)
					std::cerr << "Symbolname expected: Line "<<tokens->children[pos]->line<<std::endl;
				else pos++;
			}while(tokens->isChildType(pos,Tokens::SPECIAL)
				&&tokens->getChildValue(pos)==",");
			
			if(tokens->isChildType(pos,Tokens::SPECIAL)
				&&tokens->getChildValue(pos)==";")
				pos++;
			else std::cerr << "Semicolon expected: Line "<<tokens->children[pos]->line<<std::endl;
		}else{
			// a:b>c;
		}
	}
}