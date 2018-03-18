#include <stdio.h>
#include <stdlib.h> // To use functions rand() and srand()
#include <time.h> // To use function time()

void create_random_array(int array[], int length);
void print_array(int array[], int length);
int sequential_search(int array[], int length, int wanted);

int main() {
  int length, wanted, index = -1;

  printf("Indique o numero de elementos: ");
  scanf("%d", &length);
  int array[length];

  printf("Indique um numero para procurar: ");
  scanf("%d", &wanted);

  create_random_array(array, length);
  print_array(array, length);

  index = sequential_search(array, length, wanted);

  if(index == -1) {
    printf("Numero nao encontrado\n");
  } else {
    printf("Indice = %d\n", index);
  }

  return 0;
}

void create_random_array(int array[], int length) {
  int i = 0, RANGE = 100;

  // Seed rand function
  srand(time(NULL));

  // Generate random elements and add on Array
  for(i = 0; i < length; i++) {
    array[i] = rand() % RANGE;
  }
}

// Print formated array = [e1, e2, ... , eN]
void print_array(int array[], int length) {
  int i = 0;

  printf("[");
  for(i = 0; i < length - 1; i++) {
    printf("%d, ", array[i]);
  }
  printf("%d]\n", array[i]);
}

int sequential_search(int array[], int length, int wanted) {
  int i = 0;

  // Go through the array searhing for the number
  for(i = 0; i < length; i++) {
    if(array[i] == wanted) {
      return i; // Found the number
    }
  }
  return -1; // Number not found
}
