#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void Scan(char*start,char*save)
{
	for(;*start!=0;start++)
	{
		if(*start!='.')
		*save++=*start;
	}
	*save=0;
} 


int main()
{
	char A[109];
	gets(A);
	
	char *start=A-1,*doc, *i;
	char sig='+';
	doc = A+strlen(A)-1;
	
	while(*start<='0'||*start>'9')
	{
		start++;
		if (*start=='.')
		{
			sig = '-';
			doc = start;
		}
	}
	
	if(sig=='+')
	{
		for(i=start;i<A+strlen(A)-1;i++)
		{
			if(*i=='.')
			{
				doc=i;
				break;
			}
		}
	}
	
	char save[109];
	Scan(start,save);
	
	char *end=save+strlen(save)-1;
	while(*end == '0')
	{
		*(end--) = 0;
	}
	
	if((strlen(save) == 1))
	printf("%c%se%d",*save,save+1,doc-start);	
	else if(doc == A+strlen(A)-1)
	printf("%c.%se%d",*save,save+1,doc-start);	
	else if	(doc-start>0)
	printf("%c.%se%d",*save,save+1,doc-start-1);
	else
	printf("%c.%se%d",*save,save+1,doc-start);
	
	return 0;
}


