/*图的邻接矩阵表示*/
#define INFINITY 65535 /* ∞设为双字节无符号整数的最大值65535*/
#define MaxVertexNum 100  /* 最大顶点数设为100 */
typedef int Vertex;
typedef int WeightType;
typedef char DataType;

typedef struct ENode *PtrToENode;
typedef PtrToENode Edge;
struct ENode{
	Vertex V1,V2;
	WeightType Weight;
};

typedef struct GNode *PtrToGNode;
struct GNode{
	int Nv;/* 顶点数 */
    int Ne;  /* 边数   */
	WeightType G[MaxVertexNum][MaxVertexNum];
	DataType Data[MaxVertexNum]; 
	/* 注意：很多情况下，顶点无数据，此时Data[]可以不用出现 */
};
typedef PtrToGNode MGraph;

MGraph CreatGraph(int VerTexNum){
	Vertex V,w;
	MGraph Graph;
	Graph = (Graph)malloc(sizeof(struct GNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	for(V = 0;V<Graph->Nv;V++){
		for(W=0;W<Graph->Nv;W++){
			Graph->G[V][W] = INFINITY;
		}
	} 
	return Graph;
}

void InsertEdge(MGraph Graph,Edge E){
	Graph->G[E->V1][E->V2] = E->Weight;
	/* 若是无向图，还要插入边<V2, V1> */
     Graph->G[E->V2][E->V1] = E->Weight;
}

MGraph BuildGraph(){
	MGraph Graph;
	Edge E;
	Vertex V;
	int Nv,i;
	scanf("%d",&Nv);
	Graph = CreatGraph(Nv);
	
	scanf("%d",&(Graph->Ne));
	if(Graph->Ne !=  0){
		E = (Edge)malloc(sizeof(struct ENode));
		for(i = 0;i<Graph->Ne;++i){
			//scanf("%d%d%d",&E->V1,&E->V2,&E->Weight);
			///* 注意：如果权重不是整型，Weight的读入格式要改 */
			cin<<E->V1<<E->V2<<E->Weight;
			InsertEdge(Graph,E);
		}
	}
	/* 如果顶点有数据的话，读入数据 */
	for(V=0;V<Graph->Nv;V++){
		scanf("%c",&(Graph->Data[V]));
	}
	return Graph;
} 
