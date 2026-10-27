# Taller de programación imperativa en C
Curso de Paradigmas de Programación, Tecnologico de Costa Rica segundo semestre 2026.
  
Integrantes:
- Bryan David Abarca Quiros
- Jorge Pablo Porras Alvarado

## Instrucciones de ejecución

El programa se ejecuta en consola, no requiere inputs ya que las entradas usadas en la prueba ya están definidas dentro de `main` y pueden modificarse para hacer pruebas diferentes.
Para ejecutarlo se requiere tener GCC instalado, abra una terminar en la carpeta que contiene a `main.c` y ejecute los 2 siguientes comandos para generar el ejecutable y correrlo, esto imprimira a la consola los resultados de todas las pruebas:

```bash
gcc -std=c11 -Wall -Wextra -pedantic main.c -o taller
./taller
```

## Organización del código

`main.c` contiene las definiciones de las funciones que resuelven los ejercicios propuestos por el enunciado, y un caso de prueba por ejercicio, llamados 'ejercicioPrueba' del 1 al 8; estas soluciones no hacen uso de variables globales, los datos se pasan unicamente por parámetros.

| Ejercicio | Funciones |
|---|---|
| 1 | `swap` |
| 2 | `sumArray`, `findMin`, `findMax`, `countNegatives`, `printReverse` |
| 3 | `copyArray` |
| 4 | `sortAscending` (inserción, sobre una copia) |
| 5 | `findPair` |
| 6 | `threeSum` |
| 7 | `buildLeftMax`, `buildRightMax` |
| 8 | `trappedWater` |

## Resultados de las pruebas
A continuacion los resultados que dio el programa al ejecutar todos los casos de prueba expuestos en el enunciado para cada ejercicio:

```text
Ejercicio 1: swap
Antes: a = 8, b = -3
Despues: a = -3, b = 8

Ejercicio 2: estadisticas
Entrada: [4, -2, 0, 7, -5]
Suma: 4
Minimo: -5
Maximo: 7
Negativos: 2
Inverso: -5 7 0 -2 4
Arreglo despues del recorrido inverso: [4, -2, 0, 7, -5]

Ejercicio 3: copia independiente
Original: [4, -2, 0, 7, -5]
Copia: [99, -2, 0, 7, -5]

Ejercicio 4: ordenar una copia
Original: [4, -2, 0, 7, -5]
Ordenado: [-5, -2, 0, 4, 7]

Ejercicio 5: dos valores que suman un objetivo
Arreglo [-4, -1, 0, 2, 5], objetivo 1: (-4, 5) es un par valido
Arreglo [-4, -1, 0, 2, 5], objetivo 8: No existe
Arreglo [0, 0], objetivo 0: (0, 0) es un par valido
Arreglo [3], objetivo 6: No existe

Ejercicio 6: 3Sum
Entrada [-1, 0, 1, 2, -1, -4]: (-1, -1, 2) (-1, 0, 1) -> 2 terna(s)
Entrada [0, 1, 1]: Ninguna terna
Entrada [0, 0, 0]: (0, 0, 0) -> 1 terna(s)
Entrada [0, 0, 0, 0]: (0, 0, 0) -> 1 terna(s)
Entrada [-2, 0, 0, 2, 2]: (-2, 0, 2) -> 1 terna(s)
Entrada [1, -1]: Ninguna terna

Ejercicio 7: maximos desde ambos extremos
height:   [3, 0, 2, 0, 4]
leftMax:  [3, 3, 3, 3, 4]
rightMax: [4, 4, 4, 4, 4]

Ejercicio 8: agua atrapada
[5] -> agua = 0 (esperado 0) OK
[0, 1, 2, 3] -> agua = 0 (esperado 0) OK
[3, 2, 1, 0] -> agua = 0 (esperado 0) OK
[2, 2, 2] -> agua = 0 (esperado 0) OK
[3, 0, 3] -> agua = 3 (esperado 3) OK
[3, 0, 2, 0, 4] -> agua = 7 (esperado 7) OK
[4, 2, 0, 3, 2, 5] -> agua = 9 (esperado 9) OK
[0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1] -> agua = 6 (esperado 6) OK

Detalle por posicion:
alturas:  [3, 0, 2, 0, 4]
leftMax:  [3, 3, 3, 3, 4]
rightMax: [4, 4, 4, 4, 4]
agua:     [0, 3, 1, 3, 0]

Caso propio:
alturas:  [2, 0, 1, 0, 2]
leftMax:  [2, 2, 2, 2, 2]
rightMax: [2, 2, 2, 2, 2]
agua:     [0, 2, 1, 2, 0]
[2, 0, 1, 0, 2] -> agua = 5 (esperado 5) OK
```

