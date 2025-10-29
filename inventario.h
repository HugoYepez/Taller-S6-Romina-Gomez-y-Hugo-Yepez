#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTOS 10
#define MAX_NOMBRE 50

void ingresarProductos(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], float precios[MAX_PRODUCTOS], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Ingrese el nombre del producto %d: ", i + 1);
        scanf(" %[^\n]", nombres[i]);
        printf("Ingrese el precio del producto %d: ", i + 1);
        scanf("%f", &precios[i]);
    }
}

float calcularTotal(float precios[MAX_PRODUCTOS], int n)
{
    float total = 0;
    for (int i = 0; i < n; i++)
    {
        total += precios[i];
    }
    return total;
}

float calcularPromedio(float precios[MAX_PRODUCTOS], int n)
{
    return calcularTotal(precios, n) / n;
}

void productoMasCaroBarato(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], float precios[MAX_PRODUCTOS], int n)
{
    int indiceCaro = 0, indiceBarato = 0;
    for (int i = 1; i < n; i++)
    {
        if (precios[i] > precios[indiceCaro])
            indiceCaro = i;
        if (precios[i] < precios[indiceBarato])
            indiceBarato = i;
    }

    printf("\nProducto mas caro: %s (%.2f)\n", nombres[indiceCaro], precios[indiceCaro]);
    printf("Producto mas barato: %s (%.2f)\n", nombres[indiceBarato], precios[indiceBarato]);
}

void buscarProducto(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], float precios[MAX_PRODUCTOS], int n)
{
    char buscado[MAX_NOMBRE];
    int encontrado = 0;

    printf("\nIngrese el nombre del producto que desea buscar: ");
    scanf(" %[^\n]", buscado);

    for (int i = 0; i < n; i++)
    {
        if (strcmp(nombres[i], buscado) == 0)
        {
            printf("El precio de %s es: %.2f\n", nombres[i], precios[i]);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
        printf("Producto no encontrado.\n");
}
