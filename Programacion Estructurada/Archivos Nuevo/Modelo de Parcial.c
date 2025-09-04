#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char vend[5];
    char nomb[31];
    char sec;
    int porc;
    float com;
} tVentas;

typedef struct {
    char vend[5];
    char sec;
    float impor;
} tError;

int busqueda(FILE*, tError, tVentas*);

int main() {
    FILE *pf, *arch;
    tVentas vent;
    tError err;

    pf = fopen("ventas.dat", "r+b");
    arch = fopen("errores.dat", "ab");
    if (pf == NULL || arch == NULL) {
        printf("Error al abrir los archivos\n");
        exit(1);
    }

    printf("Ingrese vendedor\n");
    fgets(err.vend, sizeof(err.vend), stdin);
    err.vend[strcspn(err.vend, "\n")] = 0;  // Remove newline character

    while (strcmpi(err.vend, "FFFF") != 0) {
        do {
            printf("Ingrese sector\n");
            scanf(" %c", &err.sec);  // Note the space before %c to consume any whitespace
            err.sec = toupper(err.sec);
        } while (!(err.sec == 'E' || err.sec == 'T' || err.sec == 'H' || err.sec == 'B'));

        do {
            printf("Ingrese importe\n");
            scanf("%f", &err.impor);
        } while (err.impor < 0);

        if (busqueda(pf, err, &vent)) {
            vent.com = err.impor * (vent.porc / 100.0);
            vent.sec = err.sec;

            fseek(pf, -sizeof(vent), SEEK_CUR);
            fwrite(&vent, sizeof(vent), 1, pf);
        } else {
            fwrite(&err, sizeof(err), 1, arch);
        }

        printf("Ingrese vendedor\n");
        getchar();  // To consume the newline character left by previous scanf
        fgets(err.vend, sizeof(err.vend), stdin);
        err.vend[strcspn(err.vend, "\n")] = 0;  // Remove newline character
    }

    fclose(pf);
    fclose(arch);
    return 0;
}

int busqueda(FILE *pf, tError er, tVentas *aux) {
    rewind(pf);
    int encontrado = 0;

    while (fread(aux, sizeof(*aux), 1, pf) && !encontrado) {
        if (strcmpi(er.vend, aux->vend) == 0) {
            encontrado = 1;
        }
    }

    return encontrado;
}
