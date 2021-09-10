#include <stdbool.h>
//定义
#define MaxSize 50
typedef struct{
    Elemtype data[MaxSize];
    int top;
}SqStack;

//初始化
void InitStack(SqStack &S){
    S.top=-1;
}

//判栈空
bool StackEmpty(SqStack S){
    if(S.top==-1)
        return true;
    else
        return false;
}

//进栈
bool Push(SqStack &S,ElemType x){
    if(S.top)=MaxSize-1;            //注意是MaxSieze-1
        return false;
    S.data[++S.top]=x;              //指针先加一，再入栈
    return true;
}


//出栈
bool Pop(SqStack &S,ElemType &x){
    if(S.top==-1)
        return false;
    x=S.data[S.top--];              //先出栈，指针再减一
    return true;
}

//读栈顶元素
bool GetTop(SqStack S,ElemType &x){
    if(S.top==-1)
        return false;
    X=S.data[S.top];
    return true;
}

//链栈定义
typedef struct Linknode{
    ElemType data;
    struct Linknode *next;
}*LiStack;