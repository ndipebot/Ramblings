#ifndef merge_h
#define merge_h


void merge(int* A, int p, int q, int r) {
    

    //Store elements in temporary arrays for merging
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1+1], R[n2+1];
    
    //populate left temporary array
    for (int i = 0; i < n1; ++i) {
        L[i] = A[p+i];
    }
    L[n1] = INT_MAX;
    
    //populate right temporary array
    for (int i = 0; i < n2; ++i) {
        R[i] = A[q+1+i];
    }
    
    R[n2] = INT_MAX;
    
    //merge left and right arrays
    int j,k;
    j = 0; k = 0;
    for (int i = p; i < r+1; ++i) {
        if(L[j] < R[k]){
            A[i] = L[j];
            j++;
        }else {
            A[i] = R[k];
            k++;
        }
            
    }
    
}


void mergesort(int* A, int p, int r) {
    //calculate the midpoint of array

    if (p < r) {
        int middle = (r+p)/2;

        //Recursively sort the two halves
        mergesort(A, p, middle);
        mergesort(A, middle+1, r);
        
        //Recursively merge sorted halves
        merge(A, p, middle, r);
    }

}


#endif
