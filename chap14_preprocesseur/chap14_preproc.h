#ifndef CHAP14_PREPROC
#define CHAP14_PREPROC
//ces lignes permettent d'eviter des inclusion cycliques


#define LARGEUR      600
#define LONGUEUR     400
#define AIRE         (LARGEUR * LONGUEUR) //on peut faire des calculs grace au preproc

//on peut definir une fct sur plusieur lignes avec un antislash
#define LOG()        printf("DEFINE LOG Erreur a la ligne %d du fichier %s\n",__LINE__,__FILE__);\
                    printf("DEFINE LOG Le fichier a ete compile le %s a %s\n",__DATE__,__TIME__);

// une fct peut prendre des params aussi
#define MAJEUR(age, nom) if (age >= 18)\
                    printf("vous etes majeur, %s\n", nom);



#endif
