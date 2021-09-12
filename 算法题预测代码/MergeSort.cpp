//Merge()的功能是将前后相邻的两个有序表归并为一个有序
Elemtype *B=(ElemType *)malloc((n+1)*sizeof(ElemType));//辅助数组B
void Merge(ElemType A[] , int low ,int mid ,int high){
    //表A的两段A[low...mid]和A[mid+1...high]各自有序，将它们合并成一个有序表
    for(int k=low ;k<=high ;k++ )
        B[k]=A[k];              //将A中所有元素复制到B中
    for(i=low ,j=mid+1 ,k=i ;i<=mid && j<=high ;k++ ){
        if(B[i] <= B[j])        //比较B的左右两段中的元素
            A[k]=B[i++];        //将较小值复制到A中
        else
            A[k]=B[j++];
    }//for
    while(i<=mid)   A[k++]=B[i++];//若第一个表未检测完，复制
    while(j<=high)  A[k++]=B[j++];//若第二个表未检测完，复制
}

void MergeSort(ElemType A[] ,int low ,int high){
    if(low<high){
        int mid=(low + high)/2; //从中间划分两个子序列
        MergeSort(A,low,mid);   //对左子序列进行递归排序
        MergeSort(A,mid+1,high);//对右子序列进行递归排序
        Merge(A,low,mid,high);  //归并
    }//if
}

//空间复杂度：Merge()操作中，辅助空间为n个单元，O(n)
//时间复杂度：每趟归并排序的时间复杂度为O(n)，共需进行logn向上取整趟归并，算法的时间复杂度为O(nlogn)
//稳定