
/*Se dispone de un archivo que contiene información de los vuelos realizados por las distintas aerolíneas a lo
largo del mes. El archivo se denomina Vuelos.dat y guarda los registros con la siguiente estructura:
• Código Aerolínea (alfanumérico de 10 caracteres máximo)
• Día (entero)
• Número de Vuelo (entero)
• Costo del pasaje (real)
• Pasajeros (inicialmente en el archivo viene en 0)
El mes tiene 30 días y se sabe que como máximo cada aerolínea realiza 5 vuelos diarios. Luego se dispone de un
segundo archivo llamado Pasajeros.dat que incluye la información de los viajeros del mes para la aerolínea
con código “Aero1”, el archivo contiene los siguientes campos:
• DNI (entero)
• Número de Vuelo (entero)
Se desea realizar un programa que actualice la cantidad de pasajeros de la aerolínea con código “Aero1”
con la información de los pasajeros que realizar los viajes. Al finalizar, grabar la información en un nuevo
archivo llamado Aero1.dat. Agregar la opción para exportar el archivo Aero1 a formato csv*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
                char cod[11];
                int dia;
                int nvuelo;
                float precio;
                int pasajeros;
}t_Vuelos;
typedef struct{
                int dni;
                int nvuelo;
}t_Pasajeros;

int main()
{
    int i=0;
    t_Vuelos vuelos;
    t_Pasajeros pasajeros;
    FILE*arch;
    FILE*pf;
    FILE*ivo;
    arch=fopen("VUELOS.dat","rb");
    if(arch==NULL)
    {
        printf("Error al cargar archivo\n");
        system("pause");
        exit(1);
    }
    pf=fopen("PASAJEROS.dat","rb");
    if(pf==NULL)
    {
        printf("Error al cargar archivo\n");
        system("pause");
        exit(1);
    }
    ivo=fopen("Aero1.csv","wt");
    if(ivo==NULL)
        exit(1);
    fread(&vuelos,sizeof(vuelos),1,arch);
    while(!feof(arch))
    {
        if(strcmpi("Aero1",vuelos.cod)==0){

        fread(&pasajeros,sizeof(t_Pasajeros),1,pf);
        while(!feof(pf))
        {
            if(vuelos.nvuelo==pasajeros.nvuelo)
            {
                vuelos.pasajeros++;
                fprintf(ivo,"%s;%d;n vuelo %d;%.2f;Pasajeros %d;\n",vuelos.cod,vuelos.dia,vuelos.nvuelo,vuelos.precio,vuelos.pasajeros);
            }
            fread(&pasajeros,sizeof(t_Pasajeros),1,pf);


        }
        }
        fread(&vuelos,sizeof(vuelos),1,arch);
    }
    fclose(arch);
    fclose(ivo);
    fclose(pf);



    system("pause");
    return 0;
}
