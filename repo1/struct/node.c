#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct Node {
    int data; // 数据域
    struct Node * pNext; // 指针域
}NODE, *PNODE; // NODE等价于struct Node PNODE等价于struct Node*

// 函数声明
PNODE create_list(); // 创建一个循环单链表
void traverse_list(PNODE pHead); // 遍历链表
bool is_empty(PNODE pHead); // 判断代码是否为空
int length_list(PNODE pHead); // 求链表的长度
bool insert_list(PNODE pHead, int pos, int val); // 向链表内部插入数据
bool delete_list(PNODE pHead, int pos, int * temp); // 删除链表中的元素 temp 可以当作一个容器，暂时存放要删除的数据
void sort_list(PNODE pHead); // 排序

int main(void)
{
    PNODE pHead = NULL; // 等价于 struct Node * pHead = NULL;

    pHead = create_list(); // create_list() 功能：创建一个非循环单链表，并返回该链表的头指针
    traverse_list(pHead);

    return 0;
}

PNODE create_list() 
{
    int len; // 用来存放有效节点的个数
    int i;
    int val; // 用来临时存放用户输入的节点的值

    // (PNODE)malloc(sizeof(NODE))分配了一个不存放有效数据的头结点，pHead是指向头结点的头指针
    PNODE pHead = (PNODE)malloc(sizeof(NODE));

    if (NULL == pHead) { // 如果头指针指向为空，则表示分配失败
        printf("分配失败，程序终止！\n");
        exit(-1);
    }

    // 声明一个链表指针变量，要使pTail永远指向链表的最新节点地址
    PNODE pTail = pHead; // 此时链表的第一个节点即为头结点pHead，所以pTail指向pHead
    pTail->pNext = NULL; // 让pTail的指针域为空，因为现在还没有生成新的节点

    printf("请输入需要生成的链表节点个数: len = ");
    scanf("%d", &len);

    for (i = 0; i < len; ++i) {
        printf("请输入第%d个节点的值: ", i+1);
        scanf("%d", &val);

        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        if (NULL == pNew) {
            printf("分配失败，程序终止！\n");
            exit(-1);
        }
        pNew->data = val; // 为新生成节点的数据域赋值
        pTail->pNext = pNew; // 使pTail的指向的指针域指向新的节点，这样就使pTail上次指向的节点的指针域指向了最新生成的节点
        pNew->pNext = NULL; // 让pTail的指针域为空，因为现在新生成的节点后面还没有生成更新生成的节点
        pTail = pNew; // 再次让pTail指向最新节点
    }
    return pHead;
}

void traverse_list(PNODE pHead)
{
    // 此时p指向头结点的后面一个节点，即第一个存放了有效数据的节点
    PNODE p = pHead->pNext;

    while (NULL != p) {
        printf("%d ", p->data);
        // 每循环一次，p就指向后一个节点
        p = p->pNext; 
    }
    printf("\n");

    return;
}

bool is_empty(PNODE pHead) {


    if (NULL == pHead->pNext) { // 如果头指针的指针域为空，则改链表为空
        return true;
    } else {
        return false;
    }
}

int length_list(PNODE pHead) {

    PNODE p = pHead->pNext; // 此时p指向第一个有效节点
    int len = 0; // 存放链表的长度

    if (p != NULL) { // 如果p指向的有效节点不为空，则 len 加 1
        ++len;
        p = p->pNext; // 再次使p指向下一个有效节点
    }

}

void sort_list(PNODE pHead) {

    /**
     * 狭义的算法与数据的存储方式密切相关
     * 广义的算法与数据的存储方式无关
     * 
     * 泛型：对数据不同的存储方式，他们的操作是相同的
    */
    int i, j, t;
    int len = length_list(pHead);
    PNODE p, q;
    for (i = 0, p = pHead->pNext; i < len-1; ++i, p = p->pNext) {
        for (j = i +1, q = p->pNext; j < len; ++j, q = q->pNext) {
            if (p->data > q->data) { // 类似于数组中的： a[i] > a[j]
                t = p->data; // 类似于数组中的： t = a[i]
                p->data = q->data; // 类似于数组中的： a[i] = a[j]
                q->data = t; // 类似于数组中的： a[j] = t
            }
        }
    }
    return;
}