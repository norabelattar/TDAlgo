//
// Created by Nora Belattar on 2025-10-06.
//

#include "gtest/gtest.h"
#include "Digraphe.h"
#include "AlgorithmesDigraphes.h"

TEST(Digraphe, digraphe_vide) {
    Digraphe<int> d;
    EXPECT_EQ(0, d.taille());
}

TEST(Digraphe, digraphe_vide_ajouter_un_taille_un) {
    Digraphe<int> d;
    d.ajouterSommet(42);
    EXPECT_EQ(1, d.taille());
}

TEST(Digraphe, digraphe_vide_ajoute_un_lire_un) {
    Digraphe<int> d;
    d.ajouterSommet(42);
    EXPECT_TRUE(d.sommetExiste(42));
    EXPECT_FALSE(d.sommetExiste(666));
}

TEST(Digraphe, digraphe_deux_sommets_ajouter_arc) {
    Digraphe<int> d;
    d.ajouterSommet(42);
    d.ajouterSommet(84);
    d.ajouterArc(42, 84, 5.0);
    EXPECT_TRUE(d.arcExiste(42, 84));
}

TEST(Digraphe, digraphe_deux_sommets_enumerer_sommets) {
    Digraphe<int> d;
    d.ajouterSommet(42);
    d.ajouterSommet(84);
    EXPECT_EQ(2, d.enumererSommets().size());
}

TEST(Digraphe, digraphe_deux_sommets_dfs) {
    Digraphe<int> d;
    d.ajouterSommet(42);
    d.ajouterSommet(84);
    d.ajouterArc(42,84,9.0);
    auto res = dfs_explore(d,42);
    EXPECT_EQ(42, res.top());
    res.pop();
    EXPECT_EQ(84, res.top());
}

TEST(Digraphe, digraphe_trois_sommets_dfs) {
    Digraphe<int> d;
    d.ajouterSommet(42);
    d.ajouterSommet(84);
    d.ajouterSommet(666);
    d.ajouterArc(42, 84, 9.0);
    d.ajouterArc(84, 666, 67.0);
    d.ajouterArc(666, 42, 27.8);
    auto res = dfs_explore(d, 42);
}