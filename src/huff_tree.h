#pragma once

#include <vector>
#include <string> 

struct Huff_tree
{
    Huff_tree* fils0 = nullptr;
    Huff_tree* fils1 = nullptr;
    char val = ' ';
};

class Huffmann
{
public :
    Huff_tree* treeRoot; // La racine de l'arbre de Huffmann
    std::vector<std::vector<bool>> compressedMessages; // Vecteur contenant tous les messages compressés

    Huffmann(std::vector<std::string> messages); // Prend en entrée un vecteur avec les messages non compressés correspondants aux différentes matrices 8*8

    Huff_tree* getTreeRoot(); // Renvoie la racine de l'arbre de Huffmann
    std::vector<std::vector<bool>> getByteCodes(); // Renvoie un vecteur contenant tous les messages compressés
};