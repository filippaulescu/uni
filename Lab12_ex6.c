#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 
char *functie( char *string)
{
	int len = strlen(string);
	int c1=0, c2=0;
	char ch1, ch2;
	char char_hex[2];
 
	char *rezultat=NULL;
	char *temp=NULL;
 
	for( int i=0; i< len; i++ ) 
	{
		c1= string[i] / 16;
		c2= string[i] % 16;
		ch1= '0' + c1;
		if ( c2 < 10 ) 
			ch2 = '0' + c2;
		else
			ch2 = 'A' + ( c2 - 10) ;
 
		char_hex[0]= ch1;
		char_hex[1]= ch2;
 
		if( (temp=(char *)realloc( rezultat, sizeof(char)*(i+3) )) == NULL)
		{
			perror("Eroare alocare memorie");
			free(rezultat);
			exit(EXIT_FAILURE);
		}
 
		rezultat=temp;
 
		strcat( rezultat, char_hex);
 
	}
 
 
	return rezultat;
 
}
 
 
 
int main()
{
/*Să se scrie o funcție care primește ca argument un string și returnează un alt string alocat dinamic în care fiecare caracter din string-ul inițial va fi înlocuit cu valoarea în hexazecimal a caracterului conform tabelei ASCII în format text pe strict două cifre hexazecimale fără prefixul 0x. Antetul funcției poate fi următorul
 
char *text2hex(const char *string);
Exemplu: string = "abc" -> funcția va returna un string de forma "616263"
NOTA: valgrind returneaza o eroare, dar nu are memory leaks,  ns daca e ok sau nu
*/
 
char string[100];
char *rezultat;
 
scanf("%s", string);
rezultat=functie(string);
printf("%s", rezultat);
free(rezultat);
 
 
 
return 0;
}
