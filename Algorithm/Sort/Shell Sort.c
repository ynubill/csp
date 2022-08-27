#include <stdio.h>
#define N 5

void shellSort(int *x,int n) {
    int gap = n / 2;
    while (gap > 0) {
        for (int i = gap; i < n; i++) {
            int tmp = x[i];
            int j = i - gap;
            while (j >= 0 && x[j] > tmp) {
                x[j + gap] = x[j];
                j -= gap;
            }
            x[j + gap] = tmp;
        }
        gap /= 2;
    }
}

int main() {
    int a[] = {8, 4, 7, 5, 1};
    shellSort(a, N);
    for (int i = 0; i < N; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }

    return 0;
}
