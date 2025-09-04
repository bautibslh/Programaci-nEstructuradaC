#include <stdio.h>
int CantDias(int,int);
int esFechaValida(int,int,int);
void SumaNDias (int,int,int,int);
int main ()
{
    int d,m,a,error=0,dN,n;
    do{
        if (error==1)
        {
            printf ("Error fecha invalida, intente de nuevo\n");
        }
        error=0;
        printf ("Ingrese una fecha (dd/mm/aaaa)\n");
        scanf ("%d%d%d",&d,&m,&a);
        error=1;
    }while (esFechaValida(d,m,a)!=1);

    printf ("Ingrese la cantidad de dias que desea sumar: \n");
    scanf ("%d",&n);

    SumaNDias(d,m,a,n);

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

void SumaNDias(int d,int m,int a,int n)
{
    int dN;
    dN=d+n;
    while (dN>CantDias(m,a))
    {
        dN=dN-CantDias(m,a);
        m++;
        if(m>12)
        {
            m=1;
            a++;
        }
    }
    printf ("La nueva fecha es: %d/%d/%d\n",dN,m,a);
}
