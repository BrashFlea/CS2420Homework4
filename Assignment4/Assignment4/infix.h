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

	bool precedence;
	
private:
	std::string infx;
	std::string pfx;
	std::stack <std::string> pStack;

};


