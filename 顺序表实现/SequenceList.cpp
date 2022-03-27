#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;


typedef int Position;
typedef struct LNode *List;
typedef int ElementType;
#define MAXSIZE 1000

struct LNode {
    ElementType Data[MAXSIZE];
    Position Last;
};

List InitList(){
    List L;
    L = (List)malloc(sizeof(struct LNode));
    L->Last = -1;
    return L;
 }

 #define ERROR -1;
 Position Find(List L,ElementType Data){
    Position i = 0;
    while(i<L->Last && L->Data[i]!=Data){
        ++i;
     }
    if(i>L->Last){
        return ERROR;
    }
    else{
        return i;
    }

 }

 bool Insert(List L,ElementType Data,Position i){
    if(i>=MAXSIZE||i<0){
        cout<<"the position is error"<<endl;
        return false;
     }
     if(L->Last >= MAXSIZE-1){
        printf("±íÂú");
        return false;
     }
    for(int j = L->Last ; j>i ; --j){
        L->Data[j+1]=L->Data[j];
     }
     L->Data[i] = Data;
     L->Last++;
     return true;
 }

 bool Delete(List L,Position i){
    if(i>=MAXSIZE||i<0){
        cout<<"the position is error"<<endl;
        return false;
    }
    for(int j = i;j<L->Last;++j){
        L->Data[j] = L->Data[j+1];
    }
    L->Last--;
    return true;

 }

 void Traversal(List L){
    for(int i = 0;i<L->Last;++i){
        cout<<L->Data[i]<<endl;
    }
 }

 int main(){
   List list = InitList();
//    LNode lNode;
//    List list= &lNode;
//    list->Last = -1;
    Insert(list,1,0);
    Insert(list,2,1);
    Insert(list,3,2);
    Insert(list,4,3);
    Insert(list,5,4);
    Traversal(list);
    Delete(list,2);
    Traversal(list);
    Position p = Find(list,3);
    cout<<"the position is:"<<p<<endl;
 }
