//sequent save struct of string
//using a int to show the length of string
#define maxsize 256
typedef struct
{
	char ch[maxsize];
	int length;
}SqString;
SqString *s;

//using '\0' as ending mark
#define maxsize 256
typedef char sstring[maxsize];
sstring s;

//using s[0] to store the length of string.


//determine length of string
int StrLength(char*s)
{
	int l=0;
	while(s[l]!='\0')
		l++;
	return l;
}

//copy s2 to s1
void StrCopy(char*s1,char*s2)
{
	int i=0;
	while(s1[i++]=s2[i++]);
	s1[i]='\0';
}

//compare the two strings,if s1>s2,return value>0,and so on;
int StrCmp(char*s1,char*s2)
{
	int i=0;
	while(s1[i]==s2[i]&&s1[i]!='\0')
		i++;
	return s1[i]-s2[i];
}

//connect two strings
int StrCat(char*s1,char*s2)
{
	int len1,len2,i=0,j=0;
	len1=StrLength(s1);
	len2=StrLength(s2);
	if(len1+len2>maxsize-1)
		return 0;
	else
	{
		while(s1[i]!='\0')
			i++;
		while(s2[j]!='\0')
			s1[i++]=s2[j++];
		s1[i]='\0';
		return 1;
	}
}

//using library function of C to realize get little string from big string
#include<stdio.h>
#include<string.h>
void SubStr(char*,char*,int,int);
void main()
{
	char s1[]="d:\\user\\wang\\",s2[80];
	int start,length;
	printf("start,length=");
	scanf("%d,%d",&start,&length);
	SubStr(s2,s1,start,length);
	puts(s2);
}
void SubStr(char*sub,char*s,int pos,int len)
{
	if(pos<1||pos>strlen(s)||len<0)
		printf("data error\n");
	else
	{
		strncpy(sub,s+pos-1,len);
		strcpy(sub+len,"\0");
	}
}

//link store struct of string
//jiedian daxiao == 4
#define CHUNKSIZE 4
typedef struct node
{
	char ch[CHUNKSIZE];
	struct node *next;
}Chunk;
typedef struct 
{
	Chunk *head,*tail;
	int length;
}LinkString;
LinkString s;

//realize two linkstring merge
//main sentences
s1->tail=s2->head;
s1->tail=s2->tail;
s1->length=s1->length+s2->length;

//mode match of string
//match of sequent string
int Index(SqString*S,SqString*T,int pos)
{
	int i=pos,j=1;
	while(i<=T->length&&j<=P->length)
	{
		if(T->ch[i-1]==S->ch[j-1])
		{
			i++;
			j++;
		}
		else
		{
			i=i-j+2;
			j=1;
		}
	}
	if(j>P->length)
		return(i-p->length);
	else
		return 0;
}

//match of linked string
LinkString*Index(LinkString*T,LinkString*P,LinkString*pos)
{
	LinkString*shift,*tp,*pp;
	shift=pos;
	tp=shift;
	pp=P;
	while(tp!=NULL&&pp!=NULL)
	{
		if(tp->data==pp->data)
		{
			tp=tp->next;
			pp=pp->next;
		}
		else
		{
			shift=shift->next;
			tp=shift;
			pp=P;
		}
	}
	if(pp==NULL)
		return shift;
	else
		return NULL;
}

//then to shuzu