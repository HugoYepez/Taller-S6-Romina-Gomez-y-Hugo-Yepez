#include <stdio.h>
#include "inventario.h"

int main() {
    char nombres[MAX_PRODUCTOS][MAX_NOMBRE];
    float precios[MAX_PRODUCTOS];
    int n;

    printf("Ingrese la cantidad de productos (maximo %d): ", MAX_PRODUCTOS);
    scanf("%d", &n);

    if (n < 1 || n > MAX_PRODUCTOS) {
        printf("Error: cantidad no valida. Debe ser entre 1 y %d.\n", MAX_PRODUCTOS);
        return 1;
    }

    ingresarProductos(nombres, precios, n);

    printf("\n=== RESULTADOS DEL INVENTARIO ===\n");
    printf("Precio total del inventario: %.2f\n", calcularTotal(precios, n));
    printf("Precio promedio: %.2f\n", calcularPromedio(precios, n));

    productoMasCaroBarato(nombres, precios, n);
    buscarProducto(nombres, precios, n);

    return 0;
}
