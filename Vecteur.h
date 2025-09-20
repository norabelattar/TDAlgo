//
// Created by Nora Belattar on 2025-09-18.
//

#ifndef VECTEUR_H
#define VECTEUR_H

#include <cstddef>
#include <cassert>

template <typename T>
class Vecteur {
    public:
        Vecteur(size_t cap = DEF_CAPACITE);
        void inserer(size_t index, T nouveau);
        T lire(size_t index) const;
        void supprimer(size_t index);
        void remplacer(size_t index, T nouveau);
        size_t taille() const;


    private:
        static const size_t DEF_CAPACITE = 13;
        size_t capacite;
        T* adresse;
        size_t cardinal;
        bool indexEstValidEnLecture(size_t index) const;
        void reallouer();
        bool invariant() const;
};

template<typename T>
Vecteur<T>::Vecteur(size_t cap) : capacite(cap), adresse(new T[cap]), cardinal(0) {
}

template<typename T>
void Vecteur<T>::inserer(size_t index, T nouveau) {
    assert(index <= cardinal);
    if (cardinal == capacite) reallouer();
    for (size_t j = cardinal; j > index; --j ) adresse[j] = adresse[j-1];
    adresse[index] = nouveau;
    ++cardinal;
    assert(invariant());
}

template<typename T>
T Vecteur<T>::lire(size_t index) const {
    assert(indexEstValidEnLecture(index));
    return adresse[index];
}

template<typename T>
void Vecteur<T>::supprimer(size_t index) {
    assert(indexEstValidEnLecture(index));
    for (size_t j = index; j < cardinal - 1; ++j ) adresse[j] = adresse[j + 1];
    --cardinal;
    assert(invariant());
}

template<typename T>
void Vecteur<T>::remplacer(size_t index, T nouveau) {
    if (!indexEstValidEnLecture(index)) throw std::invalid_argument("index hors-limite dans remplacer");
    adresse[index] = nouveau;
    assert(invariant());
}

template<typename T>
size_t Vecteur<T>::taille() const {
    return cardinal;
}

template<typename T>
bool Vecteur<T>::indexEstValidEnLecture(size_t index) const {
    return index < cardinal;
}

template<typename T>
void Vecteur<T>::reallouer() {
    T* backup = new T[capacite];
    for (size_t i = 0; i < cardinal; ++i) backup[i] = adresse[i];
    delete[] adresse;
    capacite = 2 * capacite;
    adresse = new T[capacite];
    for (size_t i = 0; i < cardinal; ++i) adresse[i] = backup[i];
}

template<typename T>
bool Vecteur<T>::invariant() const {
    if (capacite == 0) return false;
    if (adresse == nullptr) return false;
    return cardinal <= capacite;
}


#endif //VECTEUR_H
