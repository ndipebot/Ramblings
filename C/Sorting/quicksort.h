#ifndef quicksort_h
#define quicksort_h


int partition(int* A, int p, int r) {
    
    int i,j;
    i = j = p;
    int temp;
    
    for (int k = p; k < r; ++k) {
        //track the large elements in band
        if (A[k] > A[r]) {
            j++;
        } else {
            temp = A[k];
            A[k] = A[i];
            A[i] = temp;
            i++; j++;
        }
    }
    
    //move last element to pivot position
    temp = A[r];
    A[r] = A[i];
    A[i] = temp;

    return i;
    

}

void quicksort(int* A, int p, int r) {

    if (p < r) {
        //get pivot
        int q = partition(A, p, r);
        
        //recursively sort both sides of pivot
        quicksort(A, p, q-1);

        quicksort(A, q+1, r);
    }

}

#endif
