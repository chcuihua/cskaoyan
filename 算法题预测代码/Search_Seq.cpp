typedef struct{     //查找表的数据结构
    ElemType *elem; //元素存储空间基地址，建表时按实际长度分配,0号单元留空
    int Tablelen;
}SSTable;

int Search_Seq(SSTable ST,ElemType key){
    ST.elem[0]=key; //哨兵
    for(i=ST.Tablelen;ST.elem[i]!=key;--i); //在for循环中++i和i++输出结果相同，在一般情况下
    return i;                               //从后往前找，如果不存在该元素，在i=0时退出循环
}
//在for循环中++i和i++输出结果相同
//在一般情况下，i++使用的是一个暂存变量，然后返回的值是暂存变量，再自增
//++i是自增以后返回内存中的i，可以作为左值而i++不能
//等概率情况下ASL成功=(n+1)/2，ASL失败=n+1