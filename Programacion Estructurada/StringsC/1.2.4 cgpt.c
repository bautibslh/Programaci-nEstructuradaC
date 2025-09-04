#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 50
#define MAX_CODE_LENGTH 4

void readProducts(char codes[][MAX_CODE_LENGTH], float prices[], int *numProducts) {
    int i = 0;
    printf("Ingrese código y precio unitario de los productos (código 'FIN' para terminar):\n");

    while (1) {
        printf("Código del producto: ");
        scanf("%s", codes[i]);

        if (strcmp(codes[i], "FIN") == 0) {
            break;
        }

        printf("Precio unitario: ");
        scanf("%f", &prices[i]);

        i++;

        if (i >= MAX_PRODUCTS) {
            printf("Se ha alcanzado el límite máximo de productos (50).\n");
            break;
        }
    }

    *numProducts = i;
}

void recordSales(char codes[][MAX_CODE_LENGTH], int quantities[], int numProducts) {
    printf("\nIngrese las ventas del día (código 'FIN' para terminar):\n");

    while (1) {
        char code[MAX_CODE_LENGTH];
        int quantity;
        printf("Código del producto: ");
        scanf("%s", code);

        if (strcmp(code, "FIN") == 0) {
            break;
        }

        printf("Cantidad de unidades vendidas: ");
        scanf("%d", &quantity);

        for (int i = 0; i < numProducts; i++) {
            if (strcmp(codes[i], code) == 0) {
                quantities[i] += quantity;
                break;
            }
        }
    }
}

float calculateTotalRevenue(float prices[], int quantities[], int numProducts) {
    float totalRevenue = 0.0;

    for (int i = 0; i < numProducts; i++) {
        totalRevenue += prices[i] * quantities[i];
    }

    return totalRevenue;
}

void sortProducts(char codes[][MAX_CODE_LENGTH], float prices[], int numProducts) {
    for (int i = 0; i < numProducts - 1; i++) {
        for (int j = i + 1; j < numProducts; j++) {
            if (strcmp(codes[i], codes[j]) > 0) {
                // Swap codes[i] and codes[j]
                char tempCode[MAX_CODE_LENGTH];
                strcpy(tempCode, codes[i]);
                strcpy(codes[i], codes[j]);
                strcpy(codes[j], tempCode);

                // Swap prices[i] and prices[j]
                float tempPrice = prices[i];
                prices[i] = prices[j];
                prices[j] = tempPrice;
            }
        }
    }
}

int main() {
    char codes[MAX_PRODUCTS][MAX_CODE_LENGTH];
    float prices[MAX_PRODUCTS];
    int quantities[MAX_PRODUCTS];
    int numProducts = 0;

    readProducts(codes, prices, &numProducts);
    memset(quantities, 0, sizeof(quantities)); // Initialize quantities to 0
    recordSales(codes, quantities, numProducts);

    float totalRevenue = calculateTotalRevenue(prices, quantities, numProducts);
    printf("\nRecaudación total del día: $%.2f\n", totalRevenue);

    // Find product with the least quantity sold
    int minQuantity = quantities[0];
    int minIndex = 0;

    for (int i = 1; i < numProducts; i++) {
        if (quantities[i] < minQuantity) {
            minQuantity = quantities[i];
            minIndex = i;
        }
    }

    printf("Producto con menor cantidad de unidades vendidas: %s\n", codes[minIndex]);

    sortProducts(codes, prices, numProducts);

    printf("\nListado de productos ordenados por código:\n");
    for (int i = 0; i < numProducts; i++) {
        printf("Código: %s, Precio: $%.2f\n", codes[i], prices[i]);
    }

    return 0;
}

