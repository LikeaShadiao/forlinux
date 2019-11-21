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

//qv zhanding yvansu
int GetStack(SqStack*S,datatype&x)
{
	if(Empty(S))
	{
		printf("zhan xia yi\n");
		return 0;
	}
	else
	{
		x=S->data[S->Top];
		return 1;
	}
}

//liang ge stack gongxiang lianxv space
//zheyangde shujv storage struct
typedef struct{
	datatype v[maxsize];
	int Top1,Top2;
}SqStack;
SqStack*S=(SqStack*)malloc(sizeof(SqStack));


//jin zhan
void Pushh(SqStack*S,datatype x,int i)//to insert x to i hao zhan
{
	if(S->Top1+1==S->Top2)
	{
		printf("zhan shang yi");
	}
	else if(i==1)
		S->v[++S->Top1]=x;
	else
		S->v[--S->Top2]=x;
}

//chu zhan
datatype Popp(SqStack*S,int i)
{
	datatype x;
	if(i==1)
		if(S->Top1==-1)
			printf("1 hao zhan xiayi");
		else
			x=S->v[S->Top1--];//bushi Top
	else if(S->Top2==maxsize)
		printf("er hao zhan xiayi");
	else
		x=S->v[S->Top2++];
	return x;
}

//xiaokuohao pipei
void corrent(char ex[])
{
	SqStack*S;
	InitSqStack(S);
	int i=0;
	while(i<strlen(ex[]))
	{
		ch=ex[i];
		switch(ch)
		{
			case '(':
			Push(S,ch);
			break;
			case ')':
			if(Empty(S)||Pop(S)!='(')
				return "expect(";
		}
		i++;
	}
	if(!Empty(S)) return "expect)";
	else return"OK";
}