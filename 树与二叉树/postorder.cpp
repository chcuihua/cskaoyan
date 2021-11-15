void postorder(BTNode *p)
{
    if(p!=NULL)
    {
        postorder(p->lchild);
        postorder(p->child);
        visit(p);
    }
}