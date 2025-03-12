#include <stdio.h>
#include <stdlib.h> // Для использования malloc и free
#include <math.h>   // Для использования sqrt

int main() {
    int n; // Размер массива
    printf("Введите размер массива: ");
    scanf("%d", &n);

    // Выделение динамической памяти для массивов b и c
    double *b = (double *)malloc(n * sizeof(double)); // Исходный массив
    double *c = (double *)malloc(n * sizeof(double)); // Массив для хранения результатов
    if (b == NULL || c == NULL) {
        printf("Ошибка выделения памяти!\n");
        return 1; // Завершаем программу с ошибкой
    }

    int c_size = 0; // Размер массива c

    // Ввод элементов массива b
    printf("Введите элементы массива: ");
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &b[i]);
        if (b[i] > 0) { // Если элемент положительный
            c[c_size] = sqrt(b[i]) / 5; // Вычисляем корень квадратный и делим на 5
            c_size++; // Увеличиваем размер массива c
        }
    }

    // Сортировка массива c методом выбора
    for (int i = 0; i < c_size - 1; ++i) {
        int min_idx = i; // Индекс минимального элемента
        for (int j = i + 1; j < c_size; ++j) {
            if (c[j] < c[min_idx]) { // Если найден меньший элемент
                min_idx = j; // Обновляем индекс минимального элемента
            }
        }
        // Меняем местами текущий элемент с минимальным
        double temp = c[i];
        c[i] = c[min_idx];
        c[min_idx] = temp;
    }

    // Вывод упорядоченного массива c
    printf("Упорядоченный массив: ");
    for (int i = 0; i < c_size; ++i) {
        printf("%.2f ", c[i]);
    }
    printf("\n");

    // Освобождение выделенной памяти
    free(b);
    free(c);
    return 0;
}
