#ifndef CHAP15_STRUCTS
#define CHAP15_STRUCTS

//on peut créer un enum de la manière suivante (le compilateur assigne des nombre au pif aux valeurs)
typedef enum Force Force;
enum Force
{
    QUICHE, NORMAL, BALAISE
};

// on peut aussi forcer le compilateur a prendre nos valeurs
typedef enum Volume Volume;
enum Volume
{
    FAIBLE=10,MOYEN=50,FORT=100
};

typedef struct Coordonnees Coordonnees;// permet de ne pas avoir a mettre "struct"
struct Coordonnees // definit la structure
{
    int x;
    int y;
};

typedef struct Joueur Joueur;
struct Joueur
{
    char nom[20];
    int vies;
    Force f;
};



#endif
