#include <stdio.h>
#include <stdlib.h>
#include "chap16_fichiers.h"

/*
*Modes d'ouvertures de fichiers:
* r  : lecture seule, on ne peut pas écrire, le fichier doit exiter
* w  : ecriture seule, on ne peut pas lire, si le fichier n'existe pas, il est créé
* a  : mode ajout, vous ecrivez dans le fichier en partant de la fin. si le fichier n'existe pas, il est créé
* r+ : lecture et ecriture, le fichier doit exiter
* w+ : lecture et ecriture, et suppression du contenu au préalable (le fichier est vidé à l'ouverture), si le fichier n'existe pas, il est créé.
* a+ : ajout en lecture/ecriture à la fin. On ecrit et lit du texte à partir de la fin du fichier. Si le fichier n'existe pas, il est créé
* rb,wb, ab, rb+, wb+, ab+: idem que les autres modes, mais en mode binaire
*/

void readFileC(FILE *f)
{

    int caractereActuel = 0;

    do
    {
        caractereActuel = fgetc(f);
        printf("%c",caractereActuel);
    } while(caractereActuel != EOF);

}


void readFileS(FILE *f, char *c )
{


        while (fgets(c,TAILLE_MAX,f) != NULL) // on lit le fichier tant qu'on ne recoit pas d'erreurs (NULL)
        {
            printf("%s",c);
        }
}



int main(int argc, char *argv[])
{
    FILE *fichier = NULL; // on initialise la struct FILE
    FILE *fichierScore = NULL;
    char chaine[TAILLE_MAX];
    int score[3] = {0};

    fichier = fopen("text.txt", "w"); //on initialise le fichier en mode ecriture seule (création de fichier s'il n'existe pas)




    if(fichier != NULL)// on teste si l'ouverture c'est bien passée
    {

        fputc('A',fichier);// on insère un caractère
        fputs("\nSalut les zou\nzous\n",fichier);// on insère une chaine
        fprintf(fichier,"nous sommes le %d decembre!\n",3);
        fclose(fichier);// on ferme le fichier après utilisation

    }

    fichier = fopen("text.txt", "r");

    if(fichier != NULL)// on teste si l'ouverture c'est bien passée
    {

        readFileC(fichier);

        rewind(fichier);// on remet le curseur du fichier à 0

        readFileS(fichier,chaine);

        fclose(fichier);// on ferme le fichier après utilisation

    }

    fichierScore = fopen("score.txt", "r");
    if(fichierScore != NULL)// on teste si l'ouverture c'est bien passée
    {
        fscanf(fichierScore, "%d %d %d", &score[0], &score[1], &score[2] );
        printf("Les meilleurs scores sont: %d , %d, et %d\n",score[0], score[1], score[2]);
        fclose(fichierScore);
    }

    rename("text.txt","text2.txt");

    remove("text2.txt");

    return 0;

}
//gcc -Wall -o "chap16_fichiers" "chap16_fichiers.c"
