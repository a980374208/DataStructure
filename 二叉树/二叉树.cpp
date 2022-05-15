/*
������T��һ������Ľ�㼯�ϡ�
 ������Ͽ���Ϊ��
 ����Ϊ�գ��������ɸ����ͳ�Ϊ��������TL��������TR�ĸ����ཻ�Ķ�������ɡ�
*/
/*������������ṹ */
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode {
	ElementType Data;
	BinTree Left;
	BinTree Right;
};

/*��������4�б���*/
void InorderTraversal(BinTree BT){
	if(BT){
		InorderTravelsal(BT->Left);
		printf("%d",BT->Data);
		InorderTravelsal(BT->Right);
	}
}

void PostorderTraversal(BinTree BT){
	if(BT){
		InorderTravelsal(BT->Left);
		InorderTravelsal(BT->Right);
		printf("%d",BT->Data);
	}
}
void PreorderTraversal(BinTree BT){
	if(BT){
		printf("%d",BT->Data);
		InorderTravelsal(BT->Left);
		InorderTravelsal(BT->Right);
	}
}
/*�������*/
void LevelorderTraversal(BinTree BT){
	Queue Q;
	BinTree T;
	if(!BT) 
	    return;
	Q = CreateQueue();
	Add(Q,BT);
	while(!IsEmpty(Q)){
		T = DeleteQueue(Q);
		printf("%d",T->Data);
		if(T->Left)
		    Add(Q,BT->Left);
		if(T->Left)
		    Add(Q,BT->Right);
	}
}


/*����������*/

BinTree Insert(BinTree BST,ElementType X){
	if(!BST){
		BST = (BinTree)malloc(sizeof(struct TNode)) ;
		BST->Data = X;
		BST->Left = BST->Right = NULL;
	}else{
		if(BST->Data<X){
			BST->Left = Insert(BST->Left,X); 
		}else if(BST->Data>X){
			BST->Right = Insert(BST->Right,X);
		}
	}
} 

BinTree FindMin(BinTree BT){
	if(!BT){
		printf("��ѯ����Ϊ��");
	}else{
		if(BT->Left){
			BT = FindMin(BT->Left);
		}else if{
			BT = FindMin(BT->Right);
		}
	}
	return BT;
}


BinTree Delete(BinTree BST,ElementType X){
	if(!BST){
		printf("δ�ҵ�Ҫɾ���Ľڵ�");
	}else{
		if(BST->Data>X){
			BST->Right = Delete(BST->Right,X);
		}else if(BST->Data<X){
			BST->Left = Delete(BST->Left,X);	
		}else{
			Position tmp;
			if(BST->Left&&BST->Right){
				tmp = BST->Right;
				BST->Right =  FindMin(BST->Right);
				free(tmp);
			}else{
				tmp = BST;
				if(!BST->Left){
					BST= BST->Right;
				}else{
					BST= BST->Left;
				}
				free(tmp);
			}
		}
	}
	return BST;
}



/*ƽ���������Balanced Binary Tree) (AVL��)
������������һ������������߶Ȳ�ľ���ֵ������1���� 
*/
typedef struct AVLNode *Position;
typedef Position AVLTree;
struct AVLNode{
	ElementType Data;
	AVLTree Left;
	AVLTree Right;
	int Height;
};

int Max(int a,int b){
	return a>b?a:b;
}

int GetHeight(AVLTree A){
	return A->Height;
}

AVLTree SingleLeftRotation(AVLTree A){
	AVLTree B = A->Left;
	A->Left = B->Right;
	B->Right = A;
	A->Height = Max(GetHeight(A->Left),GetHeight(A->Left))+1;
	B->Height = Max(GetHeight(B->Left),A->Height/*A->Height = GetHeight(B->Right)*/) +1;
	return B;
}

AVLTree SingleRightRotation(AVLTree A){
	AVLTree B = A->Left;
	A->Left = B->Right;
	B->Right = A;
	A->Height = Max(GetHeight(A->Left),GetHeight(A->Right))+1;
	B->Height = Max(A->Height,GetHeight(B->Left))+1;
}

AVLTree DoubleLeftRightRotation(AVLTree A){
	A->Left = SingleRightRotation(A->Left);
	return SingleLeftRotation(A);
}

AVLTree DoubleRightLeftRotation(AVLTree A){
	A->Right = SingleRightLeftRotation(A->Right);
	return SingleRightRotation(A);
}

AVLTree Insert(AVLTree A,X){
	if(!A){
		A = (AVLTree)malloc(sizeof(struct AVLNode));
		A->Data = x;
		A->Height = 0;
		A->Left = A->Right = null;
	}else if(X<A->Data){
		A->Left = Insert(A->Left,X);
		if(GetHeight(A->Left)-GetHeight(A->Right) == 2){
			if(X<A->Left->Data){
				A = SingleLeftRotation(A);
			}else{
				A = SingleLeftRightRotation(A);
			}
		}
	}else if(X>A->Data){
		A->Right = Insert(A->Right,X);
		if(GetHeight(A->Left)-GetHeight(A->Right) == -2){
			if(A->Left->Data<X){
				A = SingleRightLeftRotation(A);
			}else{
				A = SingleRightRotation(A);
			}
		}
	}else{
		/*X = A->Data*/
	}
	A->Height = Max( GetHeight(A->Left), GetHeight(A->Right) ) + 1;
    
    return A;
} 


