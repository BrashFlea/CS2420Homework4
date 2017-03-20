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
	operands = 0;
	operators = 0;

}

Infix::Infix(string exp) {
	infx = exp;
	char* symPtr;

	bool pushStack = false;
	for(unsigned int i = 0; i < infx.length(); i++) {
		sym[i] = exp[i];
		if (sym[i] == ' ') {
			i++;
		}
		if (sym[i] == '(') {
			pStack.push('(');
		}
		if (sym[i] == ')') {
			while (pStack.top() != '(')
				if (pStack.empty()) {
					break;
				}
			 pStack.pop();
		} 
		else {
			symPtr = &sym[i];
			pfx += constructSym(symPtr);

		}
	}

}

void Infix::setInfix(string exp) {
	this->clear();
	this->infx = exp;
	operands = 0;
	operators = 0;
	this->convertToPostFix();

}

string Infix::getInfix() {
	return infx;

}

string Infix::getPostfix() {
	return pfx;
}

int Infix::getNumberOfOperators() {
	return operators;

}

int Infix::getNumberOfOperands() {
	return operands;

}

void Infix::clear() {
	this->infx = "";
	this->sym = "";
	operands = 0;
	operators = 0;
	this->pfx = "";

	while (pStack.empty() != true) {
		pStack.pop();
	}

}

void Infix::convertToPostFix() {
	int size = infx.length();
	bool pushStack = false;
	int j = 0;
	sym = infx;

	for (int i = 0; i < size + 1; i++) {
		
		if (sym[i] == ' ') {
			i++;
		}
		if (sym[i] == '(') {
			pStack.push('(');
		}
		if (sym[i] == ')') {
			while (pStack.top() != '(') {
				if (pStack.empty()) {
					break;
				}
				pfx += pStack.top();
				pfx += ' ';
				pStack.pop();
			}

		}
		if (isdigit(sym[i])) {
			j = i;
			while (isdigit(sym[j])) {
				this->pfx += sym[j];
				j++;
			}
			operands++;
			pfx += ' ';
			i = --j;
		}
		//operator check
		if (sym[i] == '^') {
			pStack.push(sym[i]);
			operators++;
		}
		if (sym[i] == '*' || sym[i] == '/') {
			pStack.push(sym[i]);
			operators++;
		}
		if (sym[i] == '+' || sym[i] == '-') {
			pStack.push(sym[i]);
			operators++;
		}
	}
	//Add spaces to pfx for output and append operators
	 
}

string Infix::constructSym(char* sym) {
	int i = 0;
	string cSym = "";
	while (isdigit(sym[i])) {
		cSym += sym[i];
		i++;
	}
	return cSym;
}


