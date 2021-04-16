#define Maxsize 50
typedef struct{
    int data[Maxsize];
    int front,rear;
}SqQueue;

//初始化
void InitSqQueue(SqQueue &Q){
    Q.rear=Q.front=0;
}

//判队空
bool isEmpty(SqQueue Q){
    if(Q.rear==Q.front)
        return true;
    else
        return false;
}

//入队
bool EnQueue(SqQueue &Q,int x){
    if((Q.rear+1)%Maxsize==Q.front)
        return false;
    Q.data[Q.rear]=x;
    Q.rear=(Q.rear+1)%Maxsize;
    return true;
}

//出队
bool DeQueue(SqQueue &Q,int &x){
    if(Q.front==Q.rear)
        return false;
    X=Q.data[Q.front]
    Q.front=(Q.front+1)%Maxsize;
    return true;
}