//咖啡版本
#define MAXN 500
void solve(int G[][MAXN], int n){
	int *sort = (int *)malloc(n*sizeof(int));
	
	int *degree = (int *)malloc(n*sizeof(int));
	for(int i = 0; i < n; i++) degree[i] = 0;
	for(int i = 0; i < n; i++)
    {
		for(int j = 0; j < n; j++)
        {
			if(G[i][j]) degree[j]++;    //出度保存在degree
		}
	}
	int *queue = (int *)malloc(n*sizeof(int));
	int head = 0, tail = 0;     //队列头和队列尾
	int *vis = (int *)malloc(n*sizeof(int));    //vis描述数组初始入度是否为0
	for(int i = 0; i < n; i++) vis[i] = 0;
	for(int i = 0; i < n; i++){
		if(degree[i]==0){
			sort[cnt++] = i;
			queue[tail++] = i; //把入度为0的点加入队列
			vis[i] = 1;
		}
	}
	while(head!=tail){
		int u = queue[head++];      //u是入度为0的点
		for(int i = 0; i < n; i++){ 
			if(!vis[i] && G[u][i]==1){  //把u和i的边删除，i的度-1
				degree[i]-=1;
				if(degree[i]==0) queue[tail++] = i; //如果删除后出现了入度为0的点，则加入输出队列
			}
		}
	}
	if(cnt!=n) printf("该图不存在拓扑序列\n");
}
//我是感觉有关于sort的都可以删掉，然后最后一句改成if(head!=n) printf("该图不存在拓扑序列\n");