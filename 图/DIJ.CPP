void shortestpath_DIJ(MGraph G, int v0, int dist[], int path[])
{
    int set[Maxsize];//标记数组，set[v1]=0表示vi在T中尚未加入s中（s是已加入最短路径顶点）
    int min,i,j,u;
    //初始化开始
    for( i=0; i<G.n; ++i )
    {
        dist[i] = G.edges[v0][i];//dist[vi]表示当前已经找到的从v0到每一个终点vi的最短路径长度
        set[i] = 0;
        if( G.edges[v0][i] < INF)//path[vi]保存了从v0到vi最短路径上vi的前一个顶点
            path[i] = v0;
        else
            path[i] = -1;
    }
    set[v0] = 1;path[v0] = -1;
    //核心算法开始
    for ( i=0; i<G.n-1; ++i)
    {
        min = INF;
        //这个循环每次从剩余顶点中选出一个顶点，通往这个顶点的路径在通向所有剩余
        //顶点的路径中是长度最短的
        for( j=0; j<G.n; ++j)
        {
            if(set[j] == 0 && dist[j] < min)
            {
                u = j;
                min = dist[j];
            }
        }
        set[u] = 1;
        for( j=0; j<G.n; ++j)
        {
            //判断顶点u的加入是否会出现通往顶点j的更短的路径，如果出现，则改变
            //原来路径及其长度，否则上面也不做
            if( set[j] == 0 && dist[u] + G.edges[u][j] < dist[j])
            {
                dist[j] = dist[u] +G.edges[u][j];
                path[j] = u;
            }
        }
    }

}
//总结，本题严版《数据结构》P189，有出算法填空的可能
//本答案来自19版《天勤》，简单易懂代码稍长，学长建议大家记住代码时
//如代码多种，选自己可以理解的那种来记，千万别死记
//因为"死记"部分到考场上一紧张就大脑空白，总之"理解"万岁！