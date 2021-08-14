//定义
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

//头插法建立单链表
LinkList List_HeadInsert(LinkList &L){
    LNode *S;int x;                     //S为新节点插入的中介,x为新节点的值
    L=(LinkList)malloc(sizeof(LNode));  //L为头节点，LinkList L？
    L->next==NULL;
    scanf("%d", &x);
    while(x!=9999){
        S=(LNode*)malloc(sizeof(LNode));
        S->data=x;
        S->next=L->next;
        L->next=s;
        scanf("%d",&x);
    }
    return L;
}
//每个节点插入时间为O(1)，时间复杂度为O(n)

//尾插法建立单链表
LinkList List_TailInsert(LinkList &L){
    int x;
    L=(LinkList)malloc(sizeof(LNode));
    LNode *s,*r=L;                      //s为新节点，r为尾指针
    scanf("%d", &x);
    while (x!=9999){
        s=(LNode*)malloc(sizeof(LNode));
        s->data=x;                      //操作结束后r和s都指向尾部
        r->next=s;
        r=s;
        scanf("%d", &x);
    }
    r->next=NULL;
    return L;
}
//时间复杂度同上


//按序号查找结点值
LNode *GetElem(LinkList L,int i){       //找第i个节点
    int j=1;
    LNode *p=L->next;                   //寻找指针p
    if(i==0)
        return L;
    if(i<1)
        return NULL;            
    while(p&&j<i){                      //循环
        p=p->next;
        j++;
    }
    return p;
}
//时间复杂度为O(n)


//插入节点操作
p=GetElem(L,i-1);                       //P为要插入位置的前驱节点
s->next=p->next;                        //s为新插入的节点
p->next=s;
//开销在于查找i-1个元素，时间复杂度为O(n)

//前插操作
s->next=p->next;                        //把s插入到p后，交换两者数据
p->next=s;
temp=p->data;
p->data=s->data;
s->data=temp;
//时间复杂度为O(1)


//删除节点操作
p=GetElem(L,i-1);                       //找到前驱节点P，q指向要删除的节点
q=p->next;
p->next=q->next;
free(q);
//开销在于查找i-1个元素，时间复杂度为O(n)

//删除节点操作2
q=p->next;                              //转为删除目标节点的下一节点，把下一节点的值赋给当前节点
p->data=p->next->data;
p->next=q->next;
free(q);
//时间复杂度为O(1)

//求表长操作
//设计节点计数器，每访问一个节点计数器就加一。时间复杂度为O(n)