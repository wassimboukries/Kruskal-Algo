/**
 * @file main.cpp
 * @author Wassim Boukries (wassim.boukries@etu.uca.com)
 * @brief fichier qui comporte la fonction main, c'est l'entrée du projet
 * @version 0.1
 * @date 2022-01-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>
#include "functions.h"

int main(int argc, char * argv []) {
    graph_t myGraph;
    std::vector<int> edges;
    std::string inputFileName = "inputFile2.txt";

    // en vérifie si un nom de fichier est renseigné ou pas, sinon on utilise celui par défaut
    if (argc > 1) {
        inputFileName = argv[1];
    }

    readGraph(inputFileName, myGraph);
    Kruskal(myGraph);

    return 0;
}