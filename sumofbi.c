/*save the two big number in two sqlists,and little weizhi saved
the gewei of the two numbers*/
sqlist*add(sqlist*A,sqlist*B)
{
	int flag=0,i=0;
	sqlist*C=(sqlist*)malloc(sizeof(sqlist));
	int m=A->length,n=B->length;
	while(i<m&&i<n)
	{
		C->data[i]=(A->data[i]+B->data[i]+flag)%10;
		flag=(A->data[i]+B->data[i]+flag)/10;
	}
	while(i<m)
	{
		C->data[i]=(A->data[i]+flag)%10;
		flag=(A->data[i]+flag)/10;
	}
	while(i<n)
	{
		C->data[i]=(B->data[i]+flag)%10;
		flag=(B->data[i]+flag)/10;
	}
	C->length=(m>=n?m:n)+flag;
	if(flag) C->data[C->length]=1;
	return C;
}