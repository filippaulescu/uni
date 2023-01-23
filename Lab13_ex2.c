#include <stdio.h>
#include <stdlib.h>

/*Se citesc de la tastatură maxim 100 numere reale, până la întâlnirea numărului 0. Să se sorteze aceste numere și să se scrie într-un fișier, toate numerele fiind pe o singură linie, separate prin | (bară verticală).*/


int main()
{ 
	FILE *f;
	int numar;

	if((f=fopen("out.txt","w"))==NULL)
	{
        printf("eroare deschidere fisier\n");
        exit(EXIT_FAILURE);
    }
    
    scanf("%d" , &numar);
    fprintf( f,"%d", numar);
    
   
    for(;;)
    {
    	scanf("%d" , &numar);
    	if( !numar) 
    		break;
    	
    	fprintf( f,"%s","|");
    	fprintf( f,"%d", numar);
    	
    }
       
     fclose(f);
     
     
     
 return 0;
}
