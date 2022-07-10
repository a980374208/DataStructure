
typedef int ElementType ;


void Merge(ElementType A[],ElementType TmpA[],int Left,int Right,int RightEnd){
	int LeftEnd = Right-1;
	int Num = 0;
	int NumElement = Left;
	while(Left<LeftEnd&&Right<RightEnd){
		if(A[Left]<A[Right]){
			TmpA[Num++] = A[Left++];
		}else{
			TmpA[Num++] = A[Right++];
		}
	}
	while(Left<LeftEnd){
		TmpA[Num++] = A[Left++];
	}
	while(Right<RightEnd){
		TmpA[Num++] = A[Right++];
	}
	for(NumElement;NumElement<=Right;++NumElement){
		A[NumElement] = Tmp[NumElement];
	}
	
}



void MergeSort(ElementType A[],ElementType TmpA[],int Left,int Right){
	if(Left<Right){
		int mid = Left+(Right-Left)/2;
		MergeSort(A,Tmp,Left,mid);
		MergeSort(A,Tmp,mid+1,Right);
		Merge(A,TmpA,Left,mid+1,Right);
	}
} 
