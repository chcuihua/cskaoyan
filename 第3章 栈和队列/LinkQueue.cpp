#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
    int data;
    struct LinkNode *next;//简介格式LinkNode next;
}LinkNode;
typedef struct{
    LinkNode *front,*rear;
}LinkQueue;

//初始化
void InitQueue(LinkQueue &Q){
    Q.front=Q.rear=(LinkNode*)malloc(sizeof(LinkNode));
    Q.front->next=NULL;
}

//判队空
bool IsEmpty(LinkQueue Q){
    if (Q.front==Q.rear)
        return true;
    else
        return false;
}

//入队
void EnQueue(LinkQueue &Q,int x){
    LinkNode *s=(LinkNode*)malloc(sizeof(LinkNode));
    s->data=x;
    s->next=NULL;
    Q.rear->next=s;
    Q.rear=s;
}

//出队
bool DeQueue(LinkQueue &Q,int &x){
    if(Q.front==Q.rear)
        return false;
    LinkNode *p;
    p=Q.front->next;
    x=p->data;
    Q.front->next=p->next;
    if(Q.rear==p)
        Q.rear=Q.front;
    free(p);
    return true;
}