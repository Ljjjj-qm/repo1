# include <stdio.h>

long f(long);

int main(void) {

    printf("%ld\n", f(100));

    return 0;
}
/**
 * 一个大规模的计算，借助比它更小规模的计算结果得出
 **/
// 假设n的值大于等于1，不考虑其他情况
long f(long n) {

    if (1 == n) {
        return 1;
    } else {
        return f(n-1) * n;
    }

}