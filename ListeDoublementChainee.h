//
// Created by Nora Belattar on 2025-10-06.
//

#ifndef LAB1_LISTEDOUBLEMENTCHAINEE_H
#define LAB1_LISTEDOUBLEMENTCHAINEE_H

#include <cstddef>
#include <cassert>

template <typename T>
class ListeDoublementChainee {
private:
    struct Node {
        T value;
        Node * prev;
        Node * next;
        Node() : prev(nullptr), next(nullptr) {}
        explicit Node(const T& val) : value(val), prev(nullptr), next(nullptr) {}
    };
public:
    ListeDoublementChainee();

    void inserer(size_t pos, const T& val);

    const T& lire(size_t pos) const;

    size_t taille() const;
private:
    Node* trouverELementAPosition(size_t n) const;
private:
    size_t cardinal;
    Node * head;
    Node * tail;

};

template<typename T>
ListeDoublementChainee<T>::ListeDoublementChainee() : head(new Node), tail(new Node), cardinal(0) {
    head->next = tail;
    tail->prev = head;
}

template<typename T>
void ListeDoublementChainee<T>::inserer(size_t pos, const T &val) {
    assert(pos <= cardinal);
    auto c = trouverELementAPosition(pos);
    auto n = new Node(val);

    c->prev->next = n;
    n->prev = c->prev;
    c->prev = n;
    n->next = c;

    ++ cardinal;
}

template<typename T>
const T & ListeDoublementChainee<T>::lire(size_t pos) const {
    assert(pos < cardinal);
    auto p = trouverELementAPosition(pos);
    return p->value;
}

template<typename T>
size_t ListeDoublementChainee<T>::taille() const{
    return cardinal;
}

template<typename T>
typename ListeDoublementChainee<T>::Node * ListeDoublementChainee<T>::trouverELementAPosition(size_t n) const {
    Node* p = head->next;
    for (size_t i = 0; i < n; i++) {
        p = p->next;
    }
    return p;
}


#endif //LAB1_LISTEDOUBLEMENTCHAINEE_H
