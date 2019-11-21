//start stack after list

//shunxv save struct of stack
#define maxsize 1024
typedef int datatype;
typedef struct
{
	datatype data[maxsize];
	int Top;
}SqStack;

//initial of shunxv stack
void InitSqStack(SqStack*&S)
{
	S=(SqStack*)malloc(sizeof(SqStack));
	S->Top=-1;
}


//zhikong shunxv stack
void SetNull(SqStack*S)
{
	S->Top=-1;
}


//judge if stack is empty
int Empty(SqStack*S)
{
	if(S->Top==-1) return 1;
	else return 0;
}


//ruzhan 
int Push(SqStack*S,datatype x)
{
	if(S->Top==maxsize-1)
	{
		printf("zhan shang yi");
		return 0;
	}
	else
	{
		S->data[++S->Top]=x;
		return 1;
	}
}

//chuzhan

int Pop(SqStack*S,datatype&x)
{
	if(Empty(S))
	{
		printf("zhan xia yi");
		return 0;
	}
	else
	{
		x=S->data[S->Top--];
		return 1;
	}
}

//