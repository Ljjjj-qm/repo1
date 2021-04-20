# include <stdio.h>

void QuickSort(int * a, int low, int high);
int FindPos(int * a, int low, int high);

int main (void) {

    int a[6] = {2, 1, 0, 5, 4, 3};
    int i;

    QuickSort(a, 0, 5);

    for (i = 0; i < 6; ++i) 
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}

/**
 * 参数a 数组第一个元素的地址
 * 参数low 数组中需要排序的第一个下标
 * 参数high 数组中最后一个需要排序的下标
 */ 
void QuickSort(int * a, int low, int high) {

    int pos;

    if (low < high) {
        pos = FindPos(a, low, high);
        QuickSort(a, low, pos-1);
        QuickSort(a, pos+1, high);
    }
}

int FindPos(int * a, int low, int high) {

    int val = a[low];

    while (low < high) {
        while (low < high && a[high] >= val) {
            --high;
        }
        a[low] = a[high];
        while (low < high && a[low] <= val) {
            ++low;
        }
        a[high] = a[low];
    } // 终止while循环后，low和high一定是相等的
    a[low] = val;

    return high; // 返回的值可以是high和low，但不能是val、a[high]、a[low]
}