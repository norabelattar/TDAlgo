//
// Created by Nora Belattar on 2025-09-18.
//

#include "gtest/gtest.h"
#include "Vecteur.h"

TEST(Vecteur, constructeur_vide) {
    Vecteur v;
    EXPECT_EQ(0, v.taille());
}

TEST(Vecteur, insere_taille_vide_1) {
    Vecteur v;
    v.inserer(0,42);
    EXPECT_EQ(1, v.taille());
}