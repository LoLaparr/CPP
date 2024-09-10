#pragma once

#include <stack>
#include <string>
#include <stdexcept>

class RPN {
public:
	int evaluate(const std::string& expression);

private:

	bool isOperator(char c);
	int performOperation(char operation, int operand1, int operand2);
};
