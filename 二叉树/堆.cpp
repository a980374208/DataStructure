typedef struct HNode *Heap;
struct HNode{
	ElementType *Data;
	int Size;
	int Capacity;
}; 

typedef Heap MaxHeap;
typedef Heap MinHeap;

#define MAXDATA 1000
#define ERROR -1

MaxHeap CreateHeap(int MaxSzie){
	MAxHeap H = (MaxHeap)malloc(MaxSize*sizeof(sturct HNode));
	H->Data = (ElementType*)maoolc()(MaxSzie+1)*sizeof(ElementType))/*多出一个元素用于充当哨兵适当提高效率*/
	H->Szie = 0;
	H->Capacity = MaxSzie;
	H->Data[0] = MAXDATA;  /* 定义"哨兵"为大于堆中所有可能元素的值*/
	return H; 
}

bool IsFull(MaxHeap H){
	return (H->Size == H->Capacity);
}

bool IsEmpty(MaxHeap H){
	return (H->Size == 0);
} 

bool Insert(MaxHeap H,ElementType X){
	int i;
	if(IsFull(H)){
		printf("最大堆已满");
		return false;
	}
	i = ++H->Size;
	for(;H->Data[i/2]>X/*若无"哨兵"则要添加 &&i! = 0*/ ;i/=2){
		H->Data[i] = H->Data[i/2];
	}
	H->Data[i] = X;
	ruturn true;
}

ElementType DeleteMax(MaxHeap H){
	int Parent ,Child;
	ElementType MaxItem,X;
	if(IsEmpty(H)){
		printf("最大堆已空");
		return ERROR;
	}
	MaxItem = H->Data[1];
	X = H->Data[H->Size--];/*把完全二叉树最后的元素作为跟然后调整树*/
	for(Parent = 1;Parent*2 <= H->Size;Parent = Child ){
		Child = Parent*2;
		if((Child! = H->Size)&&(H->Data[Child]<H->Data[Child+1])){
			Child ++;
		}
		if(X>=H->Data[Child])) break;
		else
		    H->Data[Parent] = H->Data[Child]; 
	}
	H->Data[Parent]  = X;
	return MaxItem;
}


void PercDown(MaxHeap H,int p){
	/*下滤：将H中以H->Data[p]为根的子堆调整为最大堆*/
	int Parent,Child;
	ElementType X;
	for(Parent = p;Parent*2<H->Size;Parent = Child){
		Child = 2*Parent;
		if((Child! = H->Size)&&(H->Data[Child]<H->Data[Child+1]))
		    Child++;
		if(X> = H-<Data[Child])
		    break;
		else
		    H->Data[Parent] = H->Data[Child];
	}
	H->Data[Parent] = X;
}

void BuildHead(MaxHead H){
	/* 调整H->Data[]中的元素，使满足最大堆的有序性  */
  /* 前提：所有H->Size个元素已经存在H->Data[]中 */
  int i;
  for(i = H->Size/2;i>0;i--)
      PrecDown(H,i);
}











