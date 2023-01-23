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
 
char *hex2text(const char *hexstring)
{
	int len = strlen(hexstring);
	char hex[1]={0};
 
 
	char string[2]="";
	char *rezultat=NULL;
	char *temp=NULL;
 
	hex[0]= hexstring[0];
	hex[1]= hexstring[1];
	printf("hex: %s\n", hex);
 
	int ascii_code = (int)strtol(hex, NULL, 16);
	char c = (char)ascii_code;
	sprintf(string,"%c", c);
 
 
	if( (temp = realloc( rezultat, sizeof(rezultat)+ sizeof( char))) == NULL)
	{
		perror("eroare alocare memorie");
		free( rezultat);
		exit(EXIT_FAILURE);
	}	
 
	rezultat= temp;
	strcpy( rezultat, string);	
 
 
	hex[0]= 0;
	hex[1]= 0;
 
 
	for( int i=3; i< len; i+=2 ) 
	{
		hex[0]= hexstring[i];
		hex[1]= hexstring[i+1];
		printf("hex: %s\n", hex);
 
		int ascii_code = (int)strtol(hex, NULL, 16);
		char c = (char)ascii_code;
		sprintf(string,"%c", c);
 
 
		if( (temp = realloc( rezultat, sizeof(rezultat)+ sizeof( char))) == NULL)
		{
			perror("eroare alocare memorie");
			free( rezultat);
			exit(EXIT_FAILURE);
		}	
 
		rezultat= temp;
		strcat( rezultat, string);	
 
 
		hex[0]= 0;
		hex[1]= 0;
 
	}
	printf("\nrezultat: %s\n", rezultat);
 
	return rezultat;
 
 
}
 
 
int main()
{
/*Să se scrie o funcție care primește ca argument un string ce conține în format text valori în hexazecimal pe două cifre hexazecimale fără prefixul 0x. Aceste valori reprezintă caractere conform tabelei ASCII. Funcția va decodifica textul și il va returna într-un string alocat dinamic. Antetul funcției poate fi următorul:
char *hex2text(const char *hexstring);
Exemplu: hexstring = "616263" -> funcția va returna string-ul "abc"
 
Această problemă reprezintă inversa funcției dezvoltate la problema anterioară.
 
Pentru testare se pot folosi datele din fisierul ce se poate descarca prin comanda urmatoare
 
wget http://staff.cs.upt.ro/~valy/pt/hexlines.txt
Se recomanda ca citirea datelor sa se faca prin redirectarea intrarii standard.
*/
 
char hexstring[100];
char *rezultat;
 
scanf("%s", hexstring);
 
rezultat=hex2text(hexstring);
 
free(rezultat);
 
 
 
return 0;
}