El caso propio del ejercicio 8, `[2, 0, 1, 0, 2]`, el resultado es 5, ya que los extremos miden 2, por lo cual el agua sube hasta el nivel 2 en el centro y se acumulan 2 + 1 + 2 unidades sobre las columnas de altura 0, 1 y 0.


## Respuestas a las preguntas en algunos ejercicios del enunciado

### Ejercicio 1 - swap: "Responda: ¿por qué los parámetros son punteros? ¿Qué diferencia existe entre modificar a y modificar *adentro de la función? ¿Cuál es el alcance de una variable auxiliar declarada en swap?"

- Los parámetros son punteros porque C pasa los argumentos por valor: si `swap` recibiera `int a, int b`, intercambiaría copias locales y las variables de `main` no cambiarían. Con las direcciones, la función llega a las variables originales.
- Dentro de la función, modificar `a` cambia solo el puntero local, es decir, la direccion que se copio, y no afecta a quien llamó, por otro lado modificar `*a` cambia el valor almacenado en esa dirección, es decir, la variable original a la que se llamo.
- La variable auxiliar `temp` tiene alcance de bloque, solo existe dentro de `swap`, y desaparece al terminar la llamada.

### Ejercicio 3 — copia independiente: "Explique por qué asignar un puntero a otro no crea una copia de los elementos. Compruebe el resultado de malloc y libere los bloques ya reservados si una operación posterior falla."

- Asignar un puntero a otro (por ejemplo: `int *p = original;`) solo copia la dirección, por lo que ambos apuntan al mismo bloque de memoria, así que modificar uno modifica el otro; para tener un arreglo independiente hay que reservar un bloque nuevo y copiar elemento por elemento (como hace `copyArray`), en el código se comprueba el resultado de `malloc` y, en `trappedWater`, y si la segunda reserva falla se libera la primera antes de devolver `-1`.

### Ejercicio 5 — descartar un extremo: "Explique por qué puede descartarse un extremo después de comparar la suma. Estos dos índices no requieren aritmética de punteros." 

- Con el arreglo ordenado, si `values[left] + values[right] < target`, `values[left]` no puede formar un par válido con ningún elemento restante su mejor compañero posible sera `values[right]`, que es el mayor, pero aun así no sera capaz de alcanzar el objetivo, por eso se descarta con `left++`; por otro lado, si la suma es mayor que `target`, el razonamiento es simétrico y se descarta `values[right]` con `right--`, los dos índices solo necesitan posiciones (`values[i]`), no aritmética de punteros.


## Como `threeSum` evita ternas duplicadas

1. Se trabaja sobre una copia ordenada, así los valores iguales quedan contiguos.
2. Al recorrer el primer elemento `sorted[i]`, si es igual al anterior (`sorted[i] == sorted[i - 1]`), se salta: con ese mismo valor ya se buscaron todas las ternas posibles.
3. Al encontrar una terna con suma cero, se avanzan `left` y `right` y además se saltan los valores iguales al anterior en cada extremo. Así no se repite la misma pareja de valores para ese primer elemento.

Las posiciones son siempre distintas (`i < left < right`), por lo que valores repetidos solo se usan si hay suficientes apariciones: `[0, 0, 0]` da una terna y `[0, 0, 0, 0]` también da una sola, no cuatro. Después de ordenar, la búsqueda es O(n²): para cada `i`, `left` y `right` recorren el resto del arreglo una sola vez.


