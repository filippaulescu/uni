#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 
 
int is_fazan( char *cuv1, char *cuv2)
{
	char ultima1= tolower(cuv1[strlen(cuv1) -1]);
	char penultima1= tolower(cuv1[strlen(cuv1) -2]);
	char prima2= tolower(cuv2[0]);
	char a_doua2= tolower(cuv2[1]);
	return penultima1==prima2 && ultima1==a_doua2;
}
 
 
int main()
{
/*Jocul fazan: se citesc de la tastatură cuvinte separate prin spaţii albe (spaţiu, TAB sau ENTER), până la întâlnirea cuvântului vid. Pornind de la cuvintele
citite, se construieşte un şir de caractere după următoarele reguli:
    - Primul cuvânt citit se adaugă la şirul de caractere
    - Fiecare din următoarele cuvinte citite se adaugă la şirul de caractere dacă ultimele două litere ale şirului coincid cu primele două litere ale cuvântului
    (nu se face distincţie între literele mici şi cele mari);
Cuvintele adăugate la şirul de caractere sunt despărţite de caracterul ’-’. Să se afişeze şirul astfel construit. Programul va folosi alocare dinamică astfel
încât spaţiul de memorie utilizat să fie minim.
Spre exemplu, pentru intrarea:
 
Fazan Antic Noe icoana Egipt naftalina nimic Narcisa trei altceva santier iarba Caine Pisica erudit
 
se afişează:
 
Fazan-Antic-icoana-naftalina-Narcisa-santier-erudit*/
 
char buffer[100];
char *fazan = NULL, *temp;
 
scanf("%99s", buffer);
 
fazan = malloc( (strlen(buffer)+1) * sizeof(char));
if (fazan == NULL)
{
	printf("eroare");
	exit(EXIT_FAILURE);
}
 
strcpy(fazan , buffer );
 
for(;;)
{
	if( (scanf("%99s", buffer)) == EOF )
	{
		break;
	}
 
	if( is_fazan(fazan, buffer)==0 )
		continue;
 
	temp =(char * ) realloc ( fazan, ( strlen(fazan) + strlen(buffer) + 2) * sizeof(char));
	if (temp == NULL)
	{
	printf("eroare");
	free(fazan);
	exit(EXIT_FAILURE);
	}
	fazan = temp;
	strcpy(fazan, "-");
	strcpy(fazan, buffer);
 
 
 
}
 
 
printf("Fazanul: %s\n", fazan);
 
free(fazan);
 
 
return 0;
}
