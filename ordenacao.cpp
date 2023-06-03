#include<stdio.h>
#include<string.h>

void imprime(char n[][100], int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%s", n[i]);
    }
}

void copiaVetor(char n1[][100], char n2[][100], int tam) {
    for (int i = 0; i < tam; i++) {
        strcpy(n2[i], n1[i]);
    }
}

void troca(char v[][100], int a, int b) {
    char tmp[100];
    strcpy(tmp, v[a]);
    strcpy(v[a], v[b]);
    strcpy(v[b], tmp);
}

void bubbleSort(char v[][100], int n) { // O(n^2)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (strcmp(v[j], v[j + 1]) > 0) {
                troca(v, j, j + 1);
                //imprimirVetor(v, n);
            }
        }
    }
}

void selectionSort(char v[][100], int n) { // O(n^2)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(v[i], v[j]) > 0) {
                troca(v, i, j);
            }
        }
    }
}

void insertionSort(char v[][100], int n) { // O(n^2)
    for (int i = 1; i < n; i++) {
        char x[100];
        strcpy(x, v[i]);
        int j;
        for (j = i - 1; j >= 0 && strcmp(x, v[j]) < 0; j--) {
            strcpy(v[j + 1], v[j]);
        }
        strcpy(v[j + 1], x);
    }
}

void merge(char v[][100], int s, int m, int e) {
    char tmp[e - s + 1][100];
    int i = s, j = m + 1, k = 0;
    while (i <= m && j <= e) {
        if (strcmp(v[i], v[j]) < 0) { // Esquerda é menor
            strcpy(tmp[k++], v[i++]);
        } else { // Direita é menor
            strcpy(tmp[k++], v[j++]);
        }
    }
    while (i <= m) {
        strcpy(tmp[k++], v[i++]);
    }
    while (j <= e) {
        strcpy(tmp[k++], v[j++]);
    }
    for (i = s, k = 0; i <= e; i++, k++) {
        strcpy(v[i], tmp[k]);
    }
}

void mergeSort(char v[][100], int s, int e) {
    if (s < e) {
        int m = (s + e) / 2;
        mergeSort(v, s, m);
        mergeSort(v, m + 1, e);
        merge(v, s, m, e);
    }
}

int main() {

    FILE *f;
    f = fopen("nomes2.txt", "r+");
    char nome[1001][100], nome2[1001][100];
    int i = 0;
    while (fgets(nome[i++], 100, f) != NULL);

    int op = 0;

    do {
        printf("1. Bubble\n");
        printf("2. Selection\n");
        printf("3. Insertion\n");
        printf("4. Merge\n");
        printf("5. Sair\n");
        scanf("%d", &op);

        copiaVetor(nome, nome2, i);

        if (op == 1) {
            bubbleSort(nome2, i);
            imprime(nome2, i);
        } else if (op == 2) {
            selectionSort(nome2, i);
            imprime(nome2, i);
        } else if (op == 3) {
            insertionSort(nome2, i);
            imprime(nome2, i);
        } else if (op == 4) {
            mergeSort(nome2, 0, i - 1);
            imprime(nome2, i);
        }

    } while (op != 5);

    return 0;
}
