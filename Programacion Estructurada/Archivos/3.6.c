#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANT 10

typedef struct{
        int cod;
        int cant;
}tFaltantes;
int main()
{
    tFaltantes faltante,vFaltante[CANT]={0};

    int i;
    FILE*arch;
    FILE*pf;

    arch=fopen("FALTANTES.dat","rb");
    if(arch==NULL)
        exit(1);
    pf=fopen("faltantes.csv","wt");
    if(pf==NULL)
        exit(1);

    fread(&faltante,sizeof(tFaltantes),1,arch);
    while(!feof(arch))
    {
        vFaltante[faltante.cod-1001].cant+=faltante.cant;
        //vFaltante[faltante.cod-1001].cod=faltante.cod;
        fread(&faltante,sizeof(tFaltantes),1,arch);
    }
    for(i=0;i<CANT;i++)
    {
        vFaltante[i].cod=i+1001;
        fprintf(pf,"CODIGO %d;CANTIDAD %d\n",vFaltante[i].cod,vFaltante[i].cant);
    }
    fclose(arch);
    fclose(pf);


    return 0;
}
