#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*Aplicația 5.2: Scrieți un program care copiază conținutul unui fișier sursă într-un fișier destinație. Numele fișierelor se citesc din linia de comandă. Pentru eficiența copierii, programul va citi câte un bloc de maxim 4096 de octeți, pe care îl va scrie în destinație.
Exemplu: ./copiere src.dat dst.dat                    -> copiază src.dat în dst.dat
*/



int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Programul nu este apelat corect.\n");
        exit(-1);
    }

    char src[20], dst[20];
    strcpy(src, argv[1]);
    strcpy(dst, argv[2]);

    FILE *f, *g;
    f = fopen(src, "rb");
    g = fopen(dst, "wb");

    if (f == NULL || g == NULL) {
        printf("Nu s-au putut deschide fisierele.\n");
        exit(-1);
    }

    char buffer[4096];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, sizeof(char), sizeof(buffer), f)) > 0) {
        fwrite(buffer, sizeof(char), bytesRead, g);
    }

    fclose(f);
    fclose(g);

    return 0;
}
