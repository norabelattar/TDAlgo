//
// Created by Nora Belattar on 2025-09-18.
//

#include "gtest/gtest.h"
#include "Vecteur.h"

TEST(Vecteur, constructeur_vide) {
    Vecteur<int> v;
    EXPECT_EQ(0, v.taille());
}

TEST(Vecteur, insere_taille_vide_1) {
    Vecteur<int> v;
    v.inserer(0,42);
    EXPECT_EQ(1, v.taille());
}

TEST(Vecteur, inserer_un_element_element_lu) {
    Vecteur<int> v;
    v.inserer(0,42);
    EXPECT_EQ(42, v.lire(0));
}

TEST(Vecteur, inserer_et_supprimer_un_element) {
    Vecteur<int> v;
    v.inserer(0,42);
    v.inserer(0,666);
    v.supprimer(1);
    EXPECT_EQ(1, v.taille());
    EXPECT_EQ(666, v.lire(0));
}

TEST(Vecteur, reallouer_est_valide) {
    Vecteur<int> v(3);
    v.inserer(0,42);
    v.inserer(1,43);
    v.inserer(2,44);
    v.inserer(3,45);
    EXPECT_EQ(4, v.taille());
    EXPECT_EQ(45, v.lire(3));

}