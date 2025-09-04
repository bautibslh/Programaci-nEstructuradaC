#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
                int dni;
                char nya[81];
                int nota[2];
                float prom;
    }T_alum;

int main()
{
    T_alum alumno;
    int i=0;
    FILE* arch;
    arch=fopen("ALUMNOS.dat","rb");
    if(arch==NULL)
    {
        printf("Error, no se pudo abrir el archivo\n");
        system("pause");
        exit(1);
    }
    fread(&alumno,sizeof(T_alum),1,arch);
    while(!feof(arch))
    {
        printf("DNI %d\n",alumno.dni);
        printf("Nombre y Apellido %s\n",alumno.nya);
        printf("Notas %d ; %d\n",alumno.nota[0],alumno.nota[1]);
        printf("Promedio %.2f\n",alumno.prom);
        i++;
        fread(&alumno,sizeof(T_alum),1,arch);
    }
    fclose(arch);

    return 0;
}
