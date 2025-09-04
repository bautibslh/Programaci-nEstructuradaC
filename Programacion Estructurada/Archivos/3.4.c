#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANT 100
typedef struct {
            int cod;
            float prec;
            char desc[51];
}T_Product;


int main ()
{
    T_Product producto;
    int i=0,tam;
    float porcentaje;
    FILE*pf;
    FILE*arch;
    pf=fopen("PRECIOS.dat","rb");
    if(pf==NULL)
    {
        printf("Error al abrir el archivo\n");
        system("pause");
        exit(1);
    }
    arch=fopen("Precios_actualizados.dat","wb");
    if(arch==NULL)
    {
        printf("Error al abrir el archivo\n");
        system("pause");
        exit(1);
    }

    printf("Ingrese el porcentaje a aumentar\n");
    scanf("%f",&porcentaje);

    fread(&producto,sizeof producto,1,pf);
    while(!feof(pf))
    {
        producto.prec+=producto.prec*(porcentaje/100.);
        fwrite(&producto,sizeof producto,1,arch);
        fread(&producto,sizeof producto,1,pf);
    }
    fclose(arch);
    fclose(pf);

    return 0;
}
