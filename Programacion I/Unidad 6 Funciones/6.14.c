#include <stdio.h>
int CantDias(int,int);
int esFechaValida(int,int,int);
int CalculaEdad (int,int,int,int,int,int);
int main ()
{
    int d,m,a,dN,mN,aN,error=0,error_2=0,edad;
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

    do{
        if (error_2=0)
        {
            printf ("Error fecha invalida, intente de nuevo\n");
        }
        error_2=0;
        printf ("Ingrese su fecha de nacimiento (dd/mm/aaaa)\n");
        scanf ("%d%d%d",&dN,&mN,&aN);
        error_2=1;
    }while (esFechaValida(dN,mN,aN)!=1);

    edad=CalculaEdad(d,m,a,dN,mN,aN);

    printf ("Tu edad es: %d\n",edad);
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
int CalculaEdad(int d,int m,int a,int dN,int mN,int aN)
{
    int e;

    e=a-aN;

    if (m<mN)
    {
        e-=1;
    }

    if(m=mN)
    {
        if (d<dN)
        {
            e-=1;
        }
    }


    return e;
}
