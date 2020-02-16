#ifndef DICO
#define DICO

#define TAILLE_MAX_MOT 100


typedef struct Dictionnaire Dictionnaire;
struct Dictionnaire
{
    char mot[TAILLE_MAX_MOT];
    int tailleMot;
};

int compteMotsDansFichier(FILE *f);

int chargementDictionnaire(FILE *f,Dictionnaire *d, int nbMots);

#endif
