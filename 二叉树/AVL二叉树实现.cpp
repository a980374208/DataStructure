typedef struct AVLNode *Position;
typedef Position AVLTree;
struct AVLNode{
	ElementType Data;
	AVLNode Left;
	AVLNode Right;
	int Height;  // 表示平衡二叉树中该节点高度
};

int Max(int a,int b){
	return a>b?a:b;
} 

AVLTree SingleLeftRotation(AVLTree A){
	/*左单旋时A必须有一个做子节点*/
	AVLTree B = A->Left;
	A->Left = B->Right;
	B->Right = A;
	A->Height = Max(GetHeight(A->Left),GetHeight(A->Right))+1;
	B->Height = MAx(GetHeight(B->Left),A->Height)+1;
	return B;
}

AVLTree SinleRightRotation(AVLTree A){
	AVLTree B = A->Right;
	A->Right = B->Left;
	B->Left = A;
	A->Height = Max(GetHeight(A->Left),GetHeight(A->Right))+1;
	B->Height = Max(A->Height,GetHeight(B->Right))+1;
	return B;
}

AVLTree DoubleLeftRightRotation(AVLTRee A){
	A->Left = SingleRightRotation(A->Left);
	return SingleLeftRotation(A);
} 


AVLTree DoubleRightLeftRotation(AVLTRee A){
	A->Right = SingleLeftRotation(A->Right);
	return SingleRightRotation(A);
} 


AVLTree Insert(AVLTree T,ElementType X){
	if(!T){
		T = (AVLTree)malloc(sizeof(struct AVLNode));
		T->Data = X;
		T->Height = 0;
		T->Left = T->Right = NULL;
	}else if(T->Data<X){
		T->Left = Insert(T->Left,X);
		if(abs(GetHeight(T->Left-GetHeight(T->Right))) == 2){
			if(T->Left->Data>X){
				singleLeftRotation(T);
			}else{
				doubleLeftRightRotation(T);
			}
		}
	}else if(T->Data>X){
		T->Right = Insert(T->Right,X);
		if(abs(GetHeight(T->Left-GetHeight(T->Right))) == 2){
			if(T->Right->Data>X){
				singleRightRotation(T);
			}else{
				doubleRightLeftRotation(T);
			}
		}
	}else {
		/*X == T->Data*/
	}
	T->Height = Max(GetHeight(T->Left),GetHeight(T->Right))+1;
	return T;
}





