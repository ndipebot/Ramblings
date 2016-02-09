#include <stdlib.h>
#include <stdio.h>
#include "heapsort.h"


int main(int argc, char* argv[]) {

    //get the list of elements to be sorted
    int n = argc-1;
    int s[n];
    
    for (int i = 0; i < n; ++i) {
        s[i] = atoi(argv[i+1]);
    }
    
    //sort the input list
    heapsort(s, n);
    
    //print sorted list to console
    for (int i = 0; i < n; ++i) {
        printf("%d ", s[i]);
    }
    printf("\n");
    
    return 0;
}

void heapsort(int s[], int n){
    //make the heap
    priority_queue q;
    make_heap(&q, s, n);

    for (int i = 0; i < n; ++i) {
        s[i] = extract_min(&q);
    }
}

void make_heap(priority_queue *q, int s[], int n) {
    //fill up the queue with unsorted array
    for (int i = 0; i < n; ++i){
        q->q[i+1] = s[i];
    }

    q->n = n+1;
    
    //start from last element and bubble down to right position
    for (int i = q->n; i > 0; --i){
        bubble_down(q, i);
    }
}

void bubble_down(priority_queue *q, int p) {
    
    int c = pq_child(p);
    int min_index = p;

    for (int i = 0; i < 2; ++i) {
        if(q->q[min_index] > q->q[c+i] && q->n > (c+i))
            min_index = c+i;
    }

    if(min_index != p) {
        pq_swap(q, p, min_index);
        bubble_down(q, min_index);
    }
}

int pq_child(int p) {
    return 2*p;
}

void pq_swap(priority_queue *q, int p, int c) {
    //swap variable without using temporary variable
    q->q[p] = q->q[c] + q->q[p];
    q->q[c] = q->q[p] - q->q[c];
    q->q[p] = q->q[p] - q->q[c];
    
}

int extract_min(priority_queue *q) {
    int minimum;
    
    if(q->n <= 0) return -1;
    minimum = q->q[1];
    q->q[1] = q->q[q->n];
    q->n = q->n - 1;
    bubble_down(q, 1);

    return minimum;
}
