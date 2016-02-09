#ifndef heapsort_h
#define heapsort_h

#define QUEUE_SIZE 100

typedef struct {
    int q[QUEUE_SIZE];
    int n;

} priority_queue; 

//returns of the immediate child of current element in queue 
int pq_child(int p);

//bubble the given element down the queue 
void bubble_down(priority_queue *q, int p);

//swap two elements in the queue 
void pq_swap(priority_queue *q, int p, int c);

//extract top element in queue and rebalance
int extract_min(priority_queue *q);


//make heap using proriority queue and elements to be sorted
void make_heap(priority_queue *q, int s[], int n);

void heapsort(int s[], int n);


#endif
