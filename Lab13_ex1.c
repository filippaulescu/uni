#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
 
#define TITLE_SIZE 100
#define LINE_SIZE 1000
#define STEP 16
 
typedef struct
{
  char titlu[TITLE_SIZE + 1];
  uint16_t an;
  uint32_t buget;
}FILM;
 
void printFilm(const FILM *film)
{
  printf ("%s (%d) - %d\n", film->titlu, film->an, film->buget);
}
 
// 0 - OK
// != 0 - error
uint8_t procesareLinie(char *linie, FILM *e)
{
  char *p;
  /*
  if ((p = strtok(linie, ",")) == NULL)
    {
      return 1;
    }
  e->an = strtol(p, NULL, 10);
 
  if ((p = strtok(NULL, ",")) == NULL)
    {
      return 1;
    }
 
  if ((p = strtok(NULL, ",")) == NULL)
    {
      return 1;
    }
  memset(e->titlu, 0, TITLE_SIZE + 1);
  strncpy(e->titlu, p, TITLE_SIZE);
 
  if ((p = strtok(NULL, ",")) == NULL)
    {
      return 1;
    }
  if ((p = strtok(NULL, ",")) == NULL)
    {
      return 1;
    }
  if ((p = strtok(NULL, ",")) == NULL)
    {
      return 1;
    }
  if ((p = strtok(NULL, ",")) == NULL)
    {
      return 1;
    }
  if ((p = strtok(NULL, ",")) == NULL)
    {
      return 1;
    }
  e->buget = strtol(p, NULL, 10);
  */
 
  if ((p = strtok(linie, ",")) == NULL)
    {
      return 1;
    }
  for (int i = 0; i < 8; i++ )
    {
      switch (i)
	{
	case 0:
	  {
	    e->an = strtol(p, NULL, 10);
	    break;
	  }
	case 2:
	  {
	    memset(e->titlu, 0, TITLE_SIZE + 1);
	    strncpy(e->titlu, p, TITLE_SIZE);
	    break;
	  }
	case 7:
	  {
	    e->buget = strtol(p, NULL, 10);
	    break;
	  }	  
	}
      if ((p = strtok(NULL, ",")) == NULL)
	{
	  return 1;
	}
    }
  return 0;
}
 
void printFilme(FILM *a, int size)
{
  for (int i = 0; i < size; i++)
    {
      printFilm(&a[i]);
    }
}
 
FILM* adaugareElement(FILM *array, FILM *e, int *size)
{
  int index = 0;
  static int current_size = 0;
  index = *size;
  if (index == current_size)
    {
      current_size += STEP;
      if ((array = realloc(array, current_size * sizeof(FILM))) == NULL)
	{
	  perror(NULL);
	  exit(3);
	}
      if (index == 20)
	{
	  //	  array = NULL;
	}
    }
  array[index++] = *e;
  *size = index;
  return array;
}
/*
Se consideră un fișier csv (comma separated values) în care pe fiecare linie se află mai multe câmpuri separate prin virgulă. Fișierul conține informații despre
filme. Pe fiecare linie se află câte o inregistrare ce reprezintă un film cu date despre acesta, date ce sunt separate prin virgulă. O linie are următoarea
configurație (cap de tabel)
year,imdb,title,test,clean_test,binary,budget,domgross,intgross,code,budget_2013$,domgross_2013$,intgross_2013$,period code,decade code
Se va citi acest fișier în mod optim. Pentru fiecare înregistrare se vor extrage următoarele date: titlu, an, buget (title, year, budget). Se va proiecte 
și implementa o structură de date corespunzătoare. Se vor stoca aceste date intr-un tablou alocat dinamic. Se precizează că se consideră necunoscută
dimensiunea fișierului ( a numărului de linii) - se va aloca minimul de memorie necesar pentru a stoca toate informațiile. Programul va scrie în fișierul 
out1.txt toate filmele sortate după anul apariției, în fișierul out2.txt toate filmele sortate după titlu iar în fișierul out3.txt toate filmele sortate după buget.

Fișierul de test poate fi descărcat folosind urmatoarea comandă:

wget http://staff.cs.upt.ro/~valy/pt/movies.csv
Se vor realiza mai multe variante de procesare si extragere de informații dintr-o linie de date: folosind strtok, folosind strchr, agloritm propriu prin
parcurgere caracter cu caracter a unei linii deja citite din fișier.
*/
//FACUT DE STANGACIU!!!!!


int main(int argc, char **argv)
{
  if (argc != 2)
    {
      fprintf(stderr, "Utilziare incorecta\n");
      exit(1);
    }
 
  FILE *f;
  char line[LINE_SIZE];
  FILM *array = NULL;
 
  int index = 0;
  if ((f = fopen(argv[1], "r")) == NULL)
    {
      perror(argv[1]);
      exit(2);
    }
  if (fgets(line, 1000, f) == NULL)
    {
      perror(NULL);
      exit(3);
    }
  FILM aux;
  while (fgets(line, 1000, f) != NULL)
    {
      if (procesareLinie(line, &aux) == 0)
	{
	  array = adaugareElement(array, &aux, &index);
	}
    }
 if ((array = realloc(array, index * sizeof(FILM))) == NULL)
   {
     perror(NULL);
     exit(3);
   }
 printFilme(array, index);
 
 if (fclose(f) != 0)
   {
     perror(NULL);
     exit(2);
   }
 free(array);
 return 0;
}
