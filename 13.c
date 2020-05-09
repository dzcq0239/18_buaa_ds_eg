#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void re(char *A,int len)
{
	char *start=A, *end=A+(len-1), tem;
	
	while(start<end)
	{
		tem = *start;
		*(start++) = *end;
		*(end--)= tem;
	}
}
void ex(char *A,int s,int l)
{
	char *start=A;
	
	int i=s;
	for(;i<l;i++)
	{
		*(start+i)= '0';		
	}
	*(start+i)=0;
}

int main()
{
	char A[89],B[89];
	
	gets(A);re(A,strlen(A));
	gets(B);re(B,strlen(B));	
	
	
	if (strlen(A)>strlen(B))
	ex(B,strlen(B),strlen(A));
	else
	ex(A,strlen(A),strlen(B));
	
	
	int i=0;
	for(;i<strlen(A);i++)
	{
		A[i] =A[i]-B[i]+'0';
	}
	re(A,strlen(A));
	
	
	char sig='+';	
	int s=0;
	for(;A[s]=='0';s++);
	if(A[s]<'0') 
	{
		sig='-';
		for(i=s;i<strlen(A);i++)
		{
			A[i]= -1*(A[i]-'0')+'0';
		}	
	}
	
	for(i=strlen(A)-1;i>s;i--)
	{
		if(A[i]<'0')
		{
			A[i]+=10;
			A[i-1]-=1;
		}
	}
	
	for(;A[s]=='0';s++);
	
	char *end=A+s;
	if(*end==0)
	{
		printf("0");
		sig='+';	
	}
	if(sig=='-')
	printf("%c",sig);	
	puts(end);	
	return 0;
}



