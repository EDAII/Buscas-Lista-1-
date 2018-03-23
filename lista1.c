#include <stdio.h>
#include <stdlib.h> // To use functions rand() and srand()
#include <time.h> // To use function time()

void create_random_array(int array[], int length);
void print_array(int array[], int length);
int sequential_search(int array[], int length, int wanted);
int sentinel_sequential_search(int array[], int length, int wanted);
int sequential_search_move_forward(int array[], int length, int wanted);
int sequential_search_transposition(int array[], int length, int wanted);
int binary_search(int array[], int length, int wanted);
int binary_search_recursive(int array[], int start, int end, int wanted);
void search_options();

int main() {
  int length, wanted, index = -1, search_option = 0;
  char continue_search;
  int start=0;
	int end= length-1;

  // Continue the search?
  do {
    search_options();
    scanf("%d", &search_option);

    printf("\nIndique o numero de elementos: ");
    scanf("%d", &length);
    int array[length];

    printf("Indique um numero para procurar: ");
    scanf("%d", &wanted);

    create_random_array(array, length);
    printf("\nLista gerada:\n");
    print_array(array, length);

    switch (search_option) {
      case 1:
        index = sequential_search(array, length, wanted);
        break;
      case 2:
        index = sentinel_sequential_search(array, length, wanted);
        break;
      case 3:
        index = sequential_search_move_forward(array, length, wanted);
        printf("\nLista apos busca:\n");
        print_array(array, length);
        break;
      case 4:
        index = sequential_search_transposition(array, length, wanted);
        printf("\nLista apos busca:\n");
        print_array(array, length);
        break;
      case 5:
        index = binary_search(array, length, wanted);
        printf("\nLista apos busca:\n");
        print_array(array, length);
        break;
      case 6:
        binary_search_recursive(array, start, end, wanted);
        printf("\nLista apos busca:\n");
        print_array(array, length);
        break;
      default:
        index = -1;
    }

    if(index == -1) {
      printf("\nNumero nao encontrado\n");
    } else {
      printf("\nNumero encontrado no indice = %d\n", index);
    }

  printf("\nDeseja continuar? (S - sim/ N - nao): ");
  scanf(" %c", &continue_search);

} while(continue_search == 'S' || continue_search == 's');

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
  int i = 0, j = 0, swap;

  for(i = 0; i < length; i++) {
    if(array[i] == wanted) {
      // Move found number to the first position
      swap = array[i];
      for(j = i; j > 0; j--) {
        array[j] = array[j-1];
      }
      array[j] = swap;

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

int binary_search(int array[], int length, int wanted){

	int start=0;
	int end= length-1;
	int middle = (start+end)/2;

	while(middle!=start || middle!=end){
    if(wanted>array[end] || wanted< array[start]) return 0;

    middle = (start+end)/2;

    if(array[middle]==wanted) return 1;
    else if(array[middle] < wanted) start=middle+1;
    else if(array[middle] > wanted)	end=middle-1;
  }
  return 0;
}

int binary_search_recursive(int array[], int start, int end, int wanted){

	int middle = (start+end)/2;

	if(wanted>array[end] || wanted< array[start]) return 0;

	if(array[middle]==wanted) return 1;

	if(array[middle]< wanted)	binary_search_recursive(array, (middle +1), end, wanted);
	else if(array[middle]> wanted) binary_search_recursive(array, start, (middle -1), wanted);
}

void search_options() {
  printf("\n\tEscolha uma busca:\n\n");
  printf("1 - Busca sequencial\n");
  printf("2 - Busca sequencial com sentinela\n");
  printf("3 - Busca sequencial com mover para frente\n");
  printf("4 - Busca sequencial com tranposicao\n");
  printf("5 - Busca binaria\n");
  printf("6 - Busca binaria recursiva\n");
}
