#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define PISO 5
#define DPTO 15
void Carga(int [][DPTO],int,int);
void Muestra(int [][DPTO],int,int);
int main ()
{
    int deudores[PISO][DPTO]={{0}};
    Carga(deudores,PISO,DPTO);
    //Muestra(deudores,PISO,DPTO);

    return 0;
}

void Carga (int m[][DPTO],int p,int d)
{
    int i,j,piso,dep;
    printf ("A CONTINUACION, INDIQUE DPTO Y PISO DE QUIENES HAYAN PAGADO\n");
    do{
        printf ("PISO DEL EDIFICIO\n");
        scanf ("%d",&piso);
    }while (!(piso>=1&&piso<=p||piso==99));

    while (piso!=99)
    {
        do{
            printf("DPTO DEL PISO\n");
            scanf ("%d",&dep);
        }while (dep<1||dep>d);

        m[piso-1][dep-1]=1;

        do{
            printf ("PISO DEL EDIFICIO\n");
            scanf ("%d",&piso);
        }while (!(piso>=1&&piso<=p||piso==99));
    }
    system("cls");
    Muestra(m,p,d);
    printf ("\t\t\t\t\tDEPARTAMENTOS DEUDORES\n");
    printf ("        ");
    for(i=0;i<d;i++)
    {
        printf ("DPTO%2d ",i+1);
    }
    printf ("\n");
    for(i=0;i<p;i++)
    {
        for(j=0;j<d;j++)
        {
            if(j==0)
            {
                printf ("PISO %2d ",i+1);
            }
            if(m[i][j]==0)
            {
                printf ("   X   ");
            }
            else
                printf("       ");
        }
        printf ("\n");
    }
}

void Muestra(int m[][DPTO],int f,int c)
{
    int i,j;
    float acum=0;
    for (i=0;i<f;i++)
    {
        for (j=0;j<c;j++)
        {
            acum+=m[i][j];
        }
    }
    printf ("\t\t\t\t\tTOTAL RECAUDADO %.2f\n",acum*1000);
}
