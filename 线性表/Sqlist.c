//线性表的顺序存储
#define Maxsize 50
typedef struct{
    ElemType Data[Maxsize];
    int length;
}Sqlist;

//动态分配
#define InitSize 100
typedef struct{
    ElemType *data;  //指示动态分配数组的指针
    int MaxSize,length;
}Sqlist;

//初始化语句
//c
L.data=(ElemType)*malloc(sizeof(ElemType)*InitSize)
//cpp
L.data=new ElemType[InitSize];

//基本操作实现
//插入
bool ListInsert(SqList &L,int i,ElemType e){ //传入线性表L，位序i，元素e
    if(i<1||i>L.length+1)  //范围小于1或大于长度+1
        return false;
    if(L.length>=Maxsize)  //空间满了没
        return false;
    for(int j=L.length;j>=i;j--)
        L.data[j]=L.data[j-1];
        L.data[i-1]=e;
        L.length++;
        return true;
}
//时间复杂度：最好情况O(1)，最坏情况O(n)，平均情况O(n) 书P14

//删除
bool ListDelete(SqList &L,int i,Elemtype &e){ //传入线性表L，位序i，接受元素e
    if(i<1||i>L.length)  //范围小于1或大于长度
    e=L.data[i-1];
    for(int j=i;j<L.length;j++)
        L.data[j-1]=L.data[j];
    L.length--;
    return true;
}
//时间复杂度：最好情况O(1)，最坏情况O(n)，平均情况O(n) 书P15

//按值查找（顺序查找）
int Location(SqList L,ElemType e){  //传入顺序表L，值e
    int i;
    for(i=0;i<L.length;i++)
        if(L.data[i]==e)
            return i+1;
    return 0;
}
//时间复杂度：最好情况O(1)，最坏情况O(n)，平均情况O(n) 书P15