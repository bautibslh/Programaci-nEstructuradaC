/*Se ingresan DNI y nota de un parcial de los alumnos de un curso.
El ingreso de datos finaliza con un DNI
negativo. Se sabe que como máximo pueden presentarse a rendir 60 alumnos.
Tenga en cuenta que no pueden existir 2 o más alumnos con el mismo DNI.
Mostrar el Listado de alumnos con su correspondiente DNI y la nota obtenida
(en forma de listado), ordenado de
mayor a menor por nota.
*/
#include <stdio.h>
#include <stdlib.h>
#define TAM 60
int buscaEnVector(int[],int,int);
int cargaVectores(int[],int [],int);
void ordenaMayorMenor(int[],int[],int);
void mostrarListado(int[],int[],int);
int main ()
{
    int vDni[TAM]={0},vNotas[TAM]={0},cantCargada;
    cantCargada=cargaVectores(vDni,vNotas,TAM);
    ordenaMayorMenor(vDni,vNotas,cantCargada);
    mostrarListado(vDni,vNotas,cantCargada);
    return 0;
}
///////////////////////////////FUNCIONES//////////////////////////////////////
int buscaEnVector(int v[],int dato,int ce)
{
    int i,c,encontro=0;
    for (i=0;i<ce;i++)
    {
        if(dato==v[i])
        {
            encontro=1;
        }
    }
    return encontro;
}

int cargaVectores(int vd[],int vn[],int ce)
{
    int i=0;
    printf ("\n-INGRESO DE DATOS-\n");
    do{
        printf("DNI DEL ALUMNO (negativo para terminar)\n");
        scanf("%d",&vd[i]);
        if(buscaEnVector(vd,vd[i],i)==1)
                printf("Error, intente de nuevo\n");
    }while (buscaEnVector(vd,vd[i],i));

    while (vd[i]>0 && i<ce)
    {
        do{
            printf ("NOTA DEL ALUMNO\n");
            scanf("%d",&vn[i]);
            if(vn[i]<1||vn[i]>10)
                printf("Error, intente de nuevo\n");
        }while (vn[i]<1||vn[i]>10);
        i++;
        system("pause");
        system("cls");
        if(i<ce){
            do{
                printf("DNI DEL ALUMNO (negativo para terminar)\n");
                scanf("%d",&vd[i]);
                if(buscaEnVector(vd,vd[i],i)==1)
                    printf("Error, intente de nuevo\n");
            }while (buscaEnVector(vd,vd[i],i));
        }
    }
    return i;
}

void ordenaMayorMenor(int dni[],int nota[],int ce)
{
    int i,j,mayor,aux;
    //mayor=nota[0];
    for(j=0;j<ce-1;j++)
        {
        for (i=0;i<ce-1-j;i++)
        {
            if(nota[i]<nota[i+1])
            {
                aux=nota[i];
                nota[i]=nota[i+1];
                nota[i+1]=aux;

                aux=dni[i];
                dni[i]=dni[i+1];
                dni[i+1]=aux;
            }
        }
    }
}

void mostrarListado(int d[],int n[],int ce)
{
    int i;
    system("cls");
    printf ("\t\tLISTADO DE ALUMNOS Y NOTAS\nDNI:\t\tNOTA\n");
    for (i=0;i<ce;i++)
    {
        printf ("%9d\t%2d\n",d[i],n[i]);
    }
}
