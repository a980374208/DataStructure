/*
二叉树T：一个有穷的结点集合。
 这个集合可以为空
 若不为空，则它是由根结点和称为其左子树TL和右子树TR的个不相交的二叉树组成。
*/
/*二叉树的链表结构 */
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode {
	ElementType Data;
	BinTree Left;
	BinTree Right;
};

/*二叉树的4中遍历*/
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
/*层序遍历*/
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


/*二叉搜索树*/

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
		printf("查询的树为空");
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
		printf("未找到要删除的节点");
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



/*平衡二叉树（Balanced Binary Tree) (AVL树)
空树，或者任一结点左、右子树高度差的绝对值不超过1的树 
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


/*什么是堆
优先队列(Priority Queue):特殊的“队列”，取出元素的顺序是
依照元素的优先权（关键字)大小,而不是元素进入队列的先后顺序。*/
typedef struct HNode *Heap;
struct HNode{
    ElementType* Data;
    int Size;
    int Capacity;
};

typedef Heap MaxHeap;
typedef Heap MinHeap;

#define MAXDATA 1000  /* 该值应根据具体情况定义为大于堆中所有可能元素的值 */
#define MAXSize 500  /* 创建容量为MaxSize的空的最大堆 */
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
		printf("最大堆已满");
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
#define ERROR -1 /* 错误标识应根据具体情况定义为堆中不可能出现的元素值 */
MaxHeap DeletaMax(MaxHeap H){
	int Parent,Child;
	ElementType MaxItem,X;
	if(IsEmpty(H)){
		printf("最大堆已空");
		return ERROR;
	}
	MaxItem = H->Data[1];
	/* 把大堆中最后一个元素挪到根结点，开始过自上而下过滤结点 */
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

/*----------- 建造最大堆 -----------*/

/* 下滤：将H中以H->Data[p]为根的子堆调整为最大堆 */
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

/* 这里假设所有H->Size个元素已经存在H->Data[]中 */
void BuildHeap(MaxHeap H){
	/* 从最后一个结点的父节点开始，到根结点1 */
	for(int i= H->Size*2;i>0;i--){
		PercDown(H,i);
	}
}

/*最小堆*/
bool Insert(MinHeap H,ElementType X){
	if(IsFull(H)){
		printf("最小堆已满");
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
/*后面不想写了参照MaxHeap*/


