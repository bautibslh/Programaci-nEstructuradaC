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
    tVentas ven[6]={{"aaa1","Bautista Castagnaro",'T',30,30000},
                    {"bba2","Pedro Sanchez",'B',5,10000},
                    {"abc3","Lucasjack",'H',7,12222},
                    {"rta3","Bisicletaa",'E',10,9000},
                    {"alo0","Marcelo",'E',12,13000},
                    {"tro2","Salame",'T',10,14300}
    };
    pf=fopen("ventas.dat","wb");
    if(pf==NULL)
        exit(1);
    for(int i=0;i<6;i++)
        fwrite(&ven[i],sizeof(tVentas),1,pf);
    fclose(pf);
    return 0;
}
