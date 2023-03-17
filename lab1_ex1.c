#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*Aplicația 8.3: Se citește de la tastatură un număr n<=10 și un număr m<=20. Se cere să se scrie un program care
generează o matrice cu m linii și n coloane în care sunt puse toate numerele de la 1,2,3,...,m*n. Se vor utiliza
pointeri.
*/



int n,m;
scanf("%d%d", &m, &n);
int **a= (int **)malloc( m * sizeof( int*));
for( int i=0; i<m; i++)
{
    *(a+i)=(int *) malloc( n * sizeof(int));
}

int count=0;
for(int i=0; i<m; i++)
    for(int j=0; j<n; j++)
    {
        *(*(a+i)+j)=++count;
    }

 printf("Matricea generata este:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", *(*(a + i) + j));
        }
        printf("\n");
    }

  for (int i = 0; i < m; i++) {
        free(a[i]);
    }
    free(a);

    return 0;
}
