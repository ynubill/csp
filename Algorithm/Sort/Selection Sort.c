#include <stdio.h>
#define N 5

void selectionSort(int *x, int n) {
    int k;
    for (int i = 0; i < n - 1; i++) {
        k = i;
        for (int j = i + 1; j < n; j++) {
            if (x[j] < x[k]) {
                k = j;
            }
        }
        if (k != i) {
            int temp = x[k];
            x[k] = x[i];
            x[i] = temp;
        }
    }
}

int main() {
    int a[] = {8, 4, 7, 5, 1};
    selectionSort(a, N);
    for (int i = 0; i < N; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }

    return 0;
}
