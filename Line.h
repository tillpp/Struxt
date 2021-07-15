#include "Symbol.h"

class Line:public Symbol{
	public:
	Line();
	Line(Symbol *map,Symbol *key,Symbol *value);
	Symbol *map,*key,*value;	
};
