/*Ingresar una frase de hasta 500 caracteres y
contar cu�ntas palabras contiene dicha frase.
a. Considerar que las palabras est�n separadas
por un �nico espacio.
b. Considerar que las palabras pueden estar
separadas por m�s de un espacio consecutivo*/
#include <stdio.h>
#include <string.h>

int main()
{
    char frase[500];

    gets(frase);

    printf("Cantidad de letras %d\n",strlen(frase));

    return 0;
}
