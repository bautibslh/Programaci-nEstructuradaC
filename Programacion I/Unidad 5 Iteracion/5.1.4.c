#include <stdio.h>
#include <ctype.h>
#define CANT_CHAR 100
int esVocal (char c);

int main ()
{
    int contador=0,i;
    char letra;

    for (i=1;i<=CANT_CHAR;i++)
    {
        printf ("Ingresar letra\n");
        scanf ("%c",&letra);
        fflush(stdin);

        if (esVocal(letra)==1)
        {
            contador++;
           // printf ("Contador: %d\n",contador);
        }
       // printf ("%c\n",letra);
    }
    printf ("La cantidad de vocales es: %d\n",contador);

    return 0;
}


int esVocal (char c)
{

    c=tolower(c);

    if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
    {
        return 1;
    }
    else
        return 0;
}
