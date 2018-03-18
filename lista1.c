#include <stdio.h>
#include <stdlib.h> // To use functions rand() and srand()
#include <time.h> // To use function time()

void create_random_array(int array[], int length) {
  int i = 0, RANGE = 100;

  // Seed rand function
  srand(time(NULL));

  // Generate random elements and add on Array
  for(i = 0; i < length; i++) {
    array[i] = rand() % RANGE;
  }
}

int main() {
  int array_length;

  printf("Indique o numero de elementos: ");
  scanf("%d", &array_length);
  int array[array_length];

  create_random_array(array, array_length);

  return 0;
}
