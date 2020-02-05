#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char lettre = 'A'; //assignation d'une lettre: avec quotes
	char chaine[]= "Salut"; //assignation d'une chaine: avec quillemets, alloue un tableau de longeure chaine +1 pour le car de fin de chaine
	
	/* Assignation case par case (il faut prévoir le char de fin de chaine dans ce cas */
	char chaine2[6];
	
	chaine2[0]='S';
	chaine2[1]='a';
	chaine2[2]='l';
	chaine2[3]='u';
	chaine2[4]='t';
	chaine2[5]='\0';
	
	printf("chaine : %s \n",chaine);
	printf("chaine2 : %s \n",chaine2);
	
	//récupération d'une chaine via scanf
	char prenom[100];
	
	printf("Quel est ton nom ? \n");
	scanf("%s",prenom);//prenom est un pointeur deja, pas besoin du &
	printf("Salut %s! \n",prenom);
	
	// STRLEN : longeur d'une chaine de caracteres
	int longueurInput = 0;
	
	longueurInput = strlen(prenom);
	printf("la longueur de la chaine %s est: %d \n",prenom,longueurInput);
	
	// STRCPY : copie d'une chaine dans une autre
	char copie[100] = {0}; // on initialise la totalité de tableau de char à 0
	
	strcpy(copie, prenom); // on copie "prenom" dans "copie"
	
	printf("boom! voila une copie de l'input: %s , gratos! \n", copie);
	
	// STRCAT : concatener deux chaines
	
	char prefixe[100] = "salut ", suffixe[]="Joel!" ;// la première chaine doit être assez grand pour acceuillir les deux contenus
	
	strcat(prefixe,suffixe);
	
	printf("le prefixe vaut maintenant : %s \n",prefixe);
	printf("alors que le suffixe vaut toujours : %s \n",suffixe);
	
	// STRCMP : comparer une string a une autre
	
	
	return 0;
	
}
//gcc -Wall -c "chap13_strings.c"
//gcc -Wall -o "chap13_strings" "chap13_strings.c"
