#define MaxVertexNum 100  
#define INFINITY 65535
typedef int Vertex;     /* �ö����±��ʾ����,Ϊ���� */
typedef int WeightType;  /* �ߵ�Ȩֵ��Ϊ���� */
typedef char VertexDataType;  /* ����洢������������Ϊ�ַ��� */
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
	VertexDataType Data[MaxVertexNum];  /*���û�ж������������趨��*/
};
typedef PtrToGNode Graph;


/* ��ʼ��һ����VertexNum�����㵫û�бߵ�ͼ */
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
	/* ��������ͼ����Ҫ�����<V2, V1> */
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
	
	/* ������������ݵĻ����������� */
    for (V=0; V<G->Nv; V++) 
        scanf(" %c", &(G->Data[V]));

    return G;
}



/*�ڽӱ�*/

/* �ڽӵ�Ķ��� */
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode{
    WeightType Weight;  
	Vertex AdjV;
	PtoToAdjVNode NextAdjVNode;
};

/* �����ͷ���Ķ��� */
typedef struct VNode {
	PtoToAdjVNode FirstEdge;/* �߱�ͷָ�� */
	VertexDataType Data[MaxVertexNum];	
}AdjList[MaxVertexNum];/* AdjList���ڽӱ����� */

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
	
	
	/* ��������ͼ����Ҫ����� <V2, V1> */
    /* ΪV1�����µ��ڽӵ� */
	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV = E->V1;
    NewNode->Weight = E->Weight;
    /* ��V1����V2�ı�ͷ */
    NewNode->Next = Graph->G[E->V2].FirstEdge;
    Graph->G[E->V2].FirstEdge = NewNode;
}

LGraph BuildGraph()
{
    LGraph Graph;
    Edge E;
    Vertex V;
    int Nv, i;
    
    scanf("%d", &Nv);   /* ���붥����� */
    Graph = CreateLGraph(Nv); /* ��ʼ����Nv�����㵫û�бߵ�ͼ */ 
    
    scanf("%d", &(Graph->Ne));   /* ������� */
    if ( Graph->Ne != 0 ) { /* ����б� */ 
        E = (Edge)malloc( sizeof(struct ENode) ); /* �����߽�� */ 
        /* ����ߣ���ʽΪ"��� �յ� Ȩ��"�������ڽӾ��� */
        for (i=0; i<Graph->Ne; i++) {
            scanf("%d %d %d", &E->V1, &E->V2, &E->Weight); 
            /* ע�⣺���Ȩ�ز������ͣ�Weight�Ķ����ʽҪ�� */
            InsertEdge( Graph, E );
        }
    } 

    /* ������������ݵĻ����������� */
    for (V=0; V<Graph->Nv; V++) 
        scanf(" %c", &(Graph->G[V].Data));

    return Graph;
}

/*DFS(DepthFirstSearch)������ȱ���*/
 
 void Visit(Vertex V){
 	printf("���ڷ��ʶ���V");
 }
 
 void DFS(LGraph G,Vertex V,void (*Visit)(Vertex)/*����ָ��C���Իص�������Ҫʹ��*/){
 	Visit(V);
 	Visited[V] = true;/*Visited[]Ϊ���ж��㼯�����ⲿ�Ѿ���ʼ��Ϊfalse��Ϊ���V�ѷ��� */
 	for(PtrToAdjVNode W = G->LG.FirstEdge;!W;W = W->NextAdjVNode){
 		if(!Visited[W->AdjV]){
 			DFS(G,W->AdjV,Vertex);
		 }
	}
 }
 
 /*BFS(BreadthFirstSearch)������ȱ���**/
 
 /* IsEdge(Graph, V, W)���<V, W>�Ƿ�ͼGraph�е�һ���ߣ���W�Ƿ�V���ڽӵ㡣  */
/* �˺�������ͼ�Ĳ�ͬ����Ҫ����ͬ��ʵ�֣��ؼ�ȡ���ڶԲ����ڵıߵı�ʾ������*/
/* �������Ȩͼ, ��������ڵı߱���ʼ��ΪINFINITY, ����ʵ������:         */
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
 
 
 
/* �ڽӱ�洢 - ��Ȩͼ�ĵ�Դ���·�㷨 */

/* dist[]��path[]ȫ����ʼ��Ϊ-1 */
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

/*ʱ�临�Ӷ�O(V+E)��V=���㣬E=��*/






