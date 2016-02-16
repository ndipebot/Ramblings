#ifndef quicksort_h
#define quicksort_h


int partition(int* A, int p, int r) {
    
    int i,j;
    i = j = p;
    int temp;
    
    for (int k = p; k < r; ++k) {
        if (A[k] > A[r]) {
            j++;
        } else {
            temp = A[k];
            A[k] = A[i];
            A[i] = temp;
            i++; j++;
        }
    }

    temp = A[r];
    A[r] = A[i];
    A[i] = temp;

    return i;
    

}

void quicksort(int* A, int p, int r) {

    if (p < r) {
        int q = partition(A, p, r);

        quicksort(A, p, q-1);

        quicksort(A, q+1, r);
    }

}

#endif
