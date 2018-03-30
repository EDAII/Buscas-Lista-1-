# Relatório
  Este relatório tem com objetivo fazer uma análise sobre os algorítomos de ordenação quadrática O(n^2). Para cada algorítomo é apresentado seu código, uma tabela com número de elementos criados e seu gráfico. Para uma análise mais completa, foi escolhido um arranjo ordenado crescente, um decrescente e um aleatório para ver seu comportamento nos diferentes casos.

## Selection Sort

```c
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
```

![selection table](./img/selection_table.png)

![selection graph](./img/selection_graph.png)

## Bubble Sort
```c
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
```

![bubble table](./img/bubble_table.png)

![bubble graph](./img/bubble_graph.png)

## Insertion Sort
```c
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
```

![insertion table](./img/insertion_table.png)

![insertion graph](./img/insertion_graph.png)

## Shell Sort
```c
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
```

![shell table](./img/shell_table.png)

![shell graph](./img/shell_graph.png)

# Comparação entre Algorítmos

## Arranjo Crescente

![crescent table](./img/comp_cresc_table.png)

![crescent graph](./img/comp_cresc_graph.png)

## Arrajo Decrescente

![decreasing table](./img/comp_dec_table.png)

![decreasing graph](./img/comp_dec_graph.png)

## Arranjo Aleatório

![random table](./img/comp_random_table.png)

![random graph](./img/comp_random_graph.png)
