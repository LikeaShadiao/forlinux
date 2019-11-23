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

//