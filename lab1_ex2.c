#include <stdio.h>
#include <stdlib.h>

int main()
{
   /*Aplicația 8.8: Se citesc numerele m,n,p fiecare mai mici decat 10, apoi se citesc matricile a[m][n] și b[n][p]. Se
cere să se calculeze matricea „c” care rezultă din înmulțirea matricilor a cu b și să se afișeze.
*/

int m,n,p, a[10][10],b[10][10], c[10][10];
scanf("%d%d%d",&m,&n,&p);

for( int i=0; i<m; i++)
    for( int j=0; j<n; j++)
        scanf("%d", &a[i][j]);

for( int i=0; i<n; i++)
    for( int j=0; j<p; j++)
        scanf("%d", &b[i][j]);

for( int i=0; i<m; i++)
{
    for( int j=0; j<n; j++)
        printf("%d    ", a[i][j]);
        printf("\n");
}
        
printf("\n");

for( int i=0; i<n; i++)
{
    for( int j=0; j<p; j++)
        printf("%d   ", b[i][j]);
    printf("\n");
}

for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            c[i][j] = 0;
            for (int k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
printf("\n\n");
for( int i=0; i<m; i++)
{
    for( int j=0; j<p; j++)
        printf("%d   ", c[i][j]);
    printf("\n");
}
        
        
    return 0;
}
