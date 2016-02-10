#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "mergesort.h"


int main(int argc, char* argv[]) {

    int n = argc - 1;

    int A[n];

    for (int i = 0; i < n; ++i) {
        A[i] = atoi(argv[i+1]);
    }

     mergesort(A, 0, n-1);

    for (int i = 0; i < n; ++i){
        printf("%d ", A[i]);
    }
    printf("\n");
}
