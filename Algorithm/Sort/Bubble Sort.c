#include <stdio.h>
#define N 5

void _heapAdjust(int *x, int k, int n) {
    int tmp = x[k];
    for (int i = 2 * k + 1; i < n; i = 2 * i + 1) {
        if (i + 1 < n && x[i] < x[i + 1]) {
            i++;
        }
        if (tmp > x[i]) {
            break;
        } else {
            x[k] = x[i];
            k = i;
        }
    }
    x[k] = tmp;
}

void heapSort(int *x, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        _heapAdjust(x, i, n);
    }
    for (int i = n - 1; i > 0; i--) {
        int tmp = x[i];
        x[i] = x[0];
        x[0] = tmp;
        _heapAdjust(x, 0, i);
    }
}

int main() {
    int a[] = {8, 4, 7, 5, 1};
    heapSort(a, N);
    for (int i = 0; i < N; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }

    return 0;
}
