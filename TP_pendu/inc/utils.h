#ifndef UTILS
#define UTILS

void initMotCache(char *c,int taille);

int menu(int *choix);

char lireCaractere();

int chercherCaratereLu(char cLu, char* motADeviner, char* motCache, int *nbOccurence);

int choisiChiffreAuPif(int nbMots);

#endif
