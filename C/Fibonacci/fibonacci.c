#include <stdlib.h>
#include <stdio.h>

// 0(2^(n/2))
unsigned long long fibon_slow(int n) {
    if(n == 1 || n == 2)
        return 1;
    else
        return fibon_slow(n-1) + fibon_slow(n-2);
}

// O(n)
unsigned long long fibon_faster(int n){
    unsigned long long a = 1;
    unsigned long long b = 1;

    for (int i = 2; i < n; ++i) {
        unsigned long long temp = a;
        a = b;
        b = temp+b;
    }
    
    return b;    

}

// 0(logn)
unsigned long long fibon_fastest(int n) {
    int p = 0; int q = 1; unsigned long long a = 1; unsigned long long b = 1;
  
    while(n > 2) {
        if (n % 2 == 0) {
            int temp_p = p;
            p = p*p + q*q;
            q = q*q + 2*q*temp_p;

            n = n / 2;
        } else
            n = n - 1;

        unsigned long long temp_a  = a;
        a = p*a + q*b;
        b = p*b + q*temp_a + q*b;
    }
    
    return b;
}


int main(int argc, char* argv[]) {
    // get fibonacci number requested

    int  n = atoi(argv[1]);
    
    // 0 for exponential, 1 for linear, 2 for logarithmic
    int  option = atoi(argv[2]);


    unsigned long long fib;
    if (option == 0)
        fib = fibon_slow(n);
    else if (option == 1)
        fib = fibon_faster(n);
    else
        fib = fibon_fastest(n);

    
    printf("%llu\n", fib);

    return 0;
}

