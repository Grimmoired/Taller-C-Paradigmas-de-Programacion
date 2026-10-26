#include <stdio.h>
#include <stdlib.h>

void printArray(const int *values, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", values[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]");
}

// Ejercicio 1: Intercambio de valores
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Ejercicio 2: Estadisticas de un arreglo
int sumArray(const int *values, int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += values[i];
    }
    return total;
}

int findMin(const int *values, int size) {
    int min = values[0];
    for (int i = 1; i < size; i++) {
        if (values[i] < min) {
            min = values[i];
        }
    }
    return min;
}

int findMax(const int *values, int size) {
    int max = values[0];
    for (int i = 1; i < size; i++) {
        if (values[i] > max) {
            max = values[i];
        }
    }
    return max;
}

int countNegatives(const int *values, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (values[i] < 0) {
            count++;
        }
    }
    return count;
}

void printReverse(const int *values, int size) {
    for (int i = size - 1; i >= 0; i--) {
        printf("%d ", values[i]);
    }
    printf("\n");
}

// Ejercicio 3: Copia independiente
int *copyArray(const int *values, int size) {
    int *copy = malloc(size * sizeof(int));
    if (copy == NULL) {
        return NULL;
    }
    for (int i = 0; i < size; i++) {
        copy[i] = values[i];
    }
    return copy;
}

// Ejercicio 4: Ordenar una copia
void sortAscending(int *values, int size) {
    for (int i = 1; i < size; i++) {
        int current = values[i];
        int j = i - 1;
        while (j >= 0 && values[j] > current) {
            values[j + 1] = values[j];
            j--;
        }
        values[j + 1] = current;
    }
}

