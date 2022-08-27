#include <stdio.h>
#define N 5

void insertionSort(int *x, int n) {
    for (int i = 1; i < n; i++) {
        int tmp = x[i];
        int j = i - 1;
        while (x[j] > tmp && j >= 0) {
            x[j + 1] = x[j];
            j--;
        }
        x[j + 1] = tmp;
    }
}

int main() {
    int a[] = {8, 4, 7, 5, 1};
    insertionSort(a, N);
    for (int i = 0; i < N; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }

    return 0;
}
