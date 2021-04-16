# include <stdio.h>
/**
 * 该函数用于执行汉诺塔操作，
 * 第一个参数为该汉诺塔的盘子数量
 * 第二个参数为盘子没有移动时的柱子
 * 第三个参数为需要借助的中间柱子
 * 第四个参数为要移入的目标柱子
 */ 
void hanoiExecute(int, char, char, char);

int main(void) {

    int n;

    printf("请输入要移动盘子的个数：");
    scanf("%d", &n);

    // 起始时，盘子全部是在A柱上，B柱用于中间的移动盘，C柱作为盘子最终要移入的目标盘
    hanoiExecute(n, 'A', 'B', 'C');


    return 0;
}

void hanoiExecute(int n, char a, char b, char c) {

    /**
     * 如果是1个盘子
     *      直接将A柱子上的盘子移到C柱子
     * 否则
     *      先将A柱子上的n-1个盘子借助C移到B
     *      直接将A柱子上的盘子从A移到C
     *      最后将B柱子上的n-1个盘子借助A移到C 
     */
    if (1 == n) {
        printf("将编号为%d的盘子直接从%c柱子移到%c柱子\n", n, a, c);
    } else {
        hanoiExecute(n-1, a, c, b);
        printf("将编号为%d的盘子直接从%c柱子移到%c柱子\n", n, a, c);
        hanoiExecute(n-1, b, a, c);
    }
}