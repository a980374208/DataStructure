typedef struct TNode *position;
typedef Position BinTree;    //二叉树类型 
struct TNode {               //单个树节点 
	ElementType Data;        //数据 
	BinTree Left;             //指向左子树 
	BinTree Right;            //指向右子树 
}; 
