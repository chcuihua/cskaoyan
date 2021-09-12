typedef struct LNode{
    int data;
    struct LNode *next;
}*LinkList,LNode;//链表


//数组逆置
void Reverse(int R[],int from,int to){
    int i ,temp;
    for(i=0 ; i<(to-from+1)/2 ;i++){
        temp=R[from+i];
        R[from+i]=R[to-i];
        R[to-i]=temp;
    }//Reverse
}
//时间复杂度为O(n)，空间复杂度为O(1)

//单链表逆置
LinkList Reverse_1(LinkList L){
    LNode *p, *r; //p为工作指针，r为p的后继
    p=L->next;
    L->next=NULL;   //先把头指针的L的next置NULL
    while(p!=NULL){
        r=p->next;
        p->next=L->next;
        L->next=p;
        p=r;
    }
    return L;
}

LinkList Reverse_2(LinkList L){
//一次遍历线性表L，并将结点指针反转
    LNode *pre,*p=L->next,*r=p->next;
    p->next=NULL;
    while(r!=NULL){
        pre=p;
        p=r;
        r=r->next;
        p->next=pre;
    }
    L->next=p;
    return L;
}
//算法的时间复杂度为O(n)，空间复杂度为O(1)


//10年统考真题
void Converse(int R[] ,int n , int p){
    Reverse(R,0,p-1);
    Reverse(R,p,n-1);
    Reverse(R,0,n-1);
}
//时间复杂度为O(n)，空间复杂度为O(1)