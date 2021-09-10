//二叉排序树的非递归查找算法
BSTNode *BST_Search(BiTree T,ElemType key){
    while(T!==NULL&&key!=T->data){
        if(key<T->data) T=T->lchild;
        else T=T->child;
    }
    return T;
}
//若是平衡二叉树，查找长度为O(log2n)，若是单支树，查找长度为O(n)，查找长度用ASL表示

//二叉排序树插入算法
int BST_Insert(BiTree &T,KeyType k){
    if(T==NULL){
        T=(BiTree)malloc(sizeof(BSTNode));
        T->key=k;
        T->lchild=T->rchild=NULL;
        return 1;
    }
    else if(k==T->key)
        return 0;
    else if(K<T->key)
        return BST_Insert(T->lchild,k);
    else
        return BST_Insert(T->rchild,k);
}
//平均执行时间为O(log2n)

//构造二叉排序树
void Creat_BST(BiTree &T,KeyType str[],int n){
    T=NULL;
    int i=o;
    while(i<n){
        BST_Insert(Tmstr[i]);
        i++;
    }
}