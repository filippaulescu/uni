char *string_replace_dynamic(const char *where, const char *what, const char *replace)
{
 
	//printf("%s\n%s\n%s\n", where, what, replace);
	char *rezultat=NULL;
	char *temp;	
	char *where_aux;
	if ( (where_aux=(char *) malloc(strlen(where) + 1)) == NULL)
	{
		printf("eroare de alocare memorie");
		exit(EXIT_FAILURE);
	}
 
	strcpy(where_aux, where);
 
	char *word = strtok( where_aux, " ,.-:");
 
	while( word ) 
	{
 
		printf( " %s\n", word );
		if( strcmp( word, what) == 0 ) 
   		{
   			if ( (temp=(char *)realloc(rezultat,(strlen(replace) + 2)*sizeof(char))) == NULL)
				{
					printf("eroare de alocare memorie");
					free(rezultat);
					exit(EXIT_FAILURE);
				}
			rezultat=temp;
			strcat( rezultat, " ");
			strcat( rezultat, replace);
   		}
   		printf("REZULTAT:%s\n", rezultat);
 
   		word = strtok(NULL," ,.-:" );
	}
	free( rezultat);
	return 0;
}


int main()
{
/*Sa se scrie o functie cu urmatorul antent
char *string_replace_dynamic(const char *where, const char *what, const char *replace)
Functia inlocuieste fiecare aparitie a string-ului what in string-ul where cu string-ul replace. Funcția va returna noul string obținut, alocat dinamic,
și NULL în caz de eroare sau în cazul în care string-ul what nu apare în string-ul where.

char s1[] = "Acesta este un string si un string este terminat cu 0x00";
char s2[] = "string";
char s3[] = "sir de caractere";
char *p = string_replace(s1, s2, s3);
p devine un string alocat dinamic cu urmatorul continut: "Acesta este un sir de caractere si un sir de caractere este terminat cu 0x00";
s1, s2, s3 - raman neschimbate
r = 2*/
//NEFUNCTIONAL!!
  
  
char s1[] = "Acesta este un string si un string este terminat cu 0x00";
char s2[] = "string";
char s3[] = "sir de caractere";
char *p = string_replace_dynamic(s1, s2, s3);
  
  
}
