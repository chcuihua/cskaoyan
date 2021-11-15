//我自己写一个
int zheban (int a[], int key, int n){
    int low,high,mid;
    low = 0;
    high = n-1;
    mid = (low+high)/2;
    while(low<high)
    {
        if(a[mid]==key)
            return mid;
        else if(a[mid]<key)
            low = mid+1;
        else if(a[mid]>key)
            high = mid-1;
    }
    return -1;
}

//咖啡版本
int sort(int list[], int n, int key){
	int l = 0, r = n-1;
	while(l < r){
		int mid = (l+r)>>1;
		if(list[mid]==key) return mid;
		else if(list[mid] > key) r = mid-1;
		else l = mid+1;
	}
	return -1;		//返回-1表示没有找到 
}
