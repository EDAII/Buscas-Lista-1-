#include <stdio.h>
#include <stdlib.h> // To use functions rand() and srand()
#include <time.h> // To use function time()

void create_random_array(int array[], int length);
void print_array(int array[], int length);

int main() {
  int length;

  printf("Indique o numero de elementos: ");
  scanf("%d", &length);
  int array[length];

  create_random_array(array, length);
  print_array(array, length);

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

void print_array(int array[], int length) {
  int i = 0;

  printf("[");
  for(i = 0; i < length - 1; i++) {
    printf("%d, ", array[i]);
  }
  printf("%d]\n", array[i]);
}
