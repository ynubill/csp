#include <stdio.h>
#define N 5

void merge(int* x, int n1, int n2, int n3) {
    int l[n2 - n1];
    int r[n3 - n2];
    for (int i = n1; i < n2; i++) {
        l[i - n1] = x[i];
    }
    for (int i = n2; i < n3; i++) {
        r[i - n2] = x[i];
    }
    int cnt1 = 0;
    int cnt2 = 0;
    for (int i = n1; i < n3; i++) {
        if (cnt1 < n2 - n1 && l[cnt1] < r[cnt2] || cnt2 >= n3 - n2) {
            x[i] = l[cnt1++];
        } else {
            x[i] = r[cnt2++];
        }
    }
}

void mergeSortSp(int* x, int n1, int n2) {
    if (n1 + 1 < n2) {
        int m = (n1 + n2) / 2;
        mergeSortSp(x, n1, m);
        mergeSortSp(x, m, n2);
        merge(x, n1, m, n2);
    }
}

void mergeSort(int* x, int n) {
    mergeSortSp(x, 0, n);
}

int main() {
    int a[] = {8, 4, 7, 5, 1};
    mergeSort(a, N);
    for (int i = 0; i < N; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }

    return 0;
}
