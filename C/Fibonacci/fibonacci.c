#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>

// 0(2^(n/2))
uintmax_t fibon_slow(int n) {
    if(n == 1 || n == 2)
        return 1;
    else
        return fibon_slow(n-1) + fibon_slow(n-2);
}

// O(n)
uintmax_t fibon_faster(int n){
    uintmax_t a = 1;
    uintmax_t b = 1;

    for (int i = 2; i < n; ++i) {
        uintmax_t temp = a;
        a = b;
        b = temp+b;
    }
    
    return b;    

}

// 0(logn)
uintmax_t fibon_fastest(int n, uintmax_t a, uintmax_t b, int p, int q) {
    
    if(n == 1 || n==2)
        return b;
    else {
        if (n % 2 == 0) {
            int temp = p;
            p = p*p + q*q;
            q = q*q + 2*q*temp;
            return fibon_fastest(n/2, p*a + q*b, p*b+q*a+q*b, p, q);
        } else
            return fibon_fastest(n-1, p*a + q*b, p*b+q*a+q*b, p, q);
    }
}


int main(int argc, char* argv[]) {
    // get fibonacci number requested

    int  n = atoi(argv[1]);
    
    // 0 for exponential, 1 for linear, 2 for logarithmic
    int  option = atoi(argv[2]);


    uintmax_t fib;
    if (option == 0)
        fib = fibon_slow(n);
    else if (option == 1)
        fib = fibon_faster(n);
    else
        fib = fibon_fastest(n, 1, 1, 0, 1);

    

    printf("%ju\n", fib);

    return 0;
}

