//顺序表折半查找
int Binary_Search(Sqlist L,ElemType key){
    int low=0, high=L.TableLen-1, mid;
    while(low<high){
        mid=(low+high)/2;
        if(L.elem[mid]==key)
            return mid; //查找成功
        else if(L.elem[mid]>key)
            high=mid-1;
        else
            low=mid+1;
    }
    return -1;//查找失败
}
//平衡二叉树，平均ASL成功=log(n+1)-1
//时间复杂度为O(logn)

int zheBanSearch(int a[] ,int n ,int key){
    int low=0, high=n-1, mid;
    while(low<high){
        mid=(low+high)/2;
        if(a[mid]==key)
            return mid;
        else if(a[mid]>key)
            high=mid-1;
        else 
            low=mid+1;
    }
    return -1;
}