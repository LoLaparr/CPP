#include <iostream>
#include <fstream>
#include <string>

void replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2) {
    // Ouvrir le fichier en lecture
    std::ifstream input(filename);
    if (!input) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier " << filename << std::endl;
        return;
    }

    // Créer un nouveau nom de fichier pour le fichier de sortie
    std::string outputFilename = filename + ".replace";

    // Ouvrir le fichier en écriture
    std::ofstream output(outputFilename);
    if (!output) {
        std::cerr << "Erreur : Impossible de créer le fichier de sortie " << outputFilename << std::endl;
        return;
    }

    // Lire le contenu du fichier ligne par ligne et remplacer les occurrences
    std::string line;
    while (std::getline(input, line)) {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos) {
            line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
            pos += s2.length(); // Avancer la position après le remplacement
        }
        // Écrire la ligne modifiée dans le fichier de sortie
        output << line << std::endl;
    }

    // Fermer les fichiers
    input.close();
    output.close();

    std::cout << "Le remplacement est terminé. Le fichier de sortie est : " << outputFilename << std::endl;
}

int main(int argc, char *argv[]) {
    // Vérifier le nombre d'arguments
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <nom_fichier> <s1> <s2>" << std::endl;
        return 1;
    }

    // Récupérer les arguments
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    // Effectuer le remplacement dans le fichier
    replaceInFile(filename, s1, s2);

    return 0;
}
