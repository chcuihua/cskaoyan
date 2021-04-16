#define Maxsize 50
typedef struct{
    ElemType data[Maxsize];
    int top;
}SqStack;

//初始化
void InitStack(SqStack &S){
    S.top=-1;
}

//判栈空
bool StackEmtpy(SqStack S){
    if (S.top==-1)
        return true;
    else
        return false;
}

//进栈
bool push(SqStack &S,ElemType x){
    if(S.top==Maxsize-1)
        return false;
    else
        S.data[++S.top]=x;
        return true;
}

//出栈
bool pop(SqStack &S,Elemtype &x){
    if(S.top==-1)
        return false;
    else
        x=S.data[S.top--];
        return true;
}

//读栈顶元素
bool GetTop(SqStack S,ElemTpye &x){
    if(S.top==-1)
        return false;
    else
        x=S.data[S.top];
        return true;
}