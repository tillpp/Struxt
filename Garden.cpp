#include "Garden.h"
#include <iostream>
#include <fstream>
#include <string>

Garden::~Garden(){
	for(auto& x:garden)
		delete x;
	garden.clear();
}

void Garden::loadFromFile(std::string path){
	std::fstream file(path,std::ios::in);
	if(!file.is_open())
		return;
	while(!file.eof()){
		std::string line;
		std::getline(file,line);
		std::cout << line << std::endl;
	}
}

void Garden::loadFromString(std::string code){

}