#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANT 100
typedef struct {
            int cod;
            float prec;
            char desc[51];
}T_Product;
int posicionDelEntero(T_Product[],int,int);
void ModificaPrecios(T_Product[],int);

int main ()
{
    T_Product product[CANT];
    FILE*pf;
    int i=0,j;                                  //DECLARACION DE VARIABLES


    pf=fopen("PRODUCTOS.dat","rb");           //APERTURA DE ARCHIVO PRODUCTOS.dat
    if (pf==NULL)
    {
        printf("Error al abrir archivo\n");   //COMPROBAR CORRECTA APERTURA DEL ARCHIVO
        system("pause");
        exit(1);
    }

    fread(&product[i],sizeof(T_Product),1,pf);//LECTURA PRIMER REGISTRO, CARGA VECTOR DE ESTRUCTURAS
    while(!feof(pf) && i<CANT)
    {
        i++;
        fread(&product[i],sizeof(T_Product),1,pf);
    }
    fclose(pf);                               //CIERRE DEL ARCHIVO


    ModificaPrecios(product,i);

    pf=fopen("PRODUCTOS.csv","wt");
    if(pf==NULL)
    {
        printf("Error al abrir archivo\n");   //COMPROBAR CORRECTA APERTURA DEL ARCHIVO
        system("pause");
        exit(1);
    }

    for(j=0;j<i;j++)
    {
        //fwrite(&product[j],sizeof(T_Product),1,pf);
        fprintf(pf,"%d;%.2f;%s\n",product[j].cod,product[j].prec,product[j].desc);
    }
    fclose(pf);
    system ("pause");
    return 0;
}
int posicionDelEntero(T_Product vec[],int d,int ce)
{
    int pos=-1,i=0;
    while(i<ce && pos==-1)
    {
        if(d==vec[i].cod)
            pos=i;
        else i++;
    }
    return pos;
}
void ModificaPrecios(T_Product vest[],int ce)
{
    int dato,posic;
    printf("MODIFICAR PRODUCTOS\n");

    printf("Codigo del producto a modificar\n");
    scanf("%d",&dato);

    while(dato!=0)
    {
        if (posicionDelEntero(vest,dato,ce)!=-1)
        {
            posic=(posicionDelEntero(vest,dato,ce));
            printf("Indique nuevo precio\n");
            scanf("%f",&vest[posic].prec);
        }
        else printf("Error no existe codigo, intente de nuevo\n");

        printf("Codigo del producto a modificar\n");
        scanf("%d",&dato);
    }


}
