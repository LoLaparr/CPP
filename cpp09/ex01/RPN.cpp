#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>

int RPN::evaluate(const std::string& expression) {
	std::stack<int> stack;
	std::stringstream ss(expression);
	std::string token;

	while (ss >> token) {
		if (token.size() == 1 && isOperator(token[0])) {
			if (stack.size() < 2) {
				throw std::runtime_error("Expression invalide");
			}
			int operand2 = stack.top(); stack.pop();
			int operand1 = stack.top(); stack.pop();

			int result = performOperation(token[0], operand1, operand2);
			stack.push(result);
		} else {
			try {
				int operand = std::atoi(token.c_str());
				stack.push(operand);
			} catch (std::invalid_argument&) {
				throw std::runtime_error("Erreur: entrée invalide");
			}
		}
	}

	if (stack.size() != 1) {
		throw std::runtime_error("Expression invalide");
	}

	return stack.top();
}

bool RPN::isOperator(char c) {
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

int RPN::performOperation(char operation, int operand1, int operand2) {
	switch (operation) {
		case '+': return operand1 + operand2;
		case '-': return operand1 - operand2;
		case '*': return operand1 * operand2;
		case '/':
			if (operand2 == 0) {
				throw std::runtime_error("Erreur: division par zéro");
			}
			return operand1 / operand2;
		default:
			throw std::runtime_error("Erreur: opérateur invalide");
    }
}
