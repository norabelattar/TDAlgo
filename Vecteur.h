//
// Created by Nora Belattar on 2025-09-18.
//

#ifndef VECTEUR_H
#define VECTEUR_H

#include <cstddef>

class Vecteur {
    public:
        Vecteur();
        void inserer(size_t index, int nouveau);
        size_t taille() const;

    private:
        int* adresse;
        size_t cardinal;
};


#endif //VECTEUR_H