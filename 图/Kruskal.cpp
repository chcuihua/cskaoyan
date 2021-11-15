typedef struct Road
{
    int a, b; //一条边两个顶点
    int w; //数值
}Road;

Road road[maxsize];
int v[maxsize]; //并查集数组

int getRoot(int a) //从并查集集中找到根节点
{
    while( a != v[a]) 
        a = v[a];   //并查集中只有根节点才满足k == V[k]
    return a;
}

void Kruskal (MGraph G, int &sum, Road road[])
{
    int i = 0;
    int N, E, a, b;
    N = G.n;
    E = G.e;
    sum = 0;
    for( i = 0; i < n; ++i) 
        v[i]=i; //初始时每个顶点构成一个独自的并查集，n个顶点即有n个并查集
    sort(road, E); //对边按权值排序
    for( i = 0; i < E; ++i)
    {
        a = getRoot(road[i].a);
        b = getRoot(road[i].b);
        if( a != b)
        {
            v[a] = b;
            sum += road[i].w;
        }
    }
}
