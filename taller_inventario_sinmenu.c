#include <stdio.h>
#include <string.h>

#define MAX 10

int main(void)
{
    int productos;
    float total = 0;
    float promedio;
    int indMayor = 0;
    int indMenor = 0; 
    char nomb[25];
    int indvalor = -1;
    char nombres[MAX][25];
    float precios[MAX];
    do
    {
        printf("INGRESE LA CANTIDAD DE PRODUCTOS (de 1 a %d):\t", MAX);
        scanf("%d", &productos);

        if (productos < 1 || productos > MAX)
        {
            printf("Cantidad invalida. Intente de nuevo.\n");
        }
    } while (productos < 1 || productos > MAX);
    for (int i = 0; i < productos; i++)
    {
        printf("Ingrese nombre %d: ", i + 1);
        scanf(" %24[^\n]", nombres[i]); 

        printf("Ingrese precio %d: ", i + 1);
        scanf("%f", &precios[i]);
    }
    for (int i = 0; i < productos; i++)
    {
        total += precios[i];

        if (precios[i] > precios[indMayor])
        {
            indMayor = i;
        }

        if (precios[i] < precios[indMenor])
        {
            indMenor = i;
        }
    }
    promedio = total / productos;
    printf("\nEl precio total del inventario es: %.2f\n", total);
    printf("El producto mas caro es %s con %.2f\n", nombres[indMayor], precios[indMayor]);
    printf("El producto mas barato es %s con %.2f\n", nombres[indMenor], precios[indMenor]);
    printf("El precio promedio es: %.2f\n", promedio);
    printf("\nIngrese el nombre del producto a buscar: ");
    scanf(" %24[^\n]", nomb);

    for (int i = 0; i < productos && indvalor == -1; i++)
    {
        if (strcmp(nomb, nombres[i]) == 0)
        {
            indvalor = i;
        }
    }
    if (indvalor != -1)
    {
        printf("El valor de %s es %.2f\n", nombres[indvalor], precios[indvalor]);
    }
    else
    {
        printf("Producto no encontrado\n");
    }
    return 0;
}