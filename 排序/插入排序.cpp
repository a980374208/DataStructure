//为A[N]个数据排序
typedef  int ElementType;
void InsertSort(ElemrntType A[], int N){
	int j;
	for(int i = 1;i<n;++i){
		ElementType tmp = A[i];
		for(j = i;tmp<A[j];--j){
			A[j] = A[j+1];
		}
		A[j] = tmp;	
	}
} 
