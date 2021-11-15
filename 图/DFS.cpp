bool visited[MAX_VERTEX_NUM];
void DFSTraverse(Graph G){
    for(v=0;v<G.vexnum;++v)
        visit[v]=false;
    for(v=0;v<G.vexnum;++v)
        if(!visited[v])
            DFS(G,v);
}
//初始化
void DFS(Graph G,int V){
    visit(v);
    visited[v]=true;
    for(w=FirstNeighbor(G,v);W>=0;W=NextNeighbor(G,v,w))
        if(!visit[w]){
            DFS(G,w);
        }
}
//空间复杂度为O(|V|)
//邻接矩阵表示时，查找每个顶点的邻接点所需时间为O(|V|)，时间复杂度为O(|V|^2)
//邻接表表示时，查找所有顶点的邻接点所需时间为O(|E|)，访问顶点所需时间为O(|V|)
//时间复杂度为O(|V|+|E|)