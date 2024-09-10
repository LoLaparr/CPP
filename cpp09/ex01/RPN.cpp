#include "RPN.hpp"
#include <iostream>
#include <sstream>


int RPN::evaluate(const std::string& expression) {
	std::stack<int> stack;
	std::stringstream ss(expression);
	std::string token;

    // Parcourir chaque token de l'expression
	while (ss >> token) {
		if (token.size() == 1 && isOperator(token[0])) {
            // S'il y a moins de deux opérandes dans la pile, l'expression est invalide
			if (stack.size() < 2) {
				throw std::runtime_error("Expression invalide");
			}
            // Récupérer les deux derniers opérandes
			int operand2 = stack.top(); stack.pop();
			int operand1 = stack.top(); stack.pop();

            // Effectuer l'opération et empiler le résultat
			int result = performOperation(token[0], operand1, operand2);
			stack.push(result);
		} else {
            // Sinon, c'est un nombre, on l'empile
			try {
				int operand = std::stoi(token);
				stack.push(operand);
			} catch (std::invalid_argument&) {
				throw std::runtime_error("Erreur: entrée invalide");
			}
		}
	}

    // À la fin, il doit rester exactement un élément dans la pile
	if (stack.size() != 1) {
		throw std::runtime_error("Expression invalide");
	}

	return stack.top();  // Le résultat final
}

// Méthode pour vérifier si un caractère est un opérateur
bool RPN::isOperator(char c) {
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Méthode pour effectuer une opération entre deux opérandes
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