/*ʲô�Ƕ�
���ȶ���(Priority Queue):����ġ����С���ȡ��Ԫ�ص�˳����
����Ԫ�ص�����Ȩ���ؼ���)��С,������Ԫ�ؽ�����е��Ⱥ�˳��*/
typedef struct HNode *Heap;
struct HNode{
    ElementType* Data;
    int Size;
    int Capacity;
};

typedef Heap MaxHeap;
typedef Heap MinHeap;

#define MAXDATA 1000  /* ��ֵӦ���ݾ����������Ϊ���ڶ������п���Ԫ�ص�ֵ */
#define MAXSize 500  /* ��������ΪMaxSize�Ŀյ����� */
MaxHeap CreateHeap(/*int MAXSize*/){
	MaxHeap H  = (MaxHeap)malloc(sizeof(struct HNode));
	H->Data = (ElementType*)malloc(sizeof(ElementType)*(MAXSize+1));
	H->Size = 0;
	H->Capacity  = MAXSize;
	H->Data[0] = MAXDATA;
	
	return H;
}

bool IsFull(MaxHeap H){
	return (H->Size == H->Capacity);
}

bool Insert(MaxHeap H,ElementType X){
	int i;
	if(IsFull(H)){
		printf("��������");
		return false;
	}
	for(i = H->Size++;X>H->Data[i/2];i/=2){
		H->Data[i]  = H->Data[i/2];
	}
	H->Data[i] = X;
	return true;
}

bool IsEmpty( MaxHeap H )
{
    return (H->Size == 0);
}
#define ERROR -1 /* �����ʶӦ���ݾ����������Ϊ���в����ܳ��ֵ�Ԫ��ֵ */
MaxHeap DeletaMax(MaxHeap H){
	int Parent,Child;
	ElementType MaxItem,X;
	if(IsEmpty(H)){
		printf("�����ѿ�");
		return ERROR;
	}
	MaxItem = H->Data[1];
	/* �Ѵ�������һ��Ԫ��Ų������㣬��ʼ�����϶��¹��˽�� */
	X = H->Data(H->Size--);
	for(Parent = 1;Parent*2<H->Size;Parent=Child){
		Child = Parent*2;
		if(Child!=H->Size&&(H->Data[Child]<H->Data[Child+1])){
			Child++;
		}
		if(H->Data[Child]<X){
			H->Data[Parent] = H->Data[Child];
		}else{
			break;
		}
	}
	H->Data[Parent] = X;
	return MaxItem;
}

/*----------- �������� -----------*/

/* ���ˣ���H����H->Data[p]Ϊ�����Ӷѵ���Ϊ���� */
void PercDown(MaxHeap H,int p){
	int Parent,Child;
	ElementType X;
	X = H->Data[p];
	for(Parent = p;Parent*2<H->Size;Parent = Child){
		Child = 2*Parent;
		if(Child!= H->Size&&(H->Data[Child]<H->Data[Child+1])){
			Child++;
		}
		if(X>=H->Data[Child])
		    break;
		else
		    H->Data[Parent] = H->Data[Child];
	}
	H->Data[Parent] = X;
}

/* �����������H->Size��Ԫ���Ѿ�����H->Data[]�� */
void BuildHeap(MaxHeap H){
	/* �����һ�����ĸ��ڵ㿪ʼ���������1 */
	for(int i= H->Size*2;i>0;i--){
		PercDown(H,i);
	}
}

/*��С��*/
bool Insert(MinHeap H,ElementType X){
	if(IsFull(H)){
		printf("��С������");
		return false;
	}
	for(int i = H->Size++;i<H->Data[i/2];i/=2){
		H->Data[i/2] = H->Data[i];
	}
	H->Data[i] = X;
	return true;	
} 

ElementType DeleteMin(MinHeap H){
	if(IsEmpty(H)){
		printf("error");
		return ERROR;
	}
	int Parent,Child;
	ElementType X,MinItem;
	MinItem = H->Data[1];
	X = H->Data[H->Size--];
	for(Parent = 1;Parent*2<H->Size;Parent = Child){
		Child = 2*Parent;
		if(Child!= H->Size&&(H->Data[Child]>H->Data[++Child])){
			Child++;
		}
		if(X<=H->Data[Child]){
			break;
		}else{
			H->Data[Parent] = H->Data[Child];
		}
	}
	H->Data[Parent] = X;
	return MinItem;
}
/*���治��д�˲���MaxHeap*/


