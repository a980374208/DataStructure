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
	H->Data = (ElementType*)maoolc()(MaxSzie+1)*sizeof(ElementType))/*���һ��Ԫ�����ڳ䵱�ڱ��ʵ����Ч��*/
	H->Szie = 0;
	H->Capacity = MaxSzie;
	H->Data[0] = MAXDATA;  /* ����"�ڱ�"Ϊ���ڶ������п���Ԫ�ص�ֵ*/
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
		printf("��������");
		return false;
	}
	i = ++H->Size;
	for(;H->Data[i/2]>X/*����"�ڱ�"��Ҫ��� &&i! = 0*/ ;i/=2){
		H->Data[i] = H->Data[i/2];
	}
	H->Data[i] = X;
	ruturn true;
}

ElementType DeleteMax(MaxHeap H){
	int Parent ,Child;
	ElementType MaxItem,X;
	if(IsEmpty(H)){
		printf("�����ѿ�");
		return ERROR;
	}
	MaxItem = H->Data[1];
	X = H->Data[H->Size--];/*����ȫ����������Ԫ����Ϊ��Ȼ�������*/
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
	/*���ˣ���H����H->Data[p]Ϊ�����Ӷѵ���Ϊ����*/
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
	/* ����H->Data[]�е�Ԫ�أ�ʹ�������ѵ�������  */
  /* ǰ�᣺����H->Size��Ԫ���Ѿ�����H->Data[]�� */
  int i;
  for(i = H->Size/2;i>0;i--)
      PrecDown(H,i);
}











