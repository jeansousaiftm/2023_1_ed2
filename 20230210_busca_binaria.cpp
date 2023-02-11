#include<stdio.h>

bool buscaBinaria(int v[], int n, int x) {
    int s = 0, e = n - 1;
    while (s <= e) {
        int m = (s + e) / 2;
        if (x == v[m]) {
            return true;
        } else if (x < v[m]) {
            e = m - 1;
        } else if (x > v[m]) {
            s = m + 1;
        }
    }
    return false;
}

int main() {

    int v[] = { 1, 4, 5, 8, 9, 15, 22, 38, 40, 45 };

    printf("%d\n", buscaBinaria(v, 10, 22));

    return 0;
}
