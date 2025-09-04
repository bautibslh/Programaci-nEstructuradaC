#include <stdio.h>
//Ingresar N artículos (códigos) y sus correspondientes precios.
//Indicar el código del artículo más caro y el precio del más barato.
//NOTA: todos los artículos tienen precios distintos.
int main()
{
    int n,i,cod,cod_max=0,cod_min=0;
    float precio,precio_max=0,precio_min;

    printf("Ingrese la cantidad de articulos:\n");
    scanf ("%d",&n);

    for (i=1;i<=n;i++)
    {
        printf ("Ingrese el codigo del articulo %d:\n",i);
        scanf ("%d",&cod);
        printf ("Ingrese el precio del articulo %d:\n",i);
        scanf ("%f",&precio);
        precio_min=precio;
        if (precio>precio_max)
        {
            precio_max=precio;
            cod_max=cod;
        }

        if (precio_min>precio)
        {
            precio_min=precio;
            cod_min=cod;
        }
    }
    printf ("El codigo del articulo mas caro es: %d\n",cod_max);
    printf ("El precio del articulo mas barato es: %.2f\n",precio_min);
    return 0;
}
