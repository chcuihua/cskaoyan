//树的存储结构
//双亲表示法
#define MAX_TREE_SIZE 100
typedef struct{
    ElemType data;
    int parent;
}PTNode;
typedef struct {
    PTNode nodes[MAX_TREE_SIZE];
    int n;
}PTree;
//求孩子时需要遍历整个结构

//孩子兄弟表示法
typedef struct CSNode{
    ElemType data;
    struct CSNode *firstchild,*nextsibling; //第一个孩子节点和兄弟节点
}CSNode,*CSTree;

