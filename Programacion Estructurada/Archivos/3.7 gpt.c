
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char codigoAerolinea[10];
    int dia;
    int numeroVuelo;
    float costoPasaje;
    int pasajeros;
} Vuelo;

typedef struct {
    int dni;
    int numeroVuelo;
} Pasajero;

void actualizarPasajeros() {
    FILE *vuelosFile = fopen("VUELOS.dat", "rb");
    FILE *pasajerosFile = fopen("PASAJEROS.dat", "rb");
    FILE *aero1File = fopen("Aero1.dat", "wb");

    Vuelo vuelo;
    Pasajero pasajero;

    while (fread(&vuelo, sizeof(Vuelo), 1, vuelosFile)) {
        if (strcmp(vuelo.codigoAerolinea, "Aero1") == 0) {
            fseek(pasajerosFile, 0, SEEK_SET);
            while (fread(&pasajero, sizeof(Pasajero), 1, pasajerosFile)) {
                if (vuelo.numeroVuelo == pasajero.numeroVuelo) {
                    vuelo.pasajeros++;
                }
            }
            fwrite(&vuelo, sizeof(Vuelo), 1, aero1File);
        }
    }

    fclose(vuelosFile);
    fclose(pasajerosFile);
    fclose(aero1File);
}

void exportarCSV() {
    FILE *aero1File = fopen("Aero1.dat", "rb");
    FILE *csvFile = fopen("Aero12.csv", "wt");

    Vuelo vuelo;

    fprintf(csvFile, "Codigo Aerolinea,Dia,Numero de Vuelo,Costo del Pasaje,Pasajeros\n");

    while (fread(&vuelo, sizeof(Vuelo), 1, aero1File)) {
        fprintf(csvFile, "%s,%d,%d,%f,%d\n", vuelo.codigoAerolinea, vuelo.dia, vuelo.numeroVuelo, vuelo.costoPasaje, vuelo.pasajeros);
    }

    fclose(aero1File);
    fclose(csvFile);
}

int main() {
    actualizarPasajeros();
    exportarCSV();

    return 0;
}
