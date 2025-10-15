//
// Created by Nora Belattar on 2025-10-14.
//

#include <stack>
#include <unordered_map>
#include "Digraphe.h"

template <typename T>
void aux_dfs_explore(Digraphe<T> g, const T& depart, std::stack<T>& abandons, std::unordered_map<T, bool> decouverts) {
    decouverts.at(depart) = true;
    for (auto arc: g.sommetsAdjacents(depart)) {
        auto voisin = std::get<0>(arc);
        if (decouverts.at(voisin) == false) aux_dfs_explore(g, voisin, abandons, decouverts);
    }
    abandons.push(depart);
}

template <typename T>
std::stack<T> dfs_explore(Digraphe<T> g, const T& depart) {
    std::stack<T> abandons;
    std::unordered_map<T, bool> decouverts;
    for (auto s: g.enumererSommets()) decouverts.insert({s, false});

    aux_dfs_explore(g, depart, abandons, decouverts);
    return abandons;
}

template <typename T>
std::unordered_map<T, T> bfs_explore(Digraphe<T> g, const T& depart) {
    std::unordered_map<T, bool> decouverts;
    for (auto s : g.enumererSommets()) decouverts.insert({s, false});
    std::unordered_map<T, T> predecesseurs;
    std::queue<T> attente;
    attente.push(depart);
    while (!attente.empty()) {
        auto courant = attente.front();
        attente.pop();
        decouverts.at(courant) = true;
        for (auto arc: g.sommetsAdjacents(courant)) {
            auto voisin = std::get<0>(arc);
            if (!decouverts.at(voisin)) {
                attente.push(voisin);
                predecesseurs.insert({voisin, courant});
            }
        }
    }
    return predecesseurs;
}