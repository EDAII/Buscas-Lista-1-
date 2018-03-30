#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Auxiliar functions
void print_arranjo(int array[], int n);
void create_random_array(int array[], int n);
void create_crescent_array(int array[], int n);
void create_decreasing_array(int array[], int n);
double calculate_time(int array[], int n, int sorting_type);
void chose_type_of_array(int array[], int size);
int chose_sorting_type();

// Sorting functions
void selection_sort(int array[], int size);
void bubble_sort(int array[], int size);
void selection_sort(int array[], int size);
void insertion_sort(int array[], int size);

int main() {
  int i, size, sorting_type = 0;

  printf("Indique o número de elmentos: ");
  scanf("%d", &size);
  int array[size];

  chose_type_of_array(array, size);

  sorting_type = chose_sorting_type();

  printf("\nArray gerado:\n");
  print_arranjo(array, size);

  double sorting_time = calculate_time(array, size, sorting_type);

  printf("\nArray ordenado:\n");
  print_arranjo(array, size);

  printf("\nTempo gasto é: %g ms\n", sorting_time);

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
double calculate_time(int array[], int n, int sorting_type) {
  double tempo = 0;
  clock_t contador[2];

  switch (sorting_type) {
    case 1:
      contador[0] = clock();
      selection_sort(array, n);
      contador[1] = clock();
      break;
    case 2:
      contador[0] = clock();
      bubble_sort(array, n);
      contador[1] = clock();
      break;
    case 3:
      contador[0] = clock();
      insertion_sort(array, n);
      contador[1] = clock();
      break;
    default:
      contador[0] = clock();
      shell_sort(array, n);
      contador[1] = clock();
  }

  tempo = (contador[1] - contador[0]) * 1000.0 / CLOCKS_PER_SEC;

  return tempo;
}

void chose_type_of_array(int array[], int size) {
  int array_type = 0;

  do {
    printf("\n\tTipo de array:\n");
    printf("1: Crescente\n");
    printf("2: Decrescente\n");
    printf("3: Aleatorio\n");
    scanf("%d", &array_type);
  } while(array_type < 1 || array_type > 3);

  switch (array_type) {
    case 1:
      create_crescent_array(array, size);
      break;
    case 2:
      create_decreasing_array(array, size);
      break;
    default:
      create_random_array(array, size);
  }
}

int chose_sorting_type() {
  int sorting_type = 0;

  do {
    printf("\n\tEscolha a ordenação:\n");
    printf("1: Selection Sort\n");
    printf("2: Bubble Sort\n");
    printf("3: Insertion Sort\n");
    printf("4: Shell Sort\n");
    scanf("%d", &sorting_type);
  } while(sorting_type < 1 || sorting_type > 4);

  return sorting_type;
}
