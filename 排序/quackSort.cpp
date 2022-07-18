typedef ElementType int;
#define Cutoff 100
 
 
ElementType  findPivot(ElementType A[], int Left, int Right){
 	int mid = (Right-Left)/2;
 	if(A[Left]>A[Right])
 	    swap(A[Left],A[Right]);
 	if(A[Left]> A[mid]])
 	    swap(A[Left],A[mid]);
 	if(A[mid]>A[Right])
 	    swap(A[Left],A[Right]);
 	swap(a[mid],a[Right-1]);
 	return A[Right-1];
}

void quackSort(Element A[],int Left ,int Right){
	int Low,Height,Pivot;
	if(Cutoff<=Right-Left){
		Low = Left; Height = Pivot;
		pivot = findPivot(A[],Low,Height);
		while(1){
			while(A[Low++]<Piovt);
			while(A[Height--]>Piovt);
			if(Low<Height)
		    	swap(A[Low],A[Height]);
			else
		    	break;
		}
		swap(a[Low],A[Right-1]);
		quackSort(A[],Left,Low);
		quackSort(Q[],Height,Right);
	}else{
		insertSort(Q+Left,Right-Left+1);
	}
} 
 
