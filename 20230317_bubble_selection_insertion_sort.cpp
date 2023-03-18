#include<stdio.h>

void imprimirVetor(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void troca(int v[], int a, int b) {
    int tmp = v[a];
    v[a] = v[b];
    v[b] = tmp;
}

void bubbleSort(int v[], int n) { // O(n^2)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (v[j] > v[j + 1]) {
                troca(v, j, j + 1);
                //imprimirVetor(v, n);
            }
        }
    }
}

void selectionSort(int v[], int n) { // O(n^2)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[i] > v[j]) {
                troca(v, i, j);
                imprimirVetor(v, n);
            }
        }
    }
}

void insertionSort(int v[], int n) { // O(n^2)
    for (int i = 1; i < n; i++) {
        int x = v[i], j;
        for (j = i - 1; j >= 0 && x < v[j]; j--) {
            v[j + 1] = v[j];
            //imprimirVetor(v, n);
        }
        v[j + 1] = x;
        //imprimirVetor(v, n);
    }
}



int main() {
    int v[] = { 5, 4, 3, 2, 1 };
    int n = 5;
    imprimirVetor(v, n);
    insertionSort(v, n);
    imprimirVetor(v, n);
    return 0;
}
