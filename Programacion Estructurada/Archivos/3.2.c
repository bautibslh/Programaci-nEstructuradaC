#include <string.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct {
                int dni;
                char nya[81];
                int nota[2];
                float prom;
    }T_alum;

void MostrarArchivo(char[25]);
int main ()
{
    FILE* arch;
    FILE* pf;
    FILE* ivo;
    FILE* apro;

    T_alum alumnos;
    arch=fopen("ALUMNOS.dat","rb");
    if(arch==NULL)
    {
        printf("Error, no se pudo abrir el archivo\n");
        system("pause");
        exit(1);
    }

    fread(&alumnos,sizeof(alumnos),1,arch);
    while(!feof(arch))
    {
        if(alumnos.nota[0]<4 || alumnos.nota[1]<4)
        {
            pf=fopen("REPROBADOS.dat","wb");
            if(pf==NULL)
            {
                printf("Error, no se pudo abrir el archivo\n");
                system("pause");
                exit(1);
            }
            fwrite(&alumnos,sizeof(alumnos),1,pf);
            fclose(pf);
        }

        else if(alumnos.nota[0]>=4 && alumnos.nota[0]<7 && alumnos.nota[1]>=4 && alumnos.nota[1]<7)
        {
            ivo=fopen("CURSADOS.dat","wb");
            if(ivo==NULL)
            {
                printf("Error, no se pudo abrir el archivo\n");
                system("pause");
                exit(1);
            }
            fwrite(&alumnos,sizeof(alumnos),1,ivo);
            fclose(ivo);
        }
        else if(alumnos.nota[0]>=7 && alumnos.nota[1]>=7)
        {
            apro=fopen("PROMOCIONADOS.dat","wb");
            if(apro==NULL)
            {
                printf("Error, no se pudo abrir el archivo\n");
                system("pause");
                exit(1);
            }
            fwrite(&alumnos,sizeof(alumnos),1,apro);
            fclose(apro);
        }

        fread(&alumnos,sizeof(alumnos),1,arch);
    }
    fclose(arch);
    printf("PROMOCIONADOS\n");
    MostrarArchivo("PROMOCIONADOS.dat");

    printf("CURSADOS\n");
    MostrarArchivo("CURSADOS.dat");

    printf("REPROBADOS\n");
    MostrarArchivo("REPROBADOS.dat");
    system ("pause");
    return 0;
}

void MostrarArchivo(char nomArchivo[])
{
    FILE* pf;
    T_alum al;
    pf=fopen(nomArchivo,"rb");
    if(pf==NULL)
    {
        printf("Error, no se pudo abrir el archivo\n");
        system("pause");
        exit(1);
    }
    fread(&al,sizeof(al),1,pf);
    while(!feof(pf))
    {
        printf("%d\n%s\n%d %d\n%.2f\n",al.dni,al.nya,al.nota[0],al.nota[1],al.prom);
        fread(&al,sizeof(al),1,pf);
    }
    fclose(pf);
}
