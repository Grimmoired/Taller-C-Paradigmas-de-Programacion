//
// Created by Bryan on 10/21/2026.
//
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
    copy[0] = 99;
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

int main(void) {
    ejercicioPrueba1();
    ejercicioPrueba2();
    ejercicioPrueba3();
    ejercicioPrueba4();
    return 0;
}