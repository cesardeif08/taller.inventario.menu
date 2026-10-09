#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main (int argc, char *argv[]) {
    int menu;
    int numproduct = 0;
    char nombres[10][20];
    char busproduct [20];
    float precio[10];
    float sumprecio = 0;
    float promprecio = 0;
    int indvalor;
    int indMayor;
    int indMenor;
    do {
        printf("Eliga lo que desea hacer.\n");
        printf("(0) finalizar programa.\n");
        printf("(1) agregar un producto.\n");
        printf("(2) calcular el precio total del inventario.\n");
        printf("(3) calcular el precio promedio.\n");
        printf("(4) buscar precio de un producto.\n");
        printf("(5) encontrar el producto mas caro y el mas barato.\n");
        printf("-->:");
         do {
            scanf ("%d", &menu); 
            if (menu < 0 || menu > 5)
            {
                printf("Opcion invalida, intente de nuevo: \n");
                printf("-->");
            }
        } while(menu < 0 || menu > 5);
        switch (menu)
        {
        case 1:
            if (numproduct < 10)
            {
                printf("Ingrese los datos del producto %d:\n",numproduct + 1);
                printf("Nombre (una sola palabra): ");
                scanf("%19s", nombres[numproduct]);
                do
                {
                    printf("Precio (no ingresar valores negativos): ");
                    scanf("%f",&precio[numproduct]);
                } while (precio[numproduct] < 0);
                
            numproduct++;
            }
            else
            {
                printf("\n\t\t||Se ha alcanzado el maximo de productos||\n");
            }
            
            break;
        case 2:
           if (numproduct > 0)
           {
            sumprecio=0;
            for (int i = 0; i < numproduct; i++)
           {
            sumprecio = sumprecio + precio[i];
            printf("\t\tProducto:\t%d\t||\t\tNombre:\t%s\t\t||\tPrecio:\t%.2f$\n", i + 1, nombres[i], precio[i]);
           }
           printf("\n\t\t||La suma de los productos es:\t%.2f$||\n", sumprecio);
           }
           else
           {
            printf("\t\t||DATOS INSUFICIENTES||\n");
           }
            break;
        case 3:
           if (numproduct > 0)
           {
            sumprecio=0;
            for (int i = 0; i < numproduct; i++)
           {
            sumprecio = sumprecio + precio[i];
            printf("\t\tProducto:\t%d\t||\t\tNombre:\t%s\t\t||\tPrecio:\t%.2f$\n", i + 1, nombres[i], precio[i]);
           }
           promprecio = sumprecio/numproduct;
           printf("\n\t\t||El precio promedio de los productos es:\t%.2f$||\n", promprecio);
           }
           else
           {
            printf("\t\t||DATOS INSUFICIENTES||\n");
           }
           break;
        case 4:
           if (numproduct > 0)
           {
            printf("Ingrese el nombre(respetar el uso de mayusculas)->");
            scanf("%19s", busproduct);
            indvalor = -1;
            for (int i = 0; i < numproduct && indvalor == -1; i++) {
                if (strcmp(busproduct, nombres[i]) == 0)
                {
                    indvalor = i;
                }
            }
            if (indvalor != -1)
            {
                printf("\n\t\t||\t\t%s:%.2f$\t\t||\n", nombres[indvalor], precio[indvalor]);
            }
            else
            {
                printf("\n\t\t||\t\tProducto no encontrado\t\t||\n");
            }
           }
           else
           {
            printf("\t\t||DATOS INSUFICIENTES||\n");
           }
           
           break;
        case 5:
           if (numproduct > 0)
           {
            indMayor = 0;
            indMenor = 0;
            for (int i = 0; i < numproduct; i++)
            {
                if (precio[i] > precio[indMayor])
                {
                    indMayor = i;
                }
                if (precio[i] < precio[indMenor])
                {
                    indMenor = i;
                }
            }
            printf("\n\t\t||El producto mas caro es:\t%s:%.2f$||\n", nombres[indMayor], precio[indMayor]);
            printf("\t\t||El producto mas barato es:\t%s:%.2f$||\n", nombres[indMenor], precio[indMenor]);
           }
           else
           {
            printf("\t\t||DATOS INSUFICIENTES||\n");
           }
           break;
        default:
            break;
        }
    } while(menu != 0);
    return 0;
}