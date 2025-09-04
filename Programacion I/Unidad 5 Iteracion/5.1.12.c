/*
Calcular el factorial de un número ingresado por teclado. El factorial se calcula como el producto de todos los enteros positivos desde 1 hasta el número.
En matemática el factorial se expresa con el símbolo !. Por ejemplo, el factorial de 5 es 120 ya que 5! = 1 x 2 x 3 x 4 x 5 =120
*/

#include <stdio.h>

int main()
{
    int i,num,fact=1;

    printf ("Ingrese un numero para saber su factorial\n");
    scanf ("%d",&num);

    for (i=1;i<=num;i++)
    {
        fact=fact*i;
    }
    printf ("El factorial de %d es: %d\n",num,fact);

    return 0;
}
