#include <iostream>
#include <string>
#include "Symbol.h"
#include "Line.h"
#include "Garden.h"

int main(int argc, char const *argv[])
{
	Garden garden;
	garden.loadFromFile("data.strxt");
	while(true){
		std::string line;
		std::getline(std::cin,line);
		garden.loadFromString(line);
	}	
	getchar();
}

