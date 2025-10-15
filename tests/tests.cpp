//
// Created by Nora Belattar on 2025-10-06.
//

#include "../ListeDoublementChainee.h"
#include "gtest/gtest.h"

TEST(ListeDoublementChaine, constructeur_vide) {
    ListeDoublementChainee<int> l ;
    EXPECT_EQ(0, l.taille());
}

TEST(ListeDoublementChainee, inserer_lire) {
    ListeDoublementChainee<int> l ;
    l.inserer(0,42);
    EXPECT_EQ(42, l.lire(0));
}

