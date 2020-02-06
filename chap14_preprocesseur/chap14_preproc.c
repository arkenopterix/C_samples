#include <stdio.h>
#include <stdlib.h>
#include "chap14_preproc.h"

int main(int argc, char *argv[])
{

    printf("Aire calculee via define : %d \n",AIRE);

    //il est possilbe de loger des infos grace aux vars preproc natives
    printf("Erreur a la ligne %d du fichier %s\n",__LINE__,__FILE__);
    printf("Le fichier a ete compile le %s a %s\n",__DATE__,__TIME__);

    // on peut faire la meme chose via fct defined
    LOG()

    //on peut aussi faire des fct qui prennent des paramètres
    MAJEUR(20,"Maxime")

	return 0;

}
//gcc -Wall -c "chap14_strings.c"
//gcc -Wall -o "chap14_strings" "chap14_strings.c"
