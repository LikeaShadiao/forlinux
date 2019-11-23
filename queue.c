//shunxv save struct of queue
typedef struct{
	datatype data[maxsize];
	int front;
	int rear;
}SeQueue;
SeQueue*sq=(SeQueue*)malloc(sizeof(SeQueue));

//Normally use circle queue to save character and less a space(front)
//judge full and null
//sq->rear==sq->front;
//sq->front==(sq->rear+1)%maxsize;

//queue chushihua:shengcheng kong circle queue
void InitQueue(SeQueue*&sq)
{
	sq=(SeQueue*)malloc(sizeof(SeQueue));
	sq->rear=0;
	sq->front=0;
}

//zhikong circle queue
void SetNull(SeQueue*sq)
{
	sq->front=sq->rear=0;
}

//qiu queue changdu
int Len(SeQueue*sq)
{
	return (sq->rear-sq->front+maxsize)%maxsize;
}

//rudui of circle queue
int Enqueue(SeQueue*sq,datatype x)
{
	if((sq->rear+1)%maxsize==sq->front)
	{
		printf("duilie shangyi");
		return 0;
	}
	else
	{
		sq->rear=(sq->rear+1)%maxsize;
		sq->data[sq->rear]=x;
		return 1;
	}
}

//chudui of circle queue
int Dequeue(SeQueue*sq,datatype&x)
{
	if(sq->front==sq->rear)
	{
		printf("duilie xiayi");
		return 0;
	}
	else
	{
		sq->front=sq->(sq->front+1)%maxsize;
		x=sq->front;
		return 1;
	}
}

//qv duitou element
int Getqueue(SeQueue*sq,datatype&x)
{
	if(sq->front==sq->rear)
	{
		printf("duilie xiayi");
		return 0;
	}
	else
	{
		x=sq->data[(sq->front+1)%maxsize];
		return 1;
	}
}

//LinkQueue save struct
typedef struct node
{
	datatype data;
	struct node* next;
}QueueNode;
typedef struct
{
	QueueNode *rear,*front;
}LinkQueue;

//shengcheng konglian duilie
void InitQueue(LinkQueue*&q)
{
	q=(LinkQueue*)malloc(sizeof(LinkQueue));
	q->front=q->rear=(QueueNode*)malloc(sizeof(QueueNode));
	q->front->next=NULL;
}

//zhikong
void SetNull(LinkQueue*q)
{
	q->rear=q->front;
	q->front->next=NULL;
}

//judge if empty
int Empty(LinkQueue*q)
{
	if(q->front==q->rear)
		return 1;
	return 0;
}

//rudui of linkqueue
void Enqueue(LinkQueue*q,datatype x)
{
	q->rear->next=(QueueNode*)malloc(sizeof(QueueNode));
	q->rear=q->rear->next;
	q->rear->data=x;//not "q->data[q->rear]=x;"
}

//chulie of linkqueue
void Dequeue(LinkQueue*q,datatype&x)
{
	if(q->rear==q->front)
	{
		printf("duilie xiayi ");
	}
	else
	{
		QueueNode*s=q->front->next;
		if(s->next==NULL)
		{
			q->front->next=NULL;
			q->front=q->rear;
		}
		else
		{
			q->front->next=s->next;
		}
		x=s->data;
		free(s);
	}
}

//qv duitou element
int Getduitou(LinkQueue*q,datatype&x)
{
	if(Empty(q))
	{
		printf("duilie xiayv");
		return 0;
	}
	else
	{
		x=q->front->next->data;
		return 1;
	}
}

//use circle linklist with headnode behalf queue
//before chudui compare the length with 1
//rudui
void Enqueue(QueueNode*&rear,datatype x)
{
	QueueNode*p=(QueueNode*)malloc(sizeof(QueueNode));
	p->data=x;
	p->next=rear->next;
	rear->next=p;
	rear=p;
}

//chudui
void Dequeue(QueueNode*&rear,datatype&x)
{
	QueueNode*p;
	if(rear->next==rear)
	{
		printf("duixaiyi");
	}
	else
	{
		p=rear->next->next;
		x=p->data;
		if(p==rear)
		{
			rear=rear->next;
			rear->next=rear;
		}
		else
			rear->next->next=p->next;
		free(p);
	}
}

//using two sequent stack to realize queue
void Enqueue(SqStack*s1,datatype x)
{
	if(s1->Top==maxsize-1)
		printf("shangyi");
	else
		Push(s1,x);
}

datatype Dequeue(SqStack*s1)
{
	SqStack *s2;
	datatype x;
	InitStack(s2);
	while(!Empty(s1))
		Push(s2,Pop(s1));//yeah Pop is another function you need to write
	x=Pop(s2);
	while(!Empty(s2))
		Push(s1,Pop(s2));
}

int queue_empty(SqStack*s1)
{
	if(Empty(s1))
		return 1;
	return 0;
}

//Then may be example of apply,but I want to do other work now.