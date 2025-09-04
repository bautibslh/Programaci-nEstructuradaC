#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
                char vend[5];
                char nomb[31];
                char sec;
                int porc;
                float com;
}tVentas;
int main()
{
    FILE *pf;
    tVentas ven;
    pf=fopen("ventas.dat","rb");
    if(pf==NULL)
        exit(1);
    fread(&ven,sizeof(ven),1,pf);
    while(!feof(pf))
    {
        printf("\n%s\n%s\n%c\n%d\n%.2f\n",ven.vend,ven.nomb,ven.sec,ven.porc,ven.com);
        fread(&ven,sizeof(ven),1,pf);

    }
    fclose(pf);
    return 0;
}
