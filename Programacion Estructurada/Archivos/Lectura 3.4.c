#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANT 100
typedef struct {
            int cod;
            float prec;
            char desc[51];
}T_Product;

int main()
{
    T_Product prod;
    FILE*pf;
    pf=fopen("Precios_actualizados.dat","rb");
    if(pf==NULL)
        exit(1);
    //fread(&prod,sizeof prod,1,pf);
    while(fread(&prod,sizeof prod,1,pf))
    {
        printf("cod %d\nprecio %.2f\ndesc %s\n",prod.cod,prod.prec,prod.desc);
        fread(&prod,sizeof prod,1,pf);
    }
    fclose(pf);
    return 0;
}
