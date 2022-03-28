#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
typedef int Position;
#define MAXSIZE 20
typedef int ElementType;
struct SNode{
	ElementType *Data;
	Position Top; 
};

typedef SNode *Stack;

Stack createStack(){
	Stack S = (Stack)malloc(sizeof(struct SNode));
	S->Data = (ElementType*)malloc(MAXSIZE * sizeof(ElementType));
	S->Top = -1;
	return S;
}
 
bool isFull(Stack S){
	return (S->Top == MAXSIZE-1);
}

bool isEmpty(Stack S){
	return (S->Top == -1);
}

bool Push(Stack S,ElementType data){
	if(isFull(S)){
		cout<<"stack was fall"<<endl;
		return false;
	}else{
		S->Data[++S->Top] = data; 
		return true;
	}
}
ElementType a;
#define ERROR a  //a为Element类型的标志错误的特殊值； 
ElementType  Pop(Stack S){
	if(isEmpty(S)){
		cout << "Stack was empty"<<endl;
		return ERROR;
	}else{
		return S->Data[S->Top--] ;
	}
}


int main(){
	Stack stack = createStack();
	
	for(int i = 0;i<=MAXSIZE;++i){
		if(!Push(stack,i)){
			if(isFull(stack)){
				cout << "stack is full"<<endl;
			}
		}else{
		cout << "Push:"<<i<<endl;
	    }
	}
	ElementType temp;
//	if(isEmpty(stack)){
//			temp = Pop(stack);
//		cout<<"Pop:"<<temp<<endl;
//	}	
	for(int i = 0;i<stack->Top;){
		temp = Pop(stack);
		cout<<"Pop:"<<temp<<endl;
	}
	
}



