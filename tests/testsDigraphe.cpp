//
// Created by Nora Belattar on 2025-10-06.
//

#include "gtest/gtest.h"
#include "Digraphe.h"

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