#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 
 
void BubbleSort(int *v, int n)
{
	int s,i,aux;
	do{
		s = 0;                           
		for (i = 1; i < n; i++)
		{      
			if (v[i - 1] < v[i])
			{             
				aux = v[i - 1];                 
				v[i - 1] = v[i];
				v[i] = aux;
				s = 1;                          
			}
		}
	} while (s);                         
}
 
 
void citire()
{
	unsigned int numar;
	int *v=NULL;
	int *temp=NULL;
	int n=0;
 
	for(;;)
	{
		if( (scanf("%d", &numar) == EOF) )
			break;
		n++;
 
		if( ( temp= realloc( v,  (n+1)*sizeof(int))) == NULL ) 
			{
				perror("Eroare alocare dinamica");
				free(v);
				exit(EXIT_FAILURE);
			}
		v= temp;
		v[n] = numar;
 
	}
	BubbleSort( v, n);
	for( int i = 1; i<=n ; i++)
		printf("%d ", v[i]);
 
}
 
 
int main()
{
/* 
5-Se va citi de la intrarea standard un numar neconscut de valor intregi nenule pozitive pana la EOF. Se vor stoca aceste elemente intr-un tablou dinamic. Programul va afisa la iesirea standard tabloul sortat descrescator.
*/

citire();
 
return 0;
}
