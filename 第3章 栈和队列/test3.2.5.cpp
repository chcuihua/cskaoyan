int EnQueue1(SqQueue &Q,ElemType x){
    if (Q.front==Q.rear && Q.tag=1)
        return 0;
    Q.data[Q.rear]=x;
    Q.rear=(Q.rear+1)%Maxsize;
    Q.tag=1;
    return 1;
}

int DeQueue1(SqQueue &Q,ElemType &x){
    if(Q.front==Q.rear && Q.tag==0)
        return 0;
    x=Q.data[Q.front];
    Q.front=(Q.front+1)%Maxsize;
    Q.tag=0;
    return 1;
}