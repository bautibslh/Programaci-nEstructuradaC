#include <stdio.h>
#include <stdlib.h>
#define CAND 1000
#define SEDE 15
void Carga(int[][SEDE],int,int);
void Muestra(int[][SEDE],int,int);
int main()
{
    int mat[CAND][SEDE]={{0}};
    Carga(mat,CAND,SEDE);
    Muestra(mat,CAND,SEDE);
    return 0;
}

void Carga(int m[][SEDE],int f,int c)
{
    int nl,s,vot,i=0;
    do{
        printf("NUMERO DE LISTA (0 para terminar)\n");
        scanf("%d",&nl);
    }while(nl<100||nl>999);

    while (nl!=0)
    {
        do{
            printf("NUMERO DE SEDE\n");
            scanf("%d",&s);
        }while (s<1||s>15);
        do{
            printf("CANTIDAD DE VOTOS\n");
            scanf("%d",&vot);
        }while (vot<0);
        m[nl-1][s-1]+=vot;
        do{
            printf("NUMERO DE LISTA (0 para terminar)\n");
            scanf("%d",&nl);
        }while(!(nl>=100&&nl<=999||nl==0));
    }
}

void Muestra(int m[][SEDE],int f,int c)
{
    int i,j;
    printf("\nCANTIDAD DE VOTOS DE CADA LISTA POR SEDE\n");
    printf("              ");
    for(i=0;i<c;i++)
    printf("SEDE %d ",i+1);
    printf("\n");
    for(i=100;i<f;i++)
    {

        for(j=0;j<c;j++)
        {
            if(m[i][j]>0)
            {
                printf("Lista %d: %3d\n",i,m[i][j]);
            }
            else
                printf("                 ");
        }
    }
}
