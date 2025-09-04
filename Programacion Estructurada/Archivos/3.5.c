/*HOJA DE RUTA
-Crear struct producto
-Abrir archivo stock lectura
-Ingresar por teclado la actualizacion del prod
-Crear struct Faltantes
-Si se queda sin stock abrir un archivo y grabar
-Cerrar los archivos
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANT 10

typedef struct {
                int cod;
                char desc[51];
                int stock;
}tProducto;
typedef struct {
                int cod;
                int cant;
}tFaltantes;
int existeCod(tProducto[],tFaltantes,int);
int main()
{
    int i;
    tProducto producto[CANT];
    tFaltantes faltante;
    FILE*pf;
    FILE*arch;
    pf=fopen("STOCK.dat","rb");
    if(pf==NULL)
    {
        printf("Error al abrir el archivo\n");
        system("pause");
        exit(1);
    }
    for(i=0;i<CANT;i++)
    {
        fread(&producto[i],sizeof(tProducto),1,pf); //ABRO Y CARGO UN VECTOR CON LOS 10 PRODUCTOS
    }
    fclose(pf);

    arch=fopen("FALTANTES.dat","wb");
    if(arch==NULL)
    {
        printf("Error al abrir el archivo\n");
        system("pause");
        exit(1);
    }
    printf("Codigo de producto a vender - 0 para terminar\n");
    scanf("%d",&faltante.cod);

    while(faltante.cod!=0)
    {
        printf("Cantidad a comprar\n");
        scanf("%d",&faltante.cant);

        for(i=0;i<CANT;i++)
        {
            if(producto[i].cod==faltante.cod)
            {
                if(producto[i].stock>=faltante.cant)
                {
                    producto[i].stock-=faltante.cant;
                }
                else if(producto[i].stock<faltante.cant)
                {
                    faltante.cant=faltante.cant-producto[i].stock;
                    producto[i].stock=0;
                    fwrite(&faltante,sizeof(faltante),1,arch);
                }
                /*else if(producto[i].stock==0)
                {
                    faltante.cant+=faltante.cant;
                    fwrite(&faltante,sizeof(faltante),1,arch);
                }*/
            }
        }
        printf("Codigo de producto a vender - 0 para terminar\n");
        scanf("%d",&faltante.cod);

    }
    fclose(pf);
    fclose(arch);
    system("pause");
    return 0;
}



