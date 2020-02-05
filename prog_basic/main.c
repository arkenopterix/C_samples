#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	
	int nbVies = 10;
	int *ptNbVies = &nbVies;
	
	char *suiteChaine;
	
	printf("Val nbvies: %d\n",nbVies);
	//printf("addr nbvies: %d\n",ptNbVies);
	printf("val2 nbvies: %d\n",*ptNbVies);
	
	suiteChaine = strpbrk("Texst de texte", "dx");
	
	printf("chaine brk: %s",suiteChaine);
	
	char chaine1[] = "Test3", chaine2[] = "Test2";
	
	if( strcmp(chaine1,chaine2) == 0 )
	{
		printf("chaines identiques");
	}
	else
	{
		printf("chaines differentes : %d", strcmp(chaine1,chaine2));
	}
	
	return 0;
	
}
//gcc -Wall -c "main.c"
//gcc -Wall -o "main" "main.c"
