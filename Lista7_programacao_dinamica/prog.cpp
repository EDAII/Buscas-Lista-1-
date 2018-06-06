#include <iostream>

using namespace std;

int W[100], V[100];
int memo[100][100];

int knapsac(int i, int w);

int main() {
    int numero_de_itens;
    cout << "Indique o número de itens: ";
    cin >> numero_de_itens;

    // inicializa o memo com -1
    memset(memo, -1, sizeof memo);

    int peso_maximo;
    cout << "Indique o peso máximo: ";
    cin >> peso_maximo;

    for (int i = 0; i < numero_de_itens; ++i) {
        printf("\nQual o valor do item %d? ", i + 1);
        scanf("%d", &V[i]);
        printf("Qual é o peso do item %d? ", i + 1);
        scanf("%d", &W[i]);
    }

    printf("\nO valor máximo é %d reais.\n", knapsac(numero_de_itens - 1, peso_maximo)); 

    return 0;
}

int knapsac(int i, int w) {

    // item invalido ou mochila cheia
    if(i < 0 || w <= 0) {
        return 0;
    }

    // já calculou aquele valor
    if(memo[i][w] != -1) {
        return memo[i][w];
    }

    // peso do item maior q o disponível
    if(W[i] > w) {
        // knapsac(i-1, w) = retira o item e mantem o peso
        return memo[i][w] = knapsac(i-1, w);
    }

    return memo[i][w] = max(
        knapsac(i-1, w), // nao carrega o item
        knapsac(i-1, w - W[i]) + V[i] // carrega o item: tira o item, tira o peso e acrescenta o valor
    );
}