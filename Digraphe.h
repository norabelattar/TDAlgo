//
// Created by Nora Belattar on 2025-10-06.
//

#ifndef LAB1_DIGRAPHE_H
#define LAB1_DIGRAPHE_H

#include <cassert>
#include <list>
#include <algorithm>


template <typename T>
class Digraphe {
private:
    struct Arc {
        size_t destination;
        double poids;

        bool operator == (size_t n) const {return destination == n;}
        Arc(size_t dest, double pds) : destination(dest), poids(pds) {}
    };
public:
    Digraphe();

    void ajouterSommet(const T& sommet);
    // void supprimerSommet(const T& sommet);
    void ajouterArc(const T& depart, const T& arrivee, double poids = 0.0);
    // void supprimerArc(const T& depart, const T& arrivee);
    // std::unorderd<T, double> sommetsAdjacents(const T& depart) const ;
    size_t taille() const;
    // size_t ariteSortie(const T& depart) const;
    // size_t ariteEntree(const T& sommet) const;
    bool sommetExiste(const T& sommet) const;
    bool arcExiste(const T& depart, const T& arrivee) const;
    std::unordered_map<T, double> sommetsAdjacents(const T &depart) const;
    // std::string toString() const;
    // void dijkstra(const T& depart) const;
    const std::vector<T>& enumererSommets() const;
private:
    size_t trouverNumeroDuSommet(const T &sommet) const;
    bool invariant() const;
private:
    std::vector<T> index;
    std::vector<std::list<Arc>> listes;

};

template<typename T>
Digraphe<T>::Digraphe() : index(), listes() {
    assert(invariant());
}

template<typename T>
void Digraphe<T>::ajouterSommet(const T &sommet) {
    assert(!sommetExiste(sommet));
    index.push_back(sommet);
    listes.emplace_back();
    assert(invariant());
}

template<typename T>
void Digraphe<T>::ajouterArc(const T &depart, const T &arrivee, double poids) {
    size_t ndep = trouverNumeroDuSommet(depart);
    size_t narr = trouverNumeroDuSommet(arrivee);
    listes.at(ndep).emplace_back(narr, poids);
}

template<typename T>
size_t Digraphe<T>::taille() const {
    return index.size();
}

template<typename T>
bool Digraphe<T>::sommetExiste(const T &sommet) const {
    return std::find(index.begin(), index.end(), sommet) != index.end();
}

template<typename T>
bool Digraphe<T>::arcExiste(const T &depart, const T &arrivee) const {
    auto ndep = trouverNumeroDuSommet(depart);
    auto narr = trouverNumeroDuSommet(arrivee);
    return std::find(listes.at(ndep).begin(), listes.at(ndep).end(), narr) != listes.at(ndep).end();
}

template<typename T>
std::unordered_map<T, double> Digraphe<T>::sommetsAdjacents(const T &depart) const {
    assert(sommetExiste(depart));
    std::unordered_map<T, double> voisins;
    auto ndep = trouverNumeroDuSommet(depart);
    for (auto arc: listes.at(ndep)) voisins.insert({index.at(arc.destination), arc.poids});
    return voisins;
}

template<typename T>
const std::vector<T>& Digraphe<T>::enumererSommets() const {
    return index;
}

template<typename T>
size_t Digraphe<T>::trouverNumeroDuSommet(const T &sommet) const {
     auto it =  std::find(index.begin(), index.end(), sommet);
    return std::distance(index.begin(), it);
}

template<typename T>
bool Digraphe<T>::invariant() const {
    if (index.size() != listes.size()) return false;
    return true;
}

#endif //LAB1_DIGRAPHE_H
