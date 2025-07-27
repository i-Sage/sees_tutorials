#include <iostream>
using namespace std;

void sum(int vec1[], int vec2[], int result[]) {
    for (int i = 0; i < 3; i++) {
        result[i] = vec1[i] + vec2[i];
    }
}

void print_vector_sum(int vec[]) {
    for (int i = 0; i < 3; i++) {
        cout << vec[i] << ' ';
    }
    cout << endl;
}

int main() {
    int vector1[] = {3, 6, 9};
    int vector2[] = {5, 9, 10};

    int result_vector[3];
    sum(vector1, vector2, result_vector);
    print_vector_sum(result_vector);

    
}