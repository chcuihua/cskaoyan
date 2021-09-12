#ifndef CODE_LINKLIST_H
#define CODE_LINKLIST_H

#include <stdio.h>
#include <stdlib.h>

//定义单链表结点
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;

//初始化
bool InitList(LinkList &L){
    L = (LNode *)malloc(sizeof(LNode));
    if (L==NULL)
        return false;
    L->next = NULL;
    return true;
}

//输出链表相关的所有信息
void PrintList(LinkList L){
    LNode *p = L->next;
    int len = 0;
    while (p!=NULL){
        len++;
        printf("%d ->", p->data);
        p = p->next;
    }
    printf("NULL\n链表长度 = %d\n",len);
}

//双指针法，通过一次遍历找到中间结点
LNode * findMideNode(LinkList head){
    LNode *p=head;  //p指针，每次往后走一步
    LNode *q=head;  //q指针，每次往后走两步
    while(q->next!=NULL){
        q = q->next;
        if(q->next!=NULL)  //考虑到偶数个的情况
            q = q->next;
        p=p->next;
    }

    if(p==head)
        printf("一个空链表，让我找中间结点？你一定是在逗我~");
    else
        printf("中间结点的值为：%d\n",p->data);
    return p;
}

//双指针法，通过一次遍历找到倒数第k的结点
LNode * findDaoShuKNode(LinkList head, int k){
    LNode *p=head;
    LNode *q=head;

    int count=0;
    bool chong =false;//p指针要不要冲？
    while(q->next!=NULL){
        q = q->next;
        count++;
        if (count==k)
            chong = true;//q走到第k个结点时，p指针开冲
        
        if(chong)
            p=p->next;
    }

    if(p==head)
        printf("这个链表长度小于%d,并不存在倒数第k个结点\n",k);
    else
        printf("倒数第%d个结点的值为：%d\n",k,p->data);
    return p;
}

#define N 20 //接下来是测试代码
void test_LinkList(){
    LinkList head;
    InitList(head);
    LNode * p =head;
    for (int i=1; i<=N; i++){ //插入一些元素
        p->next = (LNode *)malloc(sizeof(LNode));
        p = p->next;
        p->data = i;
        p->next = NULL;
    }
    PrintList(head);//打出来看看

    findMideNode(head);

    findDaoShuKNode(head,3);
}

#endif //CODE_LINKLIST_H

