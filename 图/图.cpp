/*ͼ���ڽӾ����ʾ*/
#define INFINITY 65535 /* ����Ϊ˫�ֽ��޷������������ֵ65535*/
#define MaxVertexNum 100  /* ��󶥵�����Ϊ100 */
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
	int Nv;/* ������ */
    int Ne;  /* ����   */
	WeightType G[MaxVertexNum][MaxVertexNum];
	DataType Data[MaxVertexNum]; 
	/* ע�⣺�ܶ�����£����������ݣ���ʱData[]���Բ��ó��� */
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
	/* ��������ͼ����Ҫ�����<V2, V1> */
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
			///* ע�⣺���Ȩ�ز������ͣ�Weight�Ķ����ʽҪ�� */
			cin<<E->V1<<E->V2<<E->Weight;
			InsertEdge(Graph,E);
		}
	}
	/* ������������ݵĻ����������� */
	for(V=0;V<Graph->Nv;V++){
		scanf("%c",&(Graph->Data[V]));
	}
	return Graph;
} 
