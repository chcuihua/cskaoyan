//先序后继
ThreadNode *Nextnode(ThreadNode *p){
    if(p->rtag==0){
        if(p->ltag==0)
            return p->lchild;
        else
            return p->rchild;
    }
    else
        return p->rchild;
}
//后续前驱
ThreadNode *Nextnode(ThreadNode *p){
    if(p->ltag==0){
        if(p->rtag==0)
            return p->rchild;
        else
            return p->lchild;
    else 
        return p->lchild;
    }
}