void QuickSort(ElemType A[] ,int low ,int high){
    if(low<high){                               //递归跳出条件
        //partition()是划分操作
        int pivotpos=Partition(A,low,high);     //划分
        QuickSort(A,low,pivotpos-1);            //依次对两个子表进行递归操作
        QuickSort(A,pivotpos+1,high);
    }
}

int Partition(ElemType A[] ,int low ,int high){
    ElemType pivot=A[low];                      //以第一个元素为枢轴，进行划分
    while(low<high){                            //循环跳出条件
        while(low<high && A[high] >=pivot) --high;
        A[low]=A[high];                         //比枢轴小的元素放到左端
        while(low<high && A[low] <=pivot) ++high;
        A[high]=A[low];                         //比枢轴大的元素放到右端
    }
    A[low]=pivot;
    return low;                                 //返回枢轴最终位置
}

//空间效率：由于是递归的，最好情况为O(logn)，最坏情况进行n-1次调用，栈的深度是O(n)，平均情况栈的深度为O(logn)
//时间效率：最坏情况每层都不对称，即初始序列基本有序或者基本逆序，复杂度为O(n^2)，平均情况为O(nlogn)与最佳情况接近
//不稳定