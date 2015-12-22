
  typedef struct Sum{
    int sum;
    int min;
    int max;
  } Sum;

Sum find_crossing(int* A, int start, int mid, int end);

Sum find_max(int *A, int start, int end);

Sum global_max(int* A, int start, int mid, int end);
