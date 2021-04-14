# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct Node {
    int data;
    struct Node * pNext;
}NODE, * PNODE;

typedef struct Stack {

    PNODE pTop; // 指向栈顶元素
    PNODE pBottom; // 指向栈底元素的下一个没有实际含义的元素
}STACK, * PSTACK; // PSTACK 等价于 struct Stack *

// 函数声明
void init(PSTACK); // 初始化栈
void push(PSTACK, int); // 压栈操作
void traverse(PSTACK); // 遍历栈
bool empty(PSTACK); // 判断栈是否为空
bool pop(PSTACK, int *); // 出栈
void clear(PSTACK); // 清空栈内的元素


int main(void) {

    STACK S; // STACK 等价于 struct Stack

    int val;

    init(&S);

    push(&S, 1);
    push(&S, 2);
    push(&S, 3);
    push(&S, 4);
    push(&S, 5);
    traverse(&S);
    clear(&S);
    if ( pop(&S, &val) ) {
        printf("出栈成功！，出栈的元素为:%d\n", val);
    } else {
        printf("出栈失败!\n");
    }
    traverse(&S);

    return 0;
}

// 初始化栈
void init(PSTACK pS) {

    pS->pTop = (PNODE)malloc(sizeof(NODE)); // 让栈pS中的pTop成员指向一块新分配出的内存，这个新分配的内存就当作栈底元素的下面一个元素，方便栈的操作
    if (NULL == pS->pTop) {
        printf("动态内存分配失败！\n");
        exit(-1);
    } else {
        pS->pBottom = pS->pTop; // 初始时，栈为空，栈顶和栈底指向同一个元素
        // 要使栈底元素的指针域为空
        pS->pTop->pNext = NULL; // 也可以写成 pS->pBottom->pNext = NULL;
    }
}

// 压栈操作
void push(PSTACK pS, int val) {
    
    // 为要压入的元素分配一块新的内存
    PNODE pNew = (PNODE)malloc(sizeof(NODE));

    pNew->data = val; // 将数据赋给要压入的元素的数据域
    pNew->pNext = pS->pTop; // 让要压入的元素的指针域指向栈顶元素
    pS->pTop = pNew; // 让栈的栈顶指针指向刚刚压入的元素

    return;
}

void traverse(PSTACK pS) {

    // 为了不改变栈，使用一个临时变量来对栈进行遍历操作
    PNODE p = pS->pTop;

    /**
     * 每循环一次，对比p所指向的元素是否和pBottom指向的一样，如果指向相同，则代表p已经遍历到了栈底
     * 
     **/
    while (p != pS->pBottom) {
        printf("%d ", p->data);
        p = p->pNext; // 每循环一次，p 就指向下一个元素
    }
    printf("\n");

    return;
}

bool empty(PSTACK pS) {

    if (pS->pTop == pS->pBottom) {
        return true;
    } else {
        return false;
    }

}

/**
 * 把pS所指向的栈出栈一次，并把出栈的元素存入pVal形参所指向的变量中，
 * 如果出栈失败，返回false
 * 
 **/ 
bool pop(PSTACK pS, int *pVal) {

    if ( empty(pS) ) { // pS本身存放的就是S的地址
        return false;
    } else {

        PNODE r = pS->pTop;
        *pVal = r->data;
        pS->pTop = r->pNext;
        free(r);
        r = NULL;

        return true;
    }

}

void clear(PSTACK pS) {

    if ( empty(pS) ) {
        return;
    } else {
        // 定义两个临时变量
        PNODE p = pS->pTop; // 使p一开始指向pTop
        PNODE q = NULL;

        while (p != pS->pBottom) {
            q = p->pNext; // 让q为p的下一个元素，避免释放了p指向的元素时找不到下一个元素
            free(p);
            p = q; // 让p指向下一个元素，也就是q先保存好的元素
        }
        pS->pTop = pS->pBottom; // 清空元素之后，改变pTop的值
    } 

}