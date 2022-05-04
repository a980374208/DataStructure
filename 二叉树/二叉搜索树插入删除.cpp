BinTree Insert(BinTree BST,ElementType X){
	if(!BST){
		BST->Data = X;
		BST->Left = BST->Right = NULL;
	}else{
		if(X>BST->Data){
			Insert(BST->Left,X);
		}else if(X<BST->Data){
			Insert(BST->Right,X);
		}
	}
	return BST;
} 

BinTree Delete(BinTree BST,ElementType X){
	Position Tmp;
	if(!BST){
		printf("要删除的元素不存在");
	}else{
		if(X<BST->Data){
			BST->Left = Delete(BST->Left,X);
		}else if(X>BSt->Data){
			BST->Right = Delete(BST->Right,X);
		}else{
			if(BST->Left&BSt->Right){
				Tmp = FindMin(BST->Right);
				BST->Data = Tmp->Data;
				BST->Right = Delete(BST->Right);
			}else{
				Tmp = BST;
				if(!BST->Left)
				    BST = BST->Right;
			    else
			        BST = BST->Left;
			    free(Tmp);
			}
		}
	}
	return BST;
}
