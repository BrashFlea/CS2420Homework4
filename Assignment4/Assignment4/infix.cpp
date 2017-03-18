/* Place your Infix class implementation here */

/*
Jonathan Mirabile
CS2420
Assignment 4 - Infix and Postfix
*/

#include "infix.h"

using std::stack;
using std::string;

Infix::Infix() {
	infx = "";
	pfx = "";

}

Infix::Infix(string exp) {
	infx = exp;
	for(int i = 0; i < exp.length(); i++) {
		if (exp[i] == ' ') {
			
		}
		else sym[i] = exp[i];
	}

}

void Infix::setInfix(string exp) {

}

string Infix::getInfix() {
	return infx;

}

string Infix::getPostfix() {
	return pfx;

}

int Infix::getNumberOfOperators() {
	return 0;


}
int Infix::getNumberOfOperands() {
	return 0;


}
void Infix::clear() {


}
void Infix::convertToPostFix() {


}


