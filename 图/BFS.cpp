//广度优先遍历，非递归算法
bool visited[MAX_VERTEX_NUM];
void BFSTraverse(Graph G){
    for(i=0;i<G.vexnum;++i)
        visited[i]=false;
    InitQueue(Q);
    for(i=0;i<G.vexnum;++i)
        if(!visited[i]) //如果没访问过
            BFS(G,i);
}
//初始化
void BFS(Graph G,int v){
    visit(v);
    visited[v]=true;
    Enqueue(Q,v);
    while(!isEmpty(Q)){
        DeQueue(Q,v);
        for(w=FirstNeighbor(G,v);w>=0;w=NextNeighbor(G,v,w))
            if(!visit[w]){
                visit(w);
                visit[w]=true;
                EnQueue(Q,w);
            }
    }
}
//最坏情况下，n个顶点都要入队，空间复杂度为O(|V|)
//邻接表法时，搜索顶点入队O(|V|)，访问边O(|E|)，时间复杂度为O(|V|+|E|)
//邻接矩阵时，搜索每个顶点邻接点所需时间为O(|V|)，时间复杂度为O(|V|^2)
