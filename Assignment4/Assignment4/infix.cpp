/* Place your Infix class implementation here */

/*
Jonathan Mirabile
CS2420
Assignment 4 - Infix and Postfix
*/

#include "infix.h"

using std::stack;
using std::string;

//Default constructor
Infix::Infix() {
	
	infx = "";
	pfx = "";
	operands = 0;
	operators = 0;

}

//String constructor
Infix::Infix(string exp) {
	
	infx = exp;
	operands = 0;
	operators = 0;
	int size = infx.length();
	int precedence = 0;
	int j = 0;
	sym = infx;

	for (int i = 0; i < size + 1; i++) {
		//Skip whitespace
		if (sym[i] == ' ') {
			i++;
		}
		//Left parentheses check
		if (sym[i] == '(') {
			pStack.push('(');
		}
		//Right parentheses check
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
		//Construct digits symbol
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
		//Operator Checks
		//Exponent
		if (sym[i] == '^') {
			pStack.push(sym[i]);
			operators++;
			precedence = 3;
		}
		//Multiply/Divide
		if (sym[i] == '*' || sym[i] == '/') {

			pStack.push(sym[i]);
			operators++;
			precedence = 2;
		}
		//Addition/Subtraction
		if (sym[i] == '+' || sym[i] == '-') {
			if (precedence > 1) {
				if (pStack.top() == '(') {
					pStack.pop();
				}
				else {
					pfx += pStack.top();
					pfx += ' ';
					pStack.pop();

				}
			}
			pStack.push(sym[i]);
			operators++;
			precedence = 1;
		}

	}
	//Append all remaining operators
	while (pStack.empty() != true) {
		if (pStack.empty()) {
			break;
		}
		if (pStack.top() == '(') {
			pStack.pop();
		}
		else {
			pfx += pStack.top();
			pfx += ' ';
			pStack.pop();

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

	//Stack Clear
	while (pStack.empty() != true) {
		pStack.pop();
	}

}

void Infix::convertToPostFix() {
	int size = infx.length();
	int precedence = 0;
	int j = 0;
	sym = infx;

	for (int i = 0; i < size + 1; i++) {
		//Skip whitespace
		if (sym[i] == ' ') {
			i++;
		}
		//Left parentheses check
		if (sym[i] == '(') {
			pStack.push('(');
		}
		//Right parentheses check
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
		//Construct digits symbol
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
		//Operator Checks
		//Exponent
		if (sym[i] == '^') {
			pStack.push(sym[i]);
			operators++;
			precedence = 3;
		}
		//Multiply/Divide
		if (sym[i] == '*' || sym[i] == '/') {
			pStack.push(sym[i]);
			operators++;
			precedence = 2;
		}
		//Addition/Subtraction
		if (sym[i] == '+' || sym[i] == '-') {
			if (precedence > 1) {
				if (pStack.top() == '(') {
					pStack.pop();
				}
				else {
					pfx += pStack.top();
					pfx += ' ';
					pStack.pop();

				}
			}
			pStack.push(sym[i]);
			operators++;
			precedence = 1;
		}

	}
	//Append all remaining operators
	while (pStack.empty() != true) {
		if (pStack.empty()) {
			break;
		}
		if (pStack.top() == '(') {
			pStack.pop();
		}
		else {
			pfx += pStack.top();
			pfx += ' ';
			pStack.pop();

		}

	}
	 
}



