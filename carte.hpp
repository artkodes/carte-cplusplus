#include <iostream>
#include <unistd.h>
#include <SFML/Graphics.hpp>

struct Carte {int rang;int couleur;bool visible;};
struct CartePosition {int x; int y;};

void afficherCarte(Carte carte);
CartePosition lirePosition(Carte carte);
void retournerCarte(Carte* pcarte);
Carte lireCarte();