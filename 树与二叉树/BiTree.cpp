typedef struct BitNode{
    ElemType data;
    struct  BitNode *lchild,*rchild;
}BitNode,*BiTree;

//先序遍历
void PreOrder(BiTree T){
    if(T!==NULL){
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

//中序遍历
void InOreder(BiTree T){
    if(T!==NULL){
        InOreder(T->lchild);
        visit(T);
        InOreder(T->rchild);
    }
}

//后序遍历
void PostOrder(BitTree T){
    if(T!==NULL){
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}
//时间复杂度是O(n)，空间复杂度是O(n)


//层次遍历
void LevelOrder(BiTree T){
    InitQueue(Q);
    BiTree p;
    EnQueue(Q,T);
    while(!IsEmpty(Q)){
        DeQueue(Q,p);
        visit(p);
        if(p->lchild!==NULL);
            EnQueue(Q,p->lchild);
        if(p->rchild);
            EnQueue(Q,p->rchild);
    }
}

//线索二叉树的结构
typedef struct ThreadNode{
    ElemType data;
    struct ThreadNode *lchild,*rchild;
    int ltag,rtag;
}ThreadNode,*ThreadTree;
