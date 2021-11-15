typedef struct BiTNode{
    TElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

int solve(BiTNode *p){
    if(!p) return 0;
    else if(p->lchild = NULL && p->rchild == NULL) return 1;
    else return solve(p->lchild)+solve(p->rchild);
}