# include <stdio.h>
# include <malloc.h>
# include <stdbool.h>

typedef struct Queue {

    int * pBase; // 代表一个数组的第一个元素的地址
    int front;
    int rear;
}QUEUE; // QUEUE 代表了struct Queue 类型

// 函数声明
void init(QUEUE *); // 队列初始化
bool en_queue(QUEUE *, int); // 向队列执行入队操作
void traverse_queue(QUEUE *); // 遍历队列
bool full_queue(QUEUE *); // 判断队列是否满了
bool out_queue(QUEUE *, int *); // 出队
bool empty_queue(QUEUE *); // 判断队列是否为空

int main(void) {

    QUEUE Q;
    int val;

    init(&Q);
    en_queue(&Q, 1);
    en_queue(&Q, 2);
    en_queue(&Q, 3);
    en_queue(&Q, 4);
    en_queue(&Q, 5);
    en_queue(&Q, 6);
    en_queue(&Q, 7);
    traverse_queue(&Q);

    if ( out_queue(&Q, &val) ) {
        printf("出队成功！出队的元素是：%d\n", val);
    } else {
        printf("出队失败！\n");
    }

    traverse_queue(&Q);


    return 0;
}

void init(QUEUE * pQ) {

    pQ->pBase = (int *)malloc(sizeof(int) * 6);
    pQ->front = 0;
    pQ->rear = 0;

}

bool full_queue(QUEUE * pQ) {

    if ( (pQ->rear + 1) % 6 == pQ->front ) {
        return true;
    } else {
        return false;
    }

}

/**
 * 执行两步操作
 * 1.把要入队的值插入队列
 * 2.把尾指针向后移
 */ 
bool en_queue(QUEUE * pQ, int val) {

    if ( full_queue(pQ) ) {
        return false;
    } else {
        pQ->pBase[pQ->rear] = val; // 表示把值放入数组中下标为pQ->rear的位置中
        pQ->rear = (pQ->rear+1) % 6; // 队尾指针向后移一位

        return true;
    }

}

void traverse_queue(QUEUE * pQ) {

    int i = pQ->front;

    while (i != pQ->rear) {
        printf("%d ", pQ->pBase[i]);
        i = (i+1) % 6;
    }
    printf("\n");

    return;

}

bool empty_queue(QUEUE * pQ) {

    if (pQ->rear == pQ->front) {
        return true;
    } else {
        return false;
    }

}

bool out_queue(QUEUE * pQ, int * pVal) {

    if ( empty_queue(pQ) ) {
        return false;
    } else {

        *pVal = pQ->pBase[pQ->front]; // 将要出队的元素取出，放入指针pVal所指向的*pVal变量中
        pQ->front = (pQ->front + 1) % 6; // 进行出队操作，将front向后移一位

        return true;
    }
}