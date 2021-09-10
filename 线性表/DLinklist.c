//定义
typedef struct DNode{
    ElemType data;
    struct DNode *prior,*next;
}DNode, *DLinklist;

//插入
s->next=p->next;    //1和2步必须在4步之前
p->next->prior=s;
s->prior=p;
p->next=s;

//删除节点p的后继节点q
p->next=q->next;
q->next->prior=p;
free(q);



//静态链表定义
#define MaxSize 50
typedef struct{
    ElemType data;
    int next;
}SLinkList[MaxSize];
