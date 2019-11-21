//why not start tree first?
//shunxv save struct of normal tree
#define maxsize 1024
typedef char datatype;
typedef struct{
	datatype data[maxsize];
	int last;
}sqlist;


//lianshi save of tree
typedef char datatype;
typedef struct node
{
	datatype data;
	struct node *lchild,*rchild;
}bitree;
bitree *root;

