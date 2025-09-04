#include <stdio.h>
#include <stdlib.h>

int Cuadrante (int,int);
int Puntaje (int,int,int,int,int);

int main ()
{
    int id,i,x,y,cuad,puntaje,cont1=0,cont2=0,cont3=0,cont4=0,cont0=0,contCentro=0,total,pMax=0,idMax=0;

    printf ("/////////////////////////////////\n");
    printf ("Ingrese el numero de participante: \n");
    scanf ("%d",&id);

    while (id>=0)
    {
        cont1=0;
        cont2=0;
        cont3=0;
        cont4=0;
        cont0=0;
        for (i=1;i<=5;i++)
        {
            do{
                printf ("Ingrese las coordenadas del disparo %d (X-Y)\n",i);
                scanf ("%d%d",&x,&y);
            }while (x!=0 && y==0 || x==0 && y!=0);

            cuad=Cuadrante(x,y);

            if (cuad==0)
            {
                cont0++;
                contCentro++;
            }
            if (cuad==1)
            {
                cont1++;
            }
            if (cuad==2)
            {
                cont2++;
            }
            if (cuad==3)
            {
                cont3++;
            }
            if (cuad==4)
            {
                cont4++;
            }
        }

        total=Puntaje(cont0,cont1,cont2,cont3,cont4);

        printf ("El puntaje obtenido por el participante %d es: %d\n",id,total);

        if (total>pMax)
        {
            pMax=total;
            idMax=id;
        }
        system ("pause");
        system ("cls");
        printf ("/////////////////////////////////\n");
        printf ("Ingrese el numero de participante: \n");
        scanf ("%d",&id);
    }
    printf ("El ganador es el participante %d\nPUNTOS: %d\n",idMax,pMax);
    printf ("La cantidad de disparos total en el centro es %d\n",contCentro);

    return 0;
}


int Cuadrante (int x, int y)
{
    int nCuad;

    if (x==0 && y==0)
    {
        nCuad=0;
    }
    if (x>0 && y>0)
    {
        nCuad=1;
    }
    if(x>0 && y<0)
    {
        nCuad=4;
    }
    if (x<0 && y>0)
    {
        nCuad=2;
    }
    if (x<0 && y<0)
    {
        nCuad=3;
    }

     return nCuad;
}


int Puntaje (int c,int c1,int c2,int c3,int c4)
{
    int total=0;
    total+=c*100;
    total+=c1*50;
    total+=c2*50;
    total+=c3*40;
    total+=c4*40;

    return total;
}
