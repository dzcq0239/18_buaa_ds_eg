#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char a[7777777];
int address[7777777];
void sadd()
{
	int i=0,j=0;
	for (;i<strlen(a);i++)
	{
		address[i]=-1;
		if(a[i]=='-'&&
		(
		(
		(((a[i-1]>='0')&&(a[i-1]<='9'))&&((a[i+1]>='0')&&(a[i+1]<='9')))||
		(((a[i-1]>='a')&&(a[i-1]<='z'))&&((a[i+1]>='a')&&(a[i+1]<='z')))||
		(((a[i-1]>='A')&&(a[i-1]<='Z'))&&((a[i+1]>='A')&&(a[i+1]<='Z')))
		)
		)
		)
		{
			address[j++]=i;
			
		}
	}
}
int main()
{
	gets(a);
	sadd();
	
	int m=0,n=0;
	for(;m<strlen(a);m++)
	{
		printf("%c",a[m]);
		if(m+1 == address[n])
		{			
			int i=1;
			for(;i< a[m+2]-a[m];i++)
			{
				printf("%c",a[m]+i);
			}
			m++;			
			n++;
		}
	}
	
	return 0;
}



