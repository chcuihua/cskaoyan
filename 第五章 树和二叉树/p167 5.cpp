typedef struct node
{
    ElemType data;  //数据域
    struct node *fch,*nsib; //孩子与兄弟域
}*Tree;
int Leaves(Tree t){
    if(t==NULL)
        return 0;
    if(t->fch==NULL)
        return 1+Leaves(t->nsib);
    else
        return Leaves(t->fch)+Leaves(t->nsib);
}