//tree's parents show node struct definition
#define MAX_TREE_SIZE 100
typedef int ElemType;
typedef struct PTNode
{
	ElemType data;//node character
	int parent;//location of parents
}PTNode;

typedef struct
{
	PTNode nodes[MAX_TREE_SIZE];
	int r;//location of root
	int n;//number of nodes
}PTree;



//parent_child show way
typedef struct CTNode
{
	int child;
	struct CTNode *next;
}*ChildPtr;
//biaotou struct
typedef struct
{
	ElemType data;
	int parents;
	ChildPtr firstchild;
}CTBox;

typedef struct
{
	CTBox nodes[MAX_TREE_SIZE];//jiedian shuzu
	int r,n;
};


//ercha tree store struct
//ercha linklist
typedef struct BiTNode
{
	ElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;










//规定前序输入，没有数的地方用空格
#include<stdio.h>
#include<stdlib.h>
typedef char ElemType;
typedef struct BiTNode
{
	char data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
//创建一颗二叉树,约定用户遵照前序遍历的方式输入数据 
CreateBiTree(BiTree *T)
{
	char c;
	scanf("%c",&c);
	if(' '==c)
	{
		*T=NULL;
	}
	else
	{
		*T=(BiTNode *)malloc(sizeof(BiTNode));
		(*T)->data=c;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
}
//访问二叉树结点的具体操作，你想干嘛
void visit(char c,int level)
{
	printf("%c位于第%d层\n",c,level);
 } 
//前序遍历二叉树
PreOrderTraverse(BiTree T,int level)
{
	if(T)
	{
		visit(T->data,level);
		PreOrderTraverse(T->lchild,level+1);
		PreOrderTraverse(T->rchild,level+1);
	}
}
int main()
{
	int level=1;
	BiTree T=NULL;
	CreateBiTree(&T);
	PreOrderTraverse(T,level);
	return 0;
}




//ThreadTree
#include<stdio.h>
#include<stdlib.h>
typedef char ElemType;
//thread save mark location
//Link(0) pointer to left and right child
//Thread(1): tags to prior and next
typedef enum{Link,Thread
}PointerTag;
typedef struct BiThrNode
{
	char data;
	struct BiThrNode *lchild,*rchild;
	PointerTag ltag;
	PointerTag rtag;
}BiThrNode,*BiThrTree;
//È«¾Ö±äÁ¿£¬Ê¼ÖÕÖ¸Ïò¸Õ¸Õ·ÃÎÊ¹ýµÄ½áµã
BiThrTree pre; 
//´´½¨Ò»¿Å¶þ²æÊ÷£¬Ô¼¶¨ÓÃ»§×ñÕÕÇ°Ðò±éÀúµÄ·½Ê½ÊäÈëÊý¾Ý
CreateBiThrTree(BiThrTree *T)
{
	char c;
	scanf("%c",&c);
	if(' '==c)
	{
		*T=NULL;
	}
	else
	{
		*T=(BiThrNode *)malloc(sizeof(BiThrTree));
		(*T)->data=c;
		(*T)->ltag=Link;
		(*T)->rtag=Link;
		CreateBiThrTree(&(*T)->lchild);
		CreateBiThrTree(&(*T)->rchild);
	}
}
InThreading(BiThrTree T)
{
	if(T)
	{
		InThreading(T->lchild);
		if(!T->lchild)
		{
			T->ltag=Thread;
			T->lchild=pre;
		}
		if(!pre->rchild)
		{
			pre->rtag=Thread;
			pre->rchild=T;
		}
		pre=T;
		InThreading(T->rchild);
	}
}
InOrderThreading(BiThrTree *p,BiThrTree T)
{
	*p=(BiThrTree)malloc(sizeof(BiThrNode));
	(*p)->ltag=Link;
	(*p)->rtag=Thread;
	(*p)->rchild=*p;
	if(!T)
	{
		(*p)->lchild=*p;
	}
	else
	{
		(*p)->lchild=T;
		pre=*p;
		InThreading(T);
		pre->rchild=*p;
		pre->rtag=Thread;
		(*p)->rchild=pre;
	}
}
int main()
{
	BiThrTree P,T=NULL;
	CreateBiThrTree(&T);
	InOrderThreading(&P,T);
	return 0;
}

