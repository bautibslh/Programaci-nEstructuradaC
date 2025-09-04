
#include <stdio.h>
#include <stdlib.h>
typedef struct {
                int cod;
                char desc[51];
                int stock;
                }s_stock;
int main()
{
    FILE *pf;
    s_stock st;
    pf=fopen("STOCK.dat","rb");
    if(pf==NULL)
    {
        printf("ERROR\n");
        exit(1);
    }

    fread(&st,sizeof(st),1,pf);
    while(!feof(pf))
    {
        printf("CODIGO: %d\nDESCRIPCION:%s\nSTOCK:%d\n\n",st.cod,st.desc,st.stock);
        fread(&st,sizeof(st),1,pf);
    }


    return 0;
}
