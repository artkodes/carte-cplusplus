#include <iostream>
#include <SFML/Graphics.hpp>
#include <unistd.h>
#include "carte.cpp"

int main()
{
    Liste L = create_liste();
    Carte carte;

    carte = readCart();
    L = ajout_queue(carte, L);
    carte = lireCarte();
    L = ajout_queue(carte, L);
    L = deleteHead(L);

    visualise_liste(L);

    return 0;
}
 