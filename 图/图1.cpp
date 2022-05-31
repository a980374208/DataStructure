#define MaxVertexNum 100  
#define INFINITY 65535
typedef int Vertex;     /* 用顶点下标表示顶点,为整型 */
typedef int WeightType;  /* 边的权值设为整型 */
typedef char VertexDataType;  /* 顶点存储的数据类型设为字符型 */
typedef ENode *PtrToENode;
struct ENode{
	int V1;
	int V2;
	WeightType Weight;
};
typedef PtrToENode Edge;

typedef GNode *PtrToGNode;
struct GNode{
	int Nv;
	int Ne;
	WeightType  Weight[MaxVerTexNum][MaxVerTexNum]; 
	VertexDataType Data[MaxVertexNum];  /*如果没有顶点数据则无需定义*/
};
typedef PtrToGNode Graph;


/* 初始化一个有VertexNum个顶点但没有边的图 */
Graph CreateGraph(int VertexNum){
	Graph G = (Graph)malloc(sizeof(struct GNode));
	G->Nv = VertexNum;
	G->Ne = 0;
	for(int i = 0;i<G->Nv;++i){
		for(int j = 0;j<G->Nv;++j){
			G->Weight[i][j] = INFINITY;
		}
	}
	return G;
}

void Insert(Graph G,Edge E){
	G->Weight[E->V1][E->V2] = E->Weight;
	/* 若是无向图，还要插入边<V2, V1> */
    G->Weight[E->V2][E->V1] = E->Weight;
}

Graph BuildGraph(){
	Edge E;
    Vertex V;
	scanf("%d",&V);
	Graph G = CreateGraph(V);
	scanf("%d",&(G->Ne));
	if(G->Ne != 0){
		for(int i = 0;i<G->Ne;++i){
			Edge E = (Edge)malloc(sizeof(struct ENode));
			scanf("%d%d%d",&(E->V1),&(E->V2),&(E->Weight));
			Insert(G,E);
		}
	}
	
	/* 如果顶点有数据的话，读入数据 */
    for (V=0; V<G->Nv; V++) 
        scanf(" %c", &(G->Data[V]));

    return G;
}



/*邻接表*/

/* 邻接点的定义 */
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode{
    WeightType Weight;  
	Vertex AdjV;
	PtoToAdjVNode NextAdjVNode;
};

/* 顶点表头结点的定义 */
typedef struct VNode {
	PtoToAdjVNode FirstEdge;/* 边表头指针 */
	VertexDataType Data[MaxVertexNum];	
}AdjList[MaxVertexNum];/* AdjList是邻接表类型 */

typedef struct LGNode *LGraph;
struct LGNode{
	int Nv;
	int Ne;
	AdjList LG;
};


LGraph CreateLGraph(int VertexNum){
	LGraph LGr = (LGraph)malloc(sizeof(struct LGNode));
	LGr->Ne = 0;
	LGr->Nv = VertexNum;
    for(int i = 0;i<LGr->Nv;++i){
    	LGr->LG[i].FirstEdge = NULL:
	}
	return Graph;
}


void InsertEdge(LGraph LGr,Edge E){
	PtrToAdjVNode NewNode;
	NewNode = (PtoToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V2;
	NewNode->Weight = E->Weight;
	NewNode->NextAdjVNode = LGr->LG[E->V1].FirstEdge;
	LGr->LG[E->V1].FirstEdge = NewNode;
	
	
	/* 若是无向图，还要插入边 <V2, V1> */
    /* 为V1建立新的邻接点 */
	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV = E->V1;
    NewNode->Weight = E->Weight;
    /* 将V1插入V2的表头 */
    NewNode->Next = Graph->G[E->V2].FirstEdge;
    Graph->G[E->V2].FirstEdge = NewNode;
}

LGraph BuildGraph()
{
    LGraph Graph;
    Edge E;
    Vertex V;
    int Nv, i;
    
    scanf("%d", &Nv);   /* 读入顶点个数 */
    Graph = CreateLGraph(Nv); /* 初始化有Nv个顶点但没有边的图 */ 
    
    scanf("%d", &(Graph->Ne));   /* 读入边数 */
    if ( Graph->Ne != 0 ) { /* 如果有边 */ 
        E = (Edge)malloc( sizeof(struct ENode) ); /* 建立边结点 */ 
        /* 读入边，格式为"起点 终点 权重"，插入邻接矩阵 */
        for (i=0; i<Graph->Ne; i++) {
            scanf("%d %d %d", &E->V1, &E->V2, &E->Weight); 
            /* 注意：如果权重不是整型，Weight的读入格式要改 */
            InsertEdge( Graph, E );
        }
    } 

    /* 如果顶点有数据的话，读入数据 */
    for (V=0; V<Graph->Nv; V++) 
        scanf(" %c", &(Graph->G[V].Data));

    return Graph;
}

/*DFS(DepthFirstSearch)深度优先遍历*/
 
 void Visit(Vertex V){
 	printf("正在访问顶点V");
 }
 
 void DFS(LGraph G,Vertex V,void (*Visit)(Vertex)/*函数指针C语言回调函数主要使用*/){
 	Visit(V);
 	Visited[V] = true;/*Visited[]为所有顶点集合在外部已经初始化为false此为标记V已访问 */
 	for(PtrToAdjVNode W = G->LG.FirstEdge;!W;W = W->NextAdjVNode){
 		if(!Visited[W->AdjV]){
 			DFS(G,W->AdjV,Vertex);
		 }
	}
 }
 
 /*BFS(BreadthFirstSearch)广度优先遍历**/
 
 /* IsEdge(Graph, V, W)检查<V, W>是否图Graph中的一条边，即W是否V的邻接点。  */
/* 此函数根据图的不同类型要做不同的实现，关键取决于对不存在的边的表示方法。*/
/* 例如对有权图, 如果不存在的边被初始化为INFINITY, 则函数实现如下:         */
 void IsEdge(Graph G,Vertex V,Vertex W){
 	return G->Weight[V][W] < INFINITY? true:false; 
 }
 
 void BFS(Graph G,Vertex S,void (*Visit)(Vertex)){
 	Queue Q;
 	Vertex V,W;
 	Q = CreateQueue(MAXSIZE);
 	Visit(S);
 	Visited[S] = true; 
 	AddQ(Q,S);
 	while(!IsEmpty(Q)){
 		V = DeleteQ(Q);
 		for(W = 0;W<G->Nv;++W){
 		    if(!(Visited[W])&&IsEdge(G,V,W)){
 		    	Visit(W);
 		    	Visited[W] = true;
 		    	AddQ(Q,W);
			 }
	    }
	}
 }
 
 
 
/* 邻接表存储 - 无权图的单源最短路算法 */

/* dist[]和path[]全部初始化为-1 */
void Unweighted ( LGraph G, int dist[], int path[], Vertex S )
{
	Queue Q;
	Vertex V;
	dist[S] = 0;
	Q = CreateQueue(G->Nv);
	AddQ(Q,S);
	PtrToAdjVNode W;
	while(!IsEmpty(Q)){
		V = DeleteQ(Q);
		for(W = G->LG[V].FirstEdge;W;W = W->NextAdjVNode){
		    if(dist[W->AdjV] == -1){
			    dist[W->AdjV] = dist[V]+1; 
			    path[W->AdjV] = V;
			    AddQ(Q,W->AdjV);
		    }
	    } 
	}
}

/*时间复杂度O(V+E)，V=顶点，E=边*/






