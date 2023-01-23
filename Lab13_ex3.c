#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define LINE_SIZE 1000

typedef struct 
{
	char judet[30];
	int beneficiari_platiti;
	int suma_totala;
}indemnizatii;

/*Se consideră un fișier csv (comma separated values) în care pe fiecare linie se află mai multe câmpuri separate prin semnul punct-virgulă. 
Fișierul conține informații statistice oferite de Institutul National de Statistica prin platforma OpenData a Guvernului Romaniei 
(https://data.gov.ro/) despre plata indemnizațiilor de creșterea copilului pe o anumită lună din anul 2021. Fișierul are următorul
cap de tabel ce descrie câmpurile din liniile conținue
Judet;Populatie;Beneficiari plãtiti;Beneficiari suspendati la sfârsit de lunã;Suma totalã plãtitã drepturi curente;Alte plãþi
Programul va citi acest fișier folosind funcțiile dedicate pentru citirea fișierelor text, va extrage câmpurile judet, beneficiari 
platiti si suma total platita drepturi curente, si va stoca datele într-un tablou alocat dinamic, de structuri de date corespunzătoare,
de dimensiune minimă necesară. Se cere să se implementeze tipuri de date utilizator. Se va implementa de asemenea o funcție de sortate dupa
judet și o funcție de sortare după suma totala platita drepturi curente. Programul va scrie în fișierul rezultat.txt pe câte un rând diferit 
judetul cu cea mai mare populatie, judetul cu cea mai mare suma din câmpul alte plati.

Fișierul se poate descărca folosind următoarea comandă:

wget http://staff.cs.upt.ro/~valy/pt/indemnizatie.csv*/


void process_line(char *line, indemnizatii *array)
{	
	char *word;
	//judet
	word=strtok( line,";");
	strcpy(array->judet, word);
	printf("%s - ",array->judet);
	
	//populatie
	word= strtok( NULL, ";");
	
	//Beneficiari platiti
	word= strtok( NULL, ";");
	int numar_beneficiari= atoi( word);
	printf("%d - ", numar_beneficiari);
	array->beneficiari_platiti= numar_beneficiari;
	
	//Beneficiari suspendaþi la sfârºit de lunã
	word= strtok( NULL, ";");
	
	//Suma totalã plãtitã drepturi curente
	word= strtok( NULL, ";");
	int suma= atoi( word);
	array->suma_totala=suma;
	printf("%d \n ", suma);
	
	
}

int main()
{  
     FILE *f;
     char line[LINE_SIZE];
     indemnizatii *array=NULL;
     indemnizatii *temp;
     int index=0;
     
     
     // deschidere fisier cu verificare
	 if( ( f= fopen( "indemnizatie.csv", "r") ) == NULL)
	 {
	 	perror("ERROR: ");
		exit(1);
	 }
	
	//citire antet
	if (fgets(line, 1000, f) == NULL)
	{
	  perror(NULL);
	  exit(3);
	}


	while (fgets(line, 1000, f) != NULL)
	{
		 if( ( temp =(indemnizatii *)realloc( array, (index+1)*sizeof(indemnizatii))) == NULL)
		 {
		 	fprintf(stderr,"%s", "eroare de alocare memorie");
		 	free(array);
		 	exit( EXIT_FAILURE);
		 }
		 
		 array= temp;
		 process_line(line, &array[index]);
		 
		 
		 index++;
    }

	free(array);
	
	fclose(f);
     
    
    
     
     
     
     
 return 0;
}
