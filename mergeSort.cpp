#include<stdio.h>

void merge(int v[], int s, int m, int e) {
    int tmp[e - s + 1];
    int i = s, j = m + 1, k = 0;
    while (i <= m && j <= e) {
        if (v[i] <= v[j]) { // Esquerda é menor
            tmp[k++] = v[i++];
        } else { // Direita é menor
            tmp[k++] = v[j++];
        }
    }
    while (i <= m) {
        tmp[k++] = v[i++];
    }
    while (j <= e) {
        tmp[k++] = v[j++];
    }
    for (i = s, k = 0; i <= e; i++, k++) {
        v[i] = tmp[k];
    }
}

void mergeSort(int v[], int s, int e) {
    printf("mergeSort(%d %d)\n", s, e);
    if (s < e) {
        int m = (s + e) / 2;
        mergeSort(v, s, m);
        mergeSort(v, m + 1, e);
        merge(v, s, m, e);
    }
}

void imprime(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {
    int v[] = { 4, 5, 3, 8, 7, 1, 2, 6 };
    imprime(v, 8);
    mergeSort(v, 0, 7);
    imprime(v, 8);
    return 0;
}
