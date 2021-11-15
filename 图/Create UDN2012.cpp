//设计一个图的数组表示存储结构，并编写采用数组表示法构造一个无向图的算法
//严P162
Status CreatUDN(MGraph &G){
    //采用数组（邻接矩阵）表示法，构造无向网G
    scanf(&G.vexnum, &G.arcnum, &IncInfo); //IncInfo为0则各弧不含其他信息
    for(i=0; i<G.vexnum; ++i) scanf(&G.vexs[i]); //构造顶点向量
    for(i=0; i<G.vexnum; ++i) //初始化邻接矩阵
        for(j=0; j<G.vexnum; ++j) G.arcs[i][j] = {INFINITY, NULL}; //{adj,info}
    for(k=0; k<G.arcnum; ++k){ //构造邻接矩阵
        scanf(&v1, &v2, &w); //输入一条边依附的顶点及权值
        i = LocateVex(G,v1); j=LocateVex(G,v2); //确定v1和v2在G中的位置
        G.arcs[i][j].adj = w; //弧<v1,v2>的权值
        if(IncInfo) Input(*G,arcs[i][j].info);//若弧含有相关信息，则输入
        G.arcs[j][i] = G.arcs[i][j]; //置<v1,v2>的对称弧<v2,v1>
    }
    return OK;
}


//咖啡
#define MAXN 550					   //顶点数上限 
#define INF 0x3f3f3f3f				   //初始化距离无穷大 
int G[MAXN][MAXN];                     //邻接矩阵 
int get(int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			G[i][j] = INF;			  //初始化顶点间的距离 
		}
	}
	while(scanf("%d%d%d", &u, &v, &w)!=EOF){
		if(u < 0 || u >= n || v < 0 || v >= n) return -1;//若读入不符合要求的顶点则返回报错码-1 
		G[u][v] = G[v][u] = w;
	}
	return 1;
}
