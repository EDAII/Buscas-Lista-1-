#include <stdio.h>
#include <string.h>

void selection_sort(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        int min_i = i;

        for (int j = i + 1; j < size; ++j)
            if (array[j] < array[min_i]) min_i = j;

        if (i != min_i) {
            int swap_var = array[min_i];
            array[min_i] = array[i];
            array[i] = swap_var;
        }
    }
}

void bubble_sort(int array[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                int swap_var = array[j];
                array[j] = array[j + 1];
                array[j + 1] = swap_var;
            }
        }
    }
}

void counting_sort(int array[], int size) {
    static unsigned int count[100000];

    for(int i = 0; i < size; ++i) {
        count[array[i]]++;
    }

    for(int i = 0, k = 0; i < 100000; ++i) {
        for(int j = 0; j < count[i]; ++j) {
            array[k++] = i;
        }
    }
}
