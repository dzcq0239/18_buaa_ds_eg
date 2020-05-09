#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Save
{
	char name[19];
	long long int phone;
} save[99];

char ko[19]={};

int main()
{
	
	int n;
	scanf("%d",&n);
	getchar();
	
	int m,j;
	for(m=0;m<n;m++)
	{
		j=0;
		char c;
		while((c=getchar())!=' ')
		{
			if(c!='\n')
			save[m].name[j++]=c;
		}
		save[m].name[j]=0;
		scanf("%lld",&save[m].phone);		
	}	
	
	
	for(m=0;m<n;m++)
	{
		int k=0;
		for(j=m+1;j<n;j++)
		{
			int c=strcmp(save[m].name,save[j].name);
			if(c==0)
			{
				if(save[m].phone==save[j].phone)
				strcpy(save[j].name,ko);				
				
				else
				{
					int l=strlen (save[j].name);
					save[j].name[l]='_';
					save[j].name[l+1]='1'+k;
					save[j].name[l+2]=0;
					k++;
				}				
			}		
		}		
	}
	
	for(m=0;m<n;m++)
	{
		for(j=m+1;j<n;j++)
		{
			int c=strcmp(save[m].name,save[j].name);			
			if(c>0)
			{
				char na[19];						
				strcpy(na,save[j].name);				
				strcpy(save[j].name,save[m].name);				
				strcpy(save[m].name,na);
				
				long long int nu;				
				nu=save[m].phone;
				save[m].phone=save[j].phone;
				save[j].phone=nu;
			}
		}
	}



	for(m=0;m<n;m++)
	{
		int c=strcmp(ko,save[m].name);
		if(c!=0)
		{
			int j=0;
			while((save[m].name[j])!=0)
			printf("%c",save[m].name[j++]);
			printf(" %lld\n",save[m].phone);			
		}
	}
	
	return 0;
}



