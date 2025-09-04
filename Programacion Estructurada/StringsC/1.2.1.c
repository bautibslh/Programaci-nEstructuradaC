/*Ingresar una frase de hasta 500 caracteres y
contar cuántas palabras contiene dicha frase.
a. Considerar que las palabras están separadas
por un único espacio.
b. Considerar que las palabras pueden estar
separadas por más de un espacio consecutivo*/
#include <stdio.h>
#include <string.h>

int main()
{
    char frase[500];

    gets(frase);

    printf("Cantidad de letras %d\n",strlen(frase));

    return 0;
}
