#include "Line.h"
Line::Line(){}
Line::Line(Symbol *map,Symbol *key,Symbol *value){
	this->map = map;
	this->key = key;
	this->value = value;
}
	