# include <stdio.h>

long sum(long);

int main(void) {

    printf("%ld\n", sum(100));


    return 0;
}

long sum(long n) {

    if (1 == n) {
        return 1;
    } else {
        return n + sum(n-1);
    }
}