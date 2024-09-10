#include <iostream>
#include <string>
#include "BitcoinExchange.hpp"

int main(int argc, char* argv[]) {
    // Vérification du nombre d'arguments
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <database.csv> <input.txt>" << std::endl;
        return 1;
    }


/*
faire une fonction qui parse input.txt et data.csv
*/
    std::string inputFile = argv[1];

    // Créer une instance de BitcoinExchange
    BitcoinExchange exchange;
    // Charger la base de données des taux de change
try
{
    exchange.loadDatabase("data.csv");
}
catch(const std::exception& e)
{
    std::cerr << e.what() << std::endl;
}

    exchange.isValidInput(exchange.getMap());
    // Traiter le fichier d'entrée
try
{
    exchange.processInputFile(inputFile);
}
catch(const std::exception& e)
{
    std::cerr << e.what() << std::endl;
}




    return 0;
}
