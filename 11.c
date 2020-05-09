#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

long long cc(char*start,char*end)
{
	long long n;
	char *j;
	for(j = start; j<end; j++)
		{
				if(j == start)
				n = (long long)atoi(j+1);
				
				if(*j=='*')
				n *=  (long long)atoi(j+1);
				
				if(*j=='/')
				n /=  (long long)atoi(j+1);
		}
		return n;
}

int main()
{
	long long ans=0,n1,n2; 
	char tmp[666666], save[666666], *start, *end, *i, *j;
	
	gets(tmp);	
	start = tmp;
	end = start + strlen(tmp) - 1;
	i=start, j=save;
	
	if (*tmp!='-')
	{
		save[0]='+';
		j++;
	}
	while(*(i)!=0)
	{
		if(*i != ' ')
		{
			*(j++) = *i;
		}		
		i++;
	}
	*j=0;
	
	i = save;
	start = i;
	end = i;
	
	while(*(i++) != 0)
	{
		if(*i == '+' || *i == '-'||*i=='=')
		{
			end = i;
			
			if (*start == '+')
			ans += cc(start,end);			
			if (*start == '-')
			ans -= cc(start,end);
						
			start = i;
		}		
	}
	
	printf("%lld",ans);
	return 0;
}



