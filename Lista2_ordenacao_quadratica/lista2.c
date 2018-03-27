#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Auxiliar functions
void print_arranjo(int array[], int n);
void create_random_array(int array[], int n);
void create_crescent_array(int array[], int n);
void create_decreasing_array(int array[], int n);
double calculate_time(int array[], int n);

// Sorting functions
void selection_sort(int array[], int size);
void bubble_sort(int array[], int size);
void selection_sort(int array[], int size);
void insertion_sort(int array[], int size);


int main() {

  int i, size;
  printf("Indique o número de elmentos: ");
  scanf("%d", &size);
  int array[size];

  create_decreasing_array(array, size);

  double tempo_gasto_ordenacao = calculate_time(array, size);
  // print_arranjo(A, n);
  printf("Tempo gasto é: %g ms\n", tempo_gasto_ordenacao);

  return 0;
}

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

void insertion_sort(int array[], int size) {
  int i, j, key;
  for(i = 1; i < size; i++) {
    key = array[i];
    for(j = i; j > 0 && key < array[j-1]; j--) {
      array[j] = array[j-1];
    }
    array[j] = key;
  }
}

void shell_sort(int array[], int size) {
  int i, j, gap = 1, key;

  while(gap < size/3) {
    gap = gap * 3 + 1;
  }

  while(gap > 0) {
    for(i = 1; i < size; i++) {
      key = array[i];
      for(j = i; j >= gap && key < array[j-gap]; j -= gap) {
        array[j] = array[j-gap];
      }
      array[j] = key;
    }
    gap /= 3;
  }
}

// void counting_sort(int array[], int size) {
//     static unsigned int count[100000];
//
//     for(int i = 0; i < size; ++i) {
//         count[array[i]]++;
//     }
//
//     for(int i = 0, k = 0; i < 100000; ++i) {
//         for(int j = 0; j < count[i]; ++j) {
//             array[k++] = i;
//         }
//     }
// }

void print_arranjo(int array[], int n) {
  int i;
  printf("[");
  for(i = 0; i < n - 1; i++) {
    printf("%d, ", array[i]);
  }
  printf("%d]\n", array[i]);
}

void create_random_array(int array[], int n) {
  int i;
  srand(time(NULL));
  for(i = 0; i < n; i++) {
    array[i] = rand() % 100;
  }
}

void create_crescent_array(int array[], int n) {
  int i;
  for(i = 0; i < n; i++) {
    array[i] = i+1;
  }
}

void create_decreasing_array(int array[], int n) {
  int i;
  for(i = 0; i < n; i++) {
    array[i] = n-i;
  }
}

// Calculate time in miliseconds
double calculate_time(int array[], int n) {
  double tempo = 0;
  clock_t contador[2];

  contador[0] = clock();
  shell_sort(array, n);
  contador[1] = clock();

  tempo = (contador[1] - contador[0]) * 1000.0 / CLOCKS_PER_SEC;

  return tempo;
}
