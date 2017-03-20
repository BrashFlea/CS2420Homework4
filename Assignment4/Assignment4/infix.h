/*
Jonathan Mirabile
CS2420
Assignment 4 - Infix and Postfix
*/

#include <string>
#include <stack>

class Infix
{

public:

	Infix();
	Infix(std::string);
	
	void setInfix(std::string);
	std::string getInfix();
	std::string getPostfix();
	int getNumberOfOperators();
	int getNumberOfOperands();
	void clear();
	void convertToPostFix();
	std::string constructSym(char*);
	
private:
	std::string infx;
	std::string sym;
	std::string pfx;
	std::stack <char> pStack;
	int operands;
	int operators;

};


