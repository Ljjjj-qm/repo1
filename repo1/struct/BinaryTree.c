# include <stdio.h>
# include <malloc.h>

struct BTNode {
    
    char data;
    struct BTNode * pLchild; // p是指针 L是左 chile是孩子
    struct BTNode * pRchild; // R是右
};

struct BTNode * CreateBTree(void);
void PreTraverseBTree(struct BTNode *);
void InTraverseBTree(struct BTNode *);
void PostTraverseBTree(struct BTNode *);

int main(void) {

    struct BTNode * pT = CreateBTree();

    //PreTraverseBTree(pT);
    //InTraverseBTree(pT);
    PostTraverseBTree(pT);


    return 0;
}

/**
 * 
 * 静态构造二叉树 17.25
 *      A
 *    B   C
 *       D
 *         E
 */
struct BTNode * CreateBTree(void) {
    struct BTNode * pA = (struct BTNode *)malloc(sizeof(struct BTNode));
    struct BTNode * pB = (struct BTNode *)malloc(sizeof(struct BTNode));
    struct BTNode * pC = (struct BTNode *)malloc(sizeof(struct BTNode));
    struct BTNode * pD = (struct BTNode *)malloc(sizeof(struct BTNode));
    struct BTNode * pE = (struct BTNode *)malloc(sizeof(struct BTNode));

    pA->data = 'A';
    pB->data = 'B';
    pC->data = 'C';
    pD->data = 'D';
    pE->data = 'E';

    pA->pLchild = pB;
    pA->pRchild = pC;
    pB->pLchild = pB->pRchild = NULL;
    pC->pLchild = pD;
    pC->pRchild = NULL;
    pD->pLchild = NULL;
    pD->pRchild = pE;
    pE->pLchild = pE->pRchild = NULL;

    return pA;
}
/**
 * 先序遍历
 * 伪算法：
 * 先序访问根节点
 * 再先序访问左子树
 * 再先序访问右子树
 */
void PreTraverseBTree(struct BTNode * pT) {

    if (pT != NULL) {
        printf("%c ", pT->data);
        if (NULL != pT->pLchild) {
            PreTraverseBTree(pT->pLchild);
        }
        if (NULL != pT->pRchild) {
            PreTraverseBTree(pT->pRchild);
        }
        
    }

}

// 中序遍历
void InTraverseBTree(struct BTNode * pT) {

    if (pT != NULL) {
        if (NULL != pT->pLchild) {
            InTraverseBTree(pT->pLchild);
        }
        printf("%c ", pT->data);
        if (NULL != pT->pRchild) {
            InTraverseBTree(pT->pRchild);
        }
    }

}

// 后序遍历
void PostTraverseBTree(struct BTNode * pT) {

    if (pT != NULL) {
        if (NULL != pT->pLchild) {
            PostTraverseBTree(pT->pLchild);
        }
        
        if (NULL != pT->pRchild) {
            PostTraverseBTree(pT->pRchild);
        }
        printf("%c ", pT->data);
    }

}

