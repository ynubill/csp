#include <stdio.h>
#define N 5

void quickSortSp(int *x, int l, int r) {
    if (l < r) {
        int p = l;
        for (int i = l; i < r; i++) {
            if (x[i] < x[r]) {
                int tmp = x[p];
                x[p] = x[i];
                x[i] = tmp;
                p++;
            }
        }
        int tmp = x[p];
        x[p] = x[r];
        x[r] = tmp;
        quickSortSp(x, l, p - 1);
        quickSortSp(x, p + 1, r);
    }
}

void quickSort(int *x, int n) {
    quickSortSp(x, 0, n - 1);
}

int main() {
    int a[] = {8, 4, 7, 5, 1};
    quickSort(a, N);
    for (int i = 0; i < N; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }

    return 0;
}
