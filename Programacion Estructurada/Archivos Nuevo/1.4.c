/*1.4 Se ingresan DNI y nota de un parcial de los alumnos de un curso. El ingreso de datos finaliza con un DNI
negativo. Se sabe que como máximo pueden presentarse a rendir 60 alumnos. Tenga en cuenta que no
pueden existir 2 o más alumnos con el mismo DNI.
Mostrar el Listado de alumnos con su correspondiente DNI y la nota obtenida (en forma de listado), ordenado
de mayor a menor por nota.*/
#include <stdio.h>
#include <stdlib.h>
#define TAM 60
int estaRepetido(int[],int,int);
void cargaVectores (int[],int[],int);
void ordenaMm(int[],int[],int);
void mostrarListado (int[],int[],int);
int estaEnRango(int,int,int);

int main()
{
    int vN[TAM],vD[TAM]={0};
    cargaVectores(vN,vD,TAM);
    ordenaMm(vN,vD,TAM);
    system("cls");
    mostrarListado(vN,vD,TAM);

    return 0;
}

int estaRepetido(int v[],int ce,int dato)
{
    int i,pos=-1;
    for(i=0;i<ce;i++)
    {
        if(v[i]==dato)
        {
            pos=i;
        }
    }
    return pos;
}

int estaEnRango(int li,int ls,int d)
{
    int r=0;
    if(d>=li && d<=ls)
        r=1;
    return r;
}
void cargaVectores(int vn[],int vd[],int ce)
{
    int i=0,dni,nota;
    do{
        printf("Ingrese DNI del alumno\n");
        scanf("%d",&dni);
    }while(estaRepetido(vd,ce,dni)!=-1);

    while(i<ce && dni>0)
    {
        do{
            printf("Ingrese nota del alumno\n");
            scanf("%d",&nota);
        }while(estaEnRango(1,10,nota)!=1);

        vn[i]=nota;
        vd[i]=dni;

        i++;
        system("cls");
        do{
            printf("Ingrese DNI del alumno\n");
            scanf("%d",&dni);
        }while(estaRepetido(vd,ce,dni)!=-1);
    }
}

void ordenaMm(int vn[],int vd[],int ce)
{
    int i,j,aux;

    for(i=0;i<ce-1;i++)
    {
        for(j=0;j<ce-1-i;j++)
        {
            if(vn[j]<=vn[j+1])
            {
                aux=vn[j];
                vn[j]=vn[j+1];
                vn[j+1]=aux;

                aux=vd[j];
                vd[j]=vd[j+1];
                vd[j+1]=aux;
            }
        }
    }
}

void mostrarListado(int vn[],int vd[],int ce)
{
    int i;
    printf("DNI     \tNOTA\n");
    for(i=0;i<ce;i++)
    {
        if(vd[i]!=0)
            printf("%d\t%4d\n",vd[i],vn[i]);
    }
}
