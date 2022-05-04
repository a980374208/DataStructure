void InorderTraversal( BinTree BT){
	if(BT){
		InorderTraversal(BT->Left);
		/*�˴������Bt�ڵ�ķ��ʾ��Ǵ�ӡ����*/
		printf("%d",BT->Data);
		InorderTraversal(BT->Data);
	}
} 

void PreOrderTraverSal(BinTree BT){
	if(BT){
		Printf("%d",BT->Data);
		PreorderTraversal(BT->Left);
		PreorderTraversal(BT->Right);
	}
}

void PostorderTraversal(BinTree BT){
	if(BT){
		PostorderTraversal(BT->Left);
		PostorderTraversal(BT->Right);
		Printf("%d",BT->Data);
	}
}

void LevelorderTraversal(BInTree BT){
	Queue Q;
	BinTree T;
	if(!BT){
		return;
	}
	Q = CreateQueue();
	AddQ(Q ,BT);
	while(!IsEmpty(Q)){
		T = DeleteQ(Q);
		printf("%d",T->Data);
		if(T->Left) AddQ(Q,T->Left);
		if(T->Right) AddQ(Q,T->Right);	
	}
}
