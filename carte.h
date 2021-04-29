#ifndef CARTE_H_
#define CARTE_H_
typedef enum {CARREAU, COEUR, PIQUE, TREFLE} COULEUR;
struct maillon{Carte carte;struct maillon* suivant;};
typedef maillon* Liste;
#endif /* CARTE_H_ */