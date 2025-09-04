#include <stdio.h>

int main() {
    int i, j, es_primo, count = 0;


    for (i = 2; i <= 100; i++) {
        es_primo = 1;



        es_primo = (i % j != 0);
        for (j = 2; j <= i / 2 && es_primo == 1; j++) {
            es_primo = (i % j != 0);
        }


        if (es_primo == 1) {
            printf("%d\n", i);
            count++;
        }
    }


    printf("\nLa cantidad de numeros primos entre 1 y 100 es: %d\n", count);

    return 0;
}

