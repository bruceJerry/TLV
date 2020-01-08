#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

/*
range(2, int(pow(n, 0.5)) + 1)
*/

static bool IntIsPrime(uint32_t num)
{
    for (uint32_t i=2; i<(uint32_t)(pow((double)num, 0.5)) + 1; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// 100以内的质数
int main(void)
{
    bool isPrime = false;
    printf("Hello\n");
    for(uint32_t i=2; i<1000000;i++) {
        isPrime = IntIsPrime(i);
        if (isPrime) {
            printf("%u is a prime\n", i);
        }   
        else {
            //printf("%u is not a prime\n", i); 
        }   
    }
}
