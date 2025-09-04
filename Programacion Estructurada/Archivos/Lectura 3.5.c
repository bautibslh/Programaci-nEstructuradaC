#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int cod;
    char desc[51];
    int stock;
} tProducto;

typedef struct {
    int cod;
    int cant;
} tFaltantes;

int main() {
    tProducto producto, productos[10];
    tFaltantes faltante;
    FILE *pf, *arch;
    int i;

    pf = fopen("STOCK.dat", "rb");
    if(pf == NULL) {
        printf("Error al abrir archivo\n");
        system("pause");
        exit(1);
    }

   /* for(i = 0; i < 10; i++) {
        fread(&productos[i], sizeof(tProducto), 1, pf);
        printf("COD %d\n%s\nCANT %d\n",productos[i].cod,productos[i].desc,productos[i].stock);
    }
*/
    arch=fopen("FALTANTES.dat","rb");
    if(arch==NULL)
        exit(1);
    fread(&faltante,sizeof(tFaltantes),1,arch);
    while(!feof(arch))
    {
        printf("CODIGO %d\nCANTIDAD %d\n",faltante.cod,faltante.cant);
        fread(&faltante,sizeof(tFaltantes),1,arch);
    }
    fclose(arch);

    fclose(pf);
    system ("pause");
    return 0;
}

