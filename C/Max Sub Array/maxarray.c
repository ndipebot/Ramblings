#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "maxarray.h"


int main(int argc, char* argv[]) {

  int B[argc-1];
  int A[argc-2];
  
  for (int i = 1; i < argc; ++i) {
    B[i-1] = atoi(argv[i]);
  }

  for (int i = 1; i < argc-1; ++i) {
    A[i-1] = B[i] - B[i-1];
  }


  int mid = (argc-2)/2;

  Sum final = global_max(A, 0, mid, argc-3);

  printf("Global sum is %d found between %d and %d \n",final.sum, final.min, final.max+1);

  
}

Sum global_max(int* A, int start, int mid, int end) {

  if(start == end){
    Sum output = {A[start], start, end};
    return output;
  }else {
    Sum left = global_max(A, start, (start+mid)/2, mid);
    Sum right = global_max(A, mid+1, (end+mid+1)/2, end);

    Sum cross = find_crossing(A, start, mid, end);
    
    if(left.sum >= right.sum && left.sum >= cross.sum) {
      return left;
    }else if(right.sum >= left.sum && right.sum >= cross.sum) {
      return right;
    } else
      return cross;
  }

}


Sum find_crossing(int* A, int start, int mid, int end) {

  int left_sum = INT_MIN;
  int sum = 0;
  int max_i = mid;

  for (int i = mid; i >= start; --i) {
    sum += A[i];

    if(sum > left_sum) {
      left_sum = sum;
      max_i = i;
    }
    
  }

  int right_sum = INT_MIN;
  sum = 0;
  int max_j = mid;

  for(int i = mid+1; i <= end; i++) {
    sum += A[i];

    if(sum > right_sum) {
      right_sum = sum;
      max_j = i;
      
    }
  }

  Sum output = { right_sum + left_sum, max_i, max_j};

  return output;
  
}