## Por qué el agua depende del menor de los dos máximos

Sobre una columna `i`, el agua sube hasta el nivel de la pared más baja entre la mayor altura a su izquierda (`leftMax[i]`) y la mayor a su derecha (`rightMax[i]`). Si el agua superara la pared más baja, se derramaría por ese lado, de modo que la pared más alta no ayuda a retenerla. Por eso el nivel es `min(leftMax[i], rightMax[i])`, y el agua sobre la columna es ese nivel menos la altura de la propia columna: `water[i] = min(leftMax[i], rightMax[i]) - height[i]`.

Como `leftMax` y `rightMax` incluyen la posición actual, el resultado nunca es negativo. En los extremos uno de los dos máximos es la propia altura, así que el agua es 0: escapa por los bordes, como pide el enunciado. Ejemplo con `[3, 0, 2, 0, 4]`: en la posición 1, el nivel es `min(3, 4) = 3` y el agua es `3 - 0 = 3`; en la posición 2 es `min(3, 4) - 2 = 1`; en la 3 es `3 - 0 = 3`. Total: 7.

## Ejemplo de alcance de variables

Tomado de `threeSum`:

```c
int threeSum(const int *values, int size) {
    int *sorted = copyArray(values, size);   /* visible en toda la función */
    int count = 0;                           /* visible en toda la función */
    for (int i = 0; i < size - 2; i++) {     /* i solo existe dentro del for */
        int left = i + 1;                    /* left y right: solo en el cuerpo del for */
        int right = size - 1;
        while (left < right) {
            int sum = sorted[i] + sorted[left] + sorted[right];  /* sum: solo en el while */
            ...
        }
    }
    free(sorted);
    return count;
}
```

`sum` solo puede usarse dentro del `while`, y se crea de nuevo en cada iteración; `i` no se puede usar después del `for`; `sorted` y `count` viven mientras dure la llamada a `threeSum` y no son visibles desde `main`. Por eso `main` y `threeSum` pueden tener variables con el mismo nombre sin que se mezclen.

## Comparación entre C y GoLang con respecto al manejo de memoria:

| Aspecto | C | GoLang |
|---|---|---|
| Reserva | Manual con `malloc(n * sizeof(int))` | `make([]int, n)` o `new`; el valor queda inicializado en cero |
| Liberación | El programador debe llamar `free` exactamente una vez por bloque | Automática: un recolector de basura libera lo que ya no se referencia; no existe `free` |
| Fallo de reserva | `malloc` devuelve `NULL` y hay que comprobarlo (como en `copyArray` y `trappedWater`) | No se comprueba: si falta memoria, el programa termina con un error fatal en tiempo de ejecución |
| Errores típicos | Fugas, doble `free`, uso tras liberar, escribir fuera de los límites sin aviso | Estos errores no ocurren en código normal; salirse de un arreglo provoca un `panic` controlado |
| Arreglos | Un puntero y un tamaño que se llevan por separado (`int *values, int size`) | Los *slices* incluyen longitud y capacidad, y se comprueban los índices al ejecutar |
| Copiar | Reservar un bloque nuevo y copiar elemento por elemento (`copyArray`) | `copy(destino, origen)` o `append`; ojo: asignar un slice a otro comparte el arreglo de fondo, igual que asignar punteros en C |
| Pila y montículo | Lo decide el programador: variable local en la pila, `malloc` en el montículo | Lo decide el compilador (análisis de escape); el programador no lo elige |
| Punteros | Permiten aritmética de punteros | Existen, pero sin aritmética |

En C el programador controla cuándo se reserva y se libera cada bloque, el consumo es predecible y no hay pausas de un recolector, pero cada reserva exige comprobar fallos y liberar con cuidado, debido a esto, para llevar a cabo las soluciones de esta taller fue necesario liberar la copia en `threeSum` y los dos arreglos auxiliares en `trappedWater`, incluso cuando una de las reservas falla; en GoLang esa carga no esta presente, y el código es más corto y seguro, a cambio de menos control sobre la memoria y de la sobrecarga del recolector.
