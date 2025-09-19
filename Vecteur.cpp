//
// Created by Nora Belattar on 2025-09-18.
//

#include "Vecteur.h"

#include <stdexcept>

Vecteur::Vecteur() : adresse(new int[5]), cardinal(0)  {
}

void Vecteur::inserer(size_t index, int nouveau) {
    // Valider l'index
    if (index > cardinal) throw std::invalid_argument("inserer: index hors-limite!");
    // Tasser chaque élément du dernier ad index d'une position
    for (size_t i = cardinal; i > index; i--) adresse[i] = adresse[i-1];
    // Écrire le nouvel élément à la position index
    adresse[index] = nouveau;
    ++cardinal;
}


size_t Vecteur::taille() const {
    return cardinal;
}
