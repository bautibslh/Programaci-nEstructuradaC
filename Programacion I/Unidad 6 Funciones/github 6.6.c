#include <stdio.h>

int contarCifras(int numero, int cifra) {
    int contador = 0;
    while (numero > 0) {
        if (numero % 10 == cifra) {
            contador++;
        }
        numero /= 10;
    }
    return contador;
}

int main() {
    int cantidadNumeros = 0;

    for (int numero = 10001; numero <= 90009; numero++) {
        int cantidadTres = contarCifras(numero, 3);
        int cantidadCuatro = contarCifras(numero, 4);

        if (cantidadCuatro > 0 && cantidadTres > cantidadCuatro) {
            cantidadNumeros++;
        }
    }

    printf("Cantidad de números que cumplen la condición: %d\n", cantidadNumeros);

    return 0;
}