// Ejercicio 5: Dos valores que suman un objetivo
int findPair(const int *values, int size, int target) {
    int left = 0;
    int right = size - 1;
    while (left < right) {
        int sum = values[left] + values[right];
        if (sum == target) {
            printf("(%d, %d) es un par valido \n", values[left], values[right]);
            return 1;
        }
        if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    return 0;
}

// Ejercicio 6: 3Sum
int threeSum(const int *values, int size) {
    if (size < 3) {
        return 0;
    }
    int *sorted = copyArray(values, size);
    if (sorted == NULL) {
        return -1;
    }
    sortAscending(sorted, size);

    int count = 0;
    for (int i = 0; i < size - 2; i++) {
        if (i > 0 && sorted[i] == sorted[i - 1]) {
            continue;  // No lo incluye para evitar repeticiones
        }
        int left = i + 1;
        int right = size - 1;
        while (left < right) {
            int sum = sorted[i] + sorted[left] + sorted[right];
            if (sum == 0) {
                printf("(%d, %d, %d) ", sorted[i], sorted[left], sorted[right]);
                count++;
                left++;
                right--;
                while (left < right && sorted[left] == sorted[left - 1]) {
                    left++;
                }
                while (left < right && sorted[right] == sorted[right + 1]) {
                    right--;
                }
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }
    free(sorted);
    return count;
}

// Ejercicio 7: maximos desde ambos extremos
void buildLeftMax(const int *height, int size, int *leftMax) {
    leftMax[0] = height[0];
    for (int i = 1; i < size; i++) {
        if (height[i] > leftMax[i - 1]) {
            leftMax[i] = height[i];
        } else {
            leftMax[i] = leftMax[i - 1];
        }
    }
}

void buildRightMax(const int *height, int size, int *rightMax) {
    rightMax[size - 1] = height[size - 1];
    for (int i = size - 2; i >= 0; i--) {
        if (height[i] > rightMax[i + 1]) {
            rightMax[i] = height[i];
        } else {
            rightMax[i] = rightMax[i + 1];
        }
    }
}

// Ejercicio 8: agua atrapada
int minOf(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}

long long trappedWater(const int *height, int size) {
    int *leftMax = malloc(size * sizeof(int));
    if (leftMax == NULL) {
        return -1;
    }
    int *rightMax = malloc(size * sizeof(int));
    if (rightMax == NULL) {
        free(leftMax);
        return -1;
    }
    buildLeftMax(height, size, leftMax);
    buildRightMax(height, size, rightMax);

    long long total = 0;
    for (int i = 0; i < size; i++) {
        total += minOf(leftMax[i], rightMax[i]) - height[i];
    }
    free(leftMax);
    free(rightMax);
    return total;
}

// Pruebas

void ejercicioPrueba1(void) {
    printf("Ejercicio 1: swap\n");
    int a = 8;
    int b = -3;
    printf("Antes: a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("Despues: a = %d, b = %d\n\n", a, b);
}

void ejercicioPrueba2(void) {
    printf("Ejercicio 2: estadisticas\n");
    int values[] = {4, -2, 0, 7, -5};
    int size = 5;
    printf("Entrada: ");
    printArray(values, size);
    printf("\n");
    printf("Suma: %d\n", sumArray(values, size));
    printf("Minimo: %d\n", findMin(values, size));
    printf("Maximo: %d\n", findMax(values, size));
    printf("Negativos: %d\n", countNegatives(values, size));
    printf("Inverso: ");
    printReverse(values, size);
    printf("Arreglo despues del recorrido inverso: ");
    printArray(values, size);
    printf("\n\n");
}

void ejercicioPrueba3(void) {
    printf("Ejercicio 3: copia independiente\n");
    int values[] = {4, -2, 0, 7, -5};
    int size = 5;
    int *copy = copyArray(values, size);
    if (copy == NULL) {
        printf("Error: no se pudo reservar memoria\n\n");
        return;
    }
    copy[0] = 99;  // Se cambia el primer elemento de la lista copia para demostrar que el original no se ve afectado
    printf("Original: ");
    printArray(values, size);
    printf("\nCopia: ");
    printArray(copy, size);
    printf("\n\n");
    free(copy);
}

void ejercicioPrueba4(void) {
    printf("Ejercicio 4: ordenar una copia\n");
    int values[] = {4, -2, 0, 7, -5};
    int size = 5;
    int *copy = copyArray(values, size);
    if (copy == NULL) {
        printf("Error: no se pudo reservar memoria\n\n");
        return;
    }
    sortAscending(copy, size);
    printf("Original: ");
    printArray(values, size);
    printf("\nOrdenado: ");
    printArray(copy, size);
    printf("\n\n");
    free(copy);
}

void testPair(const int *values, int size, int target) {
    printf("Arreglo ");
    printArray(values, size);
    printf(", objetivo %d: ", target);
    if (!findPair(values, size, target)) {
        printf("No existe\n");
    }
}

void ejercicioPrueba5(void) {
    printf("Ejercicio 5: dos valores que suman un objetivo \n");
    int a[] = {-4, -1, 0, 2, 5};
    int b[] = {0, 0};
    int c[] = {3};
    testPair(a, 5, 1);
    testPair(a, 5, 8);
    testPair(b, 2, 0);
    testPair(c, 1, 6);
    printf("\n");
}

void testThreeSum(const int *values, int size) {
    printf("Entrada ");
    printArray(values, size);
    printf(": ");
    int count = threeSum(values, size);
    if (count == -1) {
        printf("Error: no se pudo reservar memoria\n");
    } else if (count == 0) {
        printf("Ninguna terna\n");
    } else {
        printf("-> %d terna(s)\n", count);
    }
}

void ejercicioPrueba6(void) {
    printf("Ejercicio 6: 3Sum \n");
    int a[] = {-1, 0, 1, 2, -1, -4};
    int b[] = {0, 1, 1};
    int c[] = {0, 0, 0};
    int d[] = {0, 0, 0, 0};
    int e[] = {-2, 0, 0, 2, 2};
    int f[] = {1, -1};
    testThreeSum(a, 6);
    testThreeSum(b, 3);
    testThreeSum(c, 3);
    testThreeSum(d, 4);
    testThreeSum(e, 5);
    testThreeSum(f, 2);
    printf("\n");
}

void ejercicioPrueba7(void) {
    printf("Ejercicio 7: maximos desde ambos extremos\n");
    int height[] = {3, 0, 2, 0, 4};
    int size = 5;
    int leftMax[5];
    int rightMax[5];
    buildLeftMax(height, size, leftMax);
    buildRightMax(height, size, rightMax);
    printf("height:   ");
    printArray(height, size);
    printf("\nleftMax:  ");
    printArray(leftMax, size);
    printf("\nrightMax: ");
    printArray(rightMax, size);
    printf("\n\n");
}

void showWaterDetail(const int *height, int size) {
    int *leftMax = malloc(size * sizeof(int));
    int *rightMax = malloc(size * sizeof(int));
    if (leftMax == NULL || rightMax == NULL) {
        printf("Error: no se pudo reservar memoria\n");
        free(leftMax);
        free(rightMax);
        return;
    }

    buildLeftMax(height, size, leftMax);
    buildRightMax(height, size, rightMax);
    printf("alturas:  ");
    printArray(height, size);
    printf("\nleftMax:  ");
    printArray(leftMax, size);
    printf("\nrightMax: ");
    printArray(rightMax, size);
    printf("\nagua:     [");

    for (int i = 0; i < size; i++) {
        printf("%d", minOf(leftMax[i], rightMax[i]) - height[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
    free(leftMax);
    free(rightMax);
}

void testWater(const int *height, int size, long long expected) {
    long long result = trappedWater(height, size);
    printArray(height, size);
    printf(" -> agua = %lld %s\n", result, result == expected ? "Correcto" : "Incorrecto");
}

void ejercicioPrueba8(void) {
    printf("Ejercicio 8: agua atrapada\n");
    int a[] = {5};
    int b[] = {0, 1, 2, 3};
    int c[] = {3, 2, 1, 0};
    int d[] = {2, 2, 2};
    int e[] = {3, 0, 3};
    int f[] = {3, 0, 2, 0, 4};
    int g[] = {4, 2, 0, 3, 2, 5};
    int h[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    testWater(a, 1, 0);
    testWater(b, 4, 0);
    testWater(c, 4, 0);
    testWater(d, 3, 0);
    testWater(e, 3, 3);
    testWater(f, 5, 7);
    testWater(g, 6, 9);
    testWater(h, 12, 6);

    printf("\nDetalle por posicion:\n");
    showWaterDetail(f, 5);

    // Caso propio: los extremos miden 2, asi que en el centro el agua sube hasta 2: 2 + 1 + 2 = 5.
    int casoPropio[] = {2, 0, 1, 0, 2};
    printf("\nCaso propio:\n");
    showWaterDetail(casoPropio, 5);
    testWater(casoPropio, 5, 5);
    printf("\n");
}

int main(void) {
    ejercicioPrueba1();
    ejercicioPrueba2();
    ejercicioPrueba3();
    ejercicioPrueba4();
    ejercicioPrueba5();
    ejercicioPrueba6();
    ejercicioPrueba7();
    ejercicioPrueba8();
    return 0;
}
