#include <cstdlib>
#include <iostream>
using namespace std;

typedef int ElementType;
typedef int Position;
struct QNode{
	ElementType *Data;
	Position Front,Rear;
	int MaxSize;  //���ɴ��� MaxSize-1���� 
};
typedef struct QNode *Queue;

Queue createQueue(int MaxSize){
	Queue q = (Queue)malloc(sizeof(struct QNode));
	q->Data = (ElementType*)malloc(sizeof(ElementType)*MaxSize);
	q->Front = q->Rear = 0;
	q->MaxSize = MaxSize+1;	//+1ʹ ��ɴ��� MaxSize���� 
	return q;
}

bool isEmpty(const Queue &q){
	return q->Front == q->Rear;
}
bool isFull(const Queue &q){
	return ((q->Rear+1)%q->MaxSize == q->Front);
}
bool addQ(Queue &q,ElementType data){
	if(isFull(q)){
		return false;
	}else{
		q->Rear = (q->Rear+1)%q->MaxSize;
		q->Data[q->Rear] = data; 
		return true;
	}	
}
//#define ERROR 98037
bool delQ(Queue &q){
		if(isEmpty(q)){
		return false;
	}else{
		q->Front = (q->Front+1)%q->MaxSize;
		return true;
	}
}


int main(){
	Queue queue = createQueue(6);
	for(int i = 0;i<=queue->MaxSize;++i){
		if(addQ(queue,i)){
			cout<<"add:"<< queue->Data[queue->Rear]<<endl;
		}else{	
			cout<<"queue is full"<<endl;
		}	
	}
	for(int i = 0;i<=queue->MaxSize;++i){
		if(delQ(queue)){
			    cout<<"delete:"<<queue->Data[queue->Front]<<endl;	    
		}else{
			cout<<"queue is empty"<<endl;
		}
	}	
}



