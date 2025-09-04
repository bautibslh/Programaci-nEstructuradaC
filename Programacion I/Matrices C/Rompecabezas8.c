#include <stdio.h>
#include <stdlib.h>
#define FILA 3
#define COLUMNAS 3

void MostrarTablero(int[][COLUMNAS],int,int);
int haGanado(int[][COLUMNAS],int,int);
void MoverNum(int[][COLUMNAS],int,int,int);
int main()
{
    int tablero[FILA][COLUMNAS]={
                                 {8,4,3},
                                 {7,0,6},
                                 {2,1,5}
                                 };
    int movimientos=0;
    int numero;

    MostrarTablero(tablero,FILA,COLUMNAS);

    while(haGanado(tablero,FILA,COLUMNAS)==0)
    {
        do{
            printf ("Que numero desea mover?\n");
            scanf("%d",&numero);
        }while (numero<1||numero>8);

        MoverNum(tablero,FILA,COLUMNAS,numero);
        system("cls");
        MostrarTablero(tablero,FILA,COLUMNAS);
        movimientos++;
    }


    printf("GANASTE! SOLO TARDASTE %d MOVIMIENTOS\n",movimientos);

    return 0;
}

void MostrarTablero(int m[][COLUMNAS],int cf,int cc)
{
    int f,c;
    printf("\nTablero\n");
    for(f=0;f<cf;f++)
    {
        for(c=0;c<cc;c++)
        {
            if(m[f][c]==0)
            {
                printf ("  ");
            }
            else
                printf("%2d",m[f][c]);
        }
        printf("\n");
    }

}

int haGanado(int m[][COLUMNAS],int cf,int cc)
{
    int f,c,num=1,cond=0;
    for(f=0;f<cf;f++)
    {
        for (c=0;c<cc;c++)
        {
            if (m[f][c]==num)
            {
                num++;
            }
        }
    }
    if(num==9)
    {
        cond=1;
    }
    return cond;
}

void MoverNum(int m[][COLUMNAS],int cf,int cc,int n)
{
    int f,c,filN,colN,filV,colV,temporal;

    for (f=0;f<cf;f++)
    {
        for (c=0;c<cc;c++)
        {
            if(m[f][c]==n)
            {
                filN=f;
                colN=c;
            }
            else if (m[f][c]==0)
            {
                filV=f;
                colV=c;
            }
        }
    }

    if(((filN == filV) && (colN == colV-1||colN == colV +1))||
        ((colN == colV) && (filN == filV-1||filN == filV +1)))
    {
        temporal=m[filV][colV];
        m[filV][colV]= m[filN][colN];
        m[filN][colN]= temporal;
    }
}


