#include <stdio.h>
/*
Realizar una función que reciba 3 números enteros correspondientes al día, mes y año de una fecha y valide si la misma es correcta.
 En caso de que la fecha es correcta debe retornar un 1 y si es incorrecta debe retornar un 0.
 Para la validación usar la función del punto 8 que retorna la cantidad de días de un mes.
*/
int CantDias (int,int);
int esFechaValida (int,int,int);
int main()
{
    int d,m,a,error=0;

    do{
        if (error==1)
        {
            printf ("Error fecha invalida\n");
        }
        error=0;
        printf ("Ingrese una fecha en formato dd/mm/aa\n");
        scanf ("%d%d%d",&d,&m,&a);
        error=1;
    }while (esFechaValida(d,m,a)!=1);

    printf ("La fecha %d/%d/%d es valida\n",d,m,a);

    return 0;
}

int CantDias(int m, int a)
{
    int d;
    if (m==2)
    {
        if (a%4==0 && a%100!=0 || a%400==0)
        {
            d=29;
        }
        else
        {
            d=28;
        }
    }
    else if (m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
    {
        d=31;
    }
    else
    {
        d=30;
    }
    return d;
}
int esFechaValida(int d,int m,int a)
{
    int r=0,cDias;

    if (m>=1&&m<=12 && a>=1582 && a<=2100 && CantDias(m,a)>=d)
    {
        r=1;
    }
    //cDias=CantDias(m,a);
    //printf ("r vale:%d\nY cant dias: %d\n",r,cDias);
    return r;
}
