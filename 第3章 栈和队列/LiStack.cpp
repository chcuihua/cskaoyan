#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Linknode{
    int data;
    struct Linknode *next;
}*LiStack,Lnode;

//不带头结点
//初始化
LiStack InitStack(LiStack &L){
    L=NULL;
    return L;
}

//进栈
LiStack push(LiStack &L,int x){
    Lnode *P;
    P = (Lnode*)malloc(sizeof(Lnode));
    P->data = x;
    P->next = L->next;
    L = P;
    return L;
}

//出栈
LiStack pop(LiStack &L,int &x){
    Lnode *P;
    P = L;
    x=P->data;
    L=P->next;
    free(P);
    return L;
}

//获取栈顶元素
bool GetTop(LiStack L,int &x){
    if(L!=NULL){
        x=L->data;
        return true;
    }
}


//判断空
bool StackEmpty(LiStack L){
    if(L==NULL)
        return true;
    else
        return false;
}

//带头节点
//初始化
LiStack InitStack2(LiStack &L){
    L=(LiStack)malloc(sizeof(Lnode));
    L->next=NULL;
}

//进栈
LiStack push2(LiStack &L,int x){
    Lnode *P;
    P=(LiStack)malloc(sizeof(Lnode));
    P->data=x;
    P->next=L->next;
    L->next=P;
    return L;
}

//出栈
LiStack pop2(LiStack &L,int &x){
    Lnode *P;
    P=L->next;
    x=P->data;
    L=P->next;
    free(P);
    return L;
}

//获取栈顶元素
bool GetTop2(LiStack L,int &x){
    if(L->next!=NULL){
        x=L->next->data;
        return true;
    }
    else
        return false;
}

//判空
bool StackEmpty2(LiStack L){
    if(L->next==NULL)
        return true;
    else
        return false;
}