#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Auxiliar functions
void print_array(int array[], int n);
void create_random_array(int array[], int n);
void create_crescent_array(int array[], int n);
void create_decreasing_array(int array[], int n);
double calculate_time(int array[], int n, int sorting_type);
void chose_type_of_array(int array[], int size);
int chose_sorting_type();

// Sorting Functions: merge_sort and quick_sort
void merge_sort(int array[], int start, int end) {
    int size = end - start + 1;

    if (size <= 1) {
        return;
    }
    else if (size == 2) {
        if (array[start] > array[end]) {
            int swap_var = array[start];
            array[start] = array[end];
            array[end] = swap_var;
        }

        return;
    }

    int mid = start + size/2;

    merge_sort(array, start, mid);
    merge_sort(array, mid + 1, end);

    static int sub_array[1000];
    memcpy(sub_array, array + start, (mid - start + 1) * sizeof(int));

    int i, j, k;
    for(i = 0, j = mid + 1, k = start; i <= (mid - start) && j <= end; k++) {
        if (array[j] < sub_array[i]) {
            array[k] = array[j];
            j++;
        }
        else {
            array[k] = sub_array[i];
            i++;
        }
    }

    for(; i <= (mid - start); k++, i++)
      array[k] = sub_array[i];
}

void quick_sort(int array[], int start, int end) {
    int size = end - start + 1;
    if (size <= 1) {
        return;
    }

    int pivot_index = start;

    int lower_index = pivot_index + 1;
    for (int i = pivot_index + 1; i <= end; ++i) {
        if (array[i] < array[pivot_index]) {
            int swap_var = array[i];
            array[i] = array[lower_index];
            array[lower_index] = swap_var;

            lower_index++;
        }
    }

    int swap_var = array[pivot_index];
    array[pivot_index] = array[lower_index - 1];
    array[lower_index - 1] = swap_var;

    quick_sort(array, start, lower_index - 2);
    quick_sort(array, lower_index, end);
}

int main() {
  int i, size, sorting_type = 0;

  printf("Indique o número de elmentos: ");
  scanf("%d", &size);
  int array[size];

  chose_type_of_array(array, size);

  sorting_type = chose_sorting_type();

  printf("\nArray gerado:\n");
  print_array(array, size);

  double sorting_time = calculate_time(array, size, sorting_type);

  printf("\nArray ordenado:\n");
  print_array(array, size);

  printf("\nTempo gasto é: %g ms\n", sorting_time);

  return 0;
}

void print_array(int array[], int n) {
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
double calculate_time(int array[], int size, int sorting_type) {
  double tempo = 0;
  clock_t contador[2];

  switch (sorting_type) {
    case 1:
      contador[0] = clock();
      merge_sort(array, 0, size - 1);
      contador[1] = clock();
      break;
    default:
      contador[0] = clock();
      quick_sort(array, 0, size - 1);
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
    printf("1: Merge Sort\n");
    printf("2: Quick Sort\n");
    scanf("%d", &sorting_type);
  } while(sorting_type < 1 || sorting_type > 4);

  return sorting_type;
}
