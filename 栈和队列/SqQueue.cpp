#include "malloc.h"
//定义
#define MaxSize 50
typedef struct{
    ElemType data[MaxSize];
    int front,rear;
}SqQueue;
//初始状态（队空条件）:Q.front==Q.rear==0
//进栈：队不满时，送值到队尾，rear+1
//出栈：队不空时，取队头的值，front+1

//循环队列书上P74
//初始Q.front==Q.rear=0
//队首指针进1：Q.front=(Q.front+1)%MaxSize
//队尾指针进1：Q.rear=(Q.rear+1)%MaxSize
//队列长度：(Q.rear+MaxSize-Q.front)&MaxSize



//初始化
void InitQueue(SqQueue &Q){
    Q.rear=Q.front=0;
}

//判队空
bool isEmpty(SqQueue Q){
    if(Q.rear==Q.front) return true;
    else return false;
}

//入队
bool EnQueue(SqQueue &Q,ElemType x){
    if((Q.rear+1)%MaxSize==Q.front) return false; //书上P74页第一种方式
    Q.data[Q.rear]=x;
    Q.rear=(Q.rear+1)&MaxSize;
    return true;
}


//出队
bool DeQueue(SqQueue &Q,ElemType &x){
    if(Q.rear==Q.front) return false;    //队空报错
    x=Q.data[Q.front];
    Q.front=(Q.front+1)%MaxSize;
    return true;
}


//链式存储
typedef struct{                         //链式队列节点
    ElemType data;
    struct LinkNode *next;
}LinkNode;

typedef struct{                         //链式队列
    LinkNode *front,*rear;
}LinkQueue;
//若不带头节点，Q.front==NULL且Q.rear==NULL时，链式队列为空

//初始化
void InitQueue(LinkQueue &Q){
    Q.front=Q.rear=(LinkNode*)malloc(sizeof(LinkNode)); //建立头结点
    Q.front->next=NULL;
}

//判队空
bool IsEmpty(LinkQueue Q){
    if(Q.front==Q.rear) return true;
    else return false;
}


//入队
void EnQueue(LinkQueue &Q,ElemType x){
    LinkNode *s=(LinkNode *)malloc(sizeof(LinkNode));
    s->data=x; s->next=NULL;
    Q.rear->next=s;
    Q.rear=s;
}


//出队
bool DeQueue(LinkQueue &Q,ElemType &x){
    if(Q.front==Q.rear) return false;       //队空
    LinkNode *p=Q.front->next;
    x=p->data;
    Q.front->next=p->next;
    if(Q.rear==p)                           //若只有一个结点
        Q.rear=Q.front;
    free(p);
    return true;
}



