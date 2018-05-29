#include <iostream>
#include <cfloat> // FLT_MAX
#include <cmath>  // sqrt

using namespace std;
 
// Ponto nos eixos X e Y
struct Point {
    int x, y;
};
 
// Auxilia para comparar os pontos de acordo com X
int compareX(const void* a, const void* b) {
    Point *p1 = (Point *)a,  *p2 = (Point *)b;
    return (p1->x - p2->x);
}

// Auxilia para comparar os pontos de acordo com Y
int compareY(const void* a, const void* b) {
    Point *p1 = (Point *)a,   *p2 = (Point *)b;
    return (p1->y - p2->y);
}
 
// Calcula a distância entre dois pontos
float distance_between(Point p1, Point p2) {
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
                 (p1.y - p2.y)*(p1.y - p2.y)
               );
}
 
// Calcula menor distância na faixa
float stripClosest(Point strip[], int size, float min_distance) {
    float min = min_distance; 
 
    // Ordena os pontos com base no eixo Y
    qsort(strip, size, sizeof(Point), compareY); 
 
    // Percorre os pontos até encontrar a menor distância
    for (int i = 0; i < size; ++i)
        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (distance_between(strip[i],strip[j]) < min)
                min = distance_between(strip[i], strip[j]);
 
    return min;
}
 
 // Função que enconta a menor distância
float closest(Point Points[], int number_of_points) {

    // Se só tiver um ponto, retornar infinito
    if (number_of_points == 1)
        return FLT_MAX;
 
    // Encontara o ponto médio
    int mid = number_of_points / 2;
    Point midPoint = Points[mid];
 
    // Dividir
    float distance_left = closest(Points, mid);
    float distance_right = closest(Points + mid, number_of_points - mid);
 
    // Encontra a menor distancia em ambos os lados
    float min_distance = min(distance_left, distance_right);
 
    // Cria a faixa em torno do ponto médio
    Point strip[number_of_points];
    int j = 0;
    for (int i = 0; i < number_of_points; i++)
        if (abs(Points[i].x - midPoint.x) < min_distance)
            strip[j] = Points[i], j++;
 
    // Encontra a menor distancia na faixa
    return min(min_distance, stripClosest(strip, j, min_distance) );
}
 
int main() {
    // Conjunto de pontos no plano
    Point Points[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};

    int number_of_points = sizeof(Points) / sizeof(Points[0]);

    // Ordena os pontos com base no eixo X
    qsort(Points, number_of_points, sizeof(Point), compareX);

    printf("The smallest distance is %f \n", closest(Points, number_of_points));
    
    return 0;
}