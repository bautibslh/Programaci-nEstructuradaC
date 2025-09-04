#include <stdio.h>
#include <stdlib.h>
/*Se dispone de un archivo llamado Stock.dat que contiene la información de los productos que vende una
fábrica. En el archivo se guarda:
• Código de artículo (entero)
• Descripción (50 caracteres máximo)
• Stock (entero)
Luego se ingresan por teclado las ventas a realizar indicando:
• Código de artículo
• Cantidad
 La carga por teclado de las ventas finaliza con un código de artículo igual a 0.
Por cada venta se debe controlar si hay stock suficiente y si lo hay, restar el stock de dicho producto, sino
hay stock se debe vender lo que quede disponible y grabar un registro en un archivo Faltantes.dat con la
cantidad que no pudo venderse, dicho registro debe contener:
• Código de artículo
• Cantidad faltante
Si ya hay un registro previo en dicho archivo de faltantes con el mismo producto debe incrementarse la
cantidad.
*/
typedef struct {
                int cod;
                char desc[51];
                int stock;
                }s_stock;
typedef struct{
                int cod;
                int falt;
                }s_faltante;
int main()
{
    s_stock prod;
    s_faltante faltante;
    FILE *pf,*arch;
    int codigo,cant,band=0;
    long registros;
    pf=fopen("Stock.dat","r+b");
    if(pf==NULL)
    {
        printf("Error al leer el archivo\n");
        exit(1);
    }
    arch=fopen("Faltantes.dat","wb");
    if(arch==NULL)
    {
        printf("Error al abrir archivo\n");
        exit(2);
    }

    printf("Ingresa ventas a realizar\nIngrese codigo de articulo\n");
    scanf("%d",&codigo);

    while(codigo!=0)
    {
        printf("Ingrese cantidad a comprar\n");
        scanf("%d",&cant);
        fread(&prod,sizeof(prod),1,pf);
        while(!feof || band==1)
        {
            band=0;
            if(prod.cod==codigo)
            {
                prod.stock-=cant;
                if(prod.stock<0)
                {
                    faltante.falt=prod.stock;
                    faltante.cod=prod.cod;
                    fwrite(&faltante,sizeof(faltante),1,arch);
                    prod.stock=0;
                    band=1;
                }
            }
            fread(&prod,sizeof(prod),1,pf);
        }
        printf("Ingresa ventas a realizar\nIngrese codigo de articulo\n");
        scanf("%d",&codigo);
    }
    fclose(arch);

    fseek(pf,0,SEEK_END);
    registros=ftell(pf)/sizeof(prod);
    rewind(pf);
    for(int i=0;i<registros;i++)
    {
        fwrite(&prod,sizeof(prod),1,pf);
    }
    fclose(pf);
    return 0;
}
