#include <stdio.h>
#include <stdlib.h> // To use functions rand() and srand()
#include <time.h> // To use function time()

void create_random_array(int array[], int length);
void print_array(int array[], int length);
int sequential_search(int array[], int length, int wanted);
int sentinel_sequential_search(int array[], int length, int wanted);
int sequential_search_move_forward(int array[], int length, int wanted);
int sequential_search_transposition(int array[], int length, int wanted);


int main() {
  int length, wanted, index = -1;

  printf("Indique o numero de elementos: ");
  scanf("%d", &length);
  int array[length];

  printf("Indique um numero para procurar: ");
  scanf("%d", &wanted);

  create_random_array(array, length);
  print_array(array, length);

  index = sequential_search_transposition(array, length, wanted);

  if(index == -1) {
    printf("Numero nao encontrado\n");
  } else {
    printf("Numero encontrado no indice = %d\n", index);
  }

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

int sentinel_sequential_search(int array[], int length, int wanted) {
  int i = 0;

  // Adding the sentinel
  array[length] = wanted;

  // Go through the array searhing for the number
  for(i = 0; wanted != array[i]; i++);

  if(i < length) {
    return i; // Found the number
  } else {
    return -1;  // Number not found
  }
}

int sequential_search_move_forward(int array[], int length, int wanted) {
  int i = 0, swap;

  for(i = 0; i < length; i++) {
    if(array[i] == wanted) {
      // Move found number to the first position
      swap = array[0];
      array[0] = array[i];
      array[i] = swap;

      return i; // Found the number
    }
  }
  return -1;  // Number not found
}

int sequential_search_transposition(int array[], int length, int wanted) {
  int i = 0, swap;

  for(i = 0; i < length; i++) {
    if(array[i] == wanted) {
      // Transposes found number with the previous
      swap = array[i-1];
      array[i-1] = array[i];
      array[i] = swap;

      return i; // Found the number
    }
  }

  return -1;  // Number not found
}
