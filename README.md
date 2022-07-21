# Struxt
A relation-based Data Language. 

Everything in Struxt is a symbol. 
Three symbols a,b,c make up a triplets, which can be intepreted in different ways:
- As function-value-pair: b(a)=c
- As triplets:            (a,b,c)
- As relation:            (a,c)∈b
- As arrow in a graph:    a--[b]-->c

Note that triplets are symbols themself. This can be used to store information about information:
"The statement a=4 is false" ((a,=,4),is,false)

# Data-Syntax

``Symbol x;``
Defined the symbol x

``a:b>c;``
Defined a triple
- *Key*   a
- *Map*   b
- *Value* c

``@name(a:b>c);``
Defined a triple and named it.

``a:$b>c;``
Defined a local symbol b, while defining a triple
b is only referable within this command. Commands end with a semicolon.

``a:@b>c;``
Defined a symbol b, while defining a triple
b is referable within the scope.

``{Symbol x;...}``
Defined a scope, all names inside are only accessable from within the scope

``name{ Symbol x;...}``
Defined a namespace, symbol inside is refered outside the scope as: name.x

``import print from iostream;
import * from "filename";``
import stuff from other files.

``@command = ("Hello world":print>_)``
Defines a the command 'print("Hello world")' and doesn't store the resulting value, because of the _

``(command,executed,false)``
executes command. triple is replaced after execution with (command,executed,true) 

``(command,execute.newthread,true)``
information that the command shall be executed in a new thread.

```#set{a,b,c}``
defines a symbol "set". with (a,in,set),(b,in,set) and (c,in,set)
