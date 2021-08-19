//邻接矩阵法
#define MaxVertexNum 100
typedef char VertexType;                        //顶点的数据类型
typedef int EdgeType;                           //带权图比中边上权值的数据类型
typedef struct{
    VertexType Vex[MaxVertexNum];               //顶点表
    EdgeType Edge[MaxVertexNum][MaxVertexNum];  //邻接矩阵，边表
    int vexnum,arcnum;                          //图当前顶点数和弧数
}MGraph;
//空间复杂度为O(n^2)，n为顶点数


//邻接表法
#define MaxVertexNum 100
typedef struct AcrNode{                         //边表节点
    int adjvex;                                 //该弧指向的顶点的位置
    struct ArcNode*next;                        //指向下一条弧的指针
    //InfoType info;                            //网的边权值
}ArcNode;

typedef struct VNode{                           //顶点表节点
    VertexType data;                            //顶点信息
    ArcNode *first;                             //指向第一条依附该顶点的弧的指针
}VNode,AdjList[MaxVertexNum];

typedef struct{                                 
    AdjList vertices;                           //邻接表
    int Vexnum,arcnum;                          //图的顶点和弧数
}ALGraph;
//容易找到所有边，但是不容易判断两个顶点是否存在边
//求顶点的出度容易，入度需要遍历全部邻接表
//邻接表表示不唯一
