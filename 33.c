#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct Ty
{
	long long int c;
	int n;
	int f;
	struct Ty *next;
} sx;

int main ()
{
	//读入S1x；
	sx *start1 = (sx*) malloc (sizeof (sx)), *end1 = start1;
	start1 -> next = NULL;
	start1 -> f = 0;
	while (1)
	{
		end1 -> next = (sx*) malloc (sizeof (sx));
		end1 = end1 -> next;
		scanf ("%lld%d", &end1 -> c, &end1 -> n);
		start1 -> f ++;
		if (getchar () == '\n')
		break;
	}
	end1 -> next = NULL;
	
	//读入S2x； 
	sx *start2 = (sx*) malloc (sizeof (sx)), *end2 = start2;
	start2 -> next = NULL;
	start2 -> f = 0;
	while (1)
	{
		end2 -> next = (sx*) malloc (sizeof (sx));
		end2 = end2 -> next;
		scanf ("%lld%d", &end2 -> c, &end2 -> n);
		start2 -> f ++;
		if (getchar () == '\n')
		break;
	}
	end2 -> next = NULL;
	
	//S3x= S1x * S2x;
	sx *start3 = (sx*) malloc (sizeof (sx)), *end3 = start3;
	start3 -> next = NULL;
	for (end1 = start1 -> next; end1 != NULL; end1 = end1 ->next)
	{
		for (end2 = start2 -> next; end2 != NULL; end2 = end2 ->next)
		{
			end3 -> next = (sx*) malloc (sizeof (sx));
			end3 = end3 -> next;
			end3 -> c = end1 -> c * end2 -> c;
			end3 -> n = end1 -> n + end2 -> n;
			end3 -> f = 1;
		}
	}
	end3 -> next = NULL;
	
	//合并同类项;
	for (end3 = start3 -> next;end3 != NULL; end3 = end3 ->next )
	{
		sx *tem;
		for (tem = end3 -> next; tem != NULL; tem = tem ->next)
		{
			if (tem -> f == 1)
			{
				if (tem -> n == end3 -> n)
				{
					end3 -> c += tem -> c;
					tem -> f = 0;
				}
			}
		}
	}
	
	//指数升序； 
	for (end3 = start3 -> next; end3 != NULL; end3 = end3 ->next )
	{
		if (end3 -> f != 0)
		{
			sx *tem;
			for (tem = end3 -> next; tem != NULL; tem = tem ->next)
			{
				if (tem -> f != 0)
				{
					if (end3 -> n <= tem -> n)
					{
						struct Ty t;
						t . c = tem -> c;
						t . n = tem -> n;
						tem -> c = end3 -> c;
						tem -> n = end3 -> n;
						end3 -> c = t . c;
						end3 -> n = t . n;
					}
				}
			}
		}
	}
	
	//输出；
	for (end3 = start3 -> next; end3  != NULL; end3 = end3 -> next)
	{
		if (end3 -> c && end3 -> f)
		printf("%lld %d ", end3 -> c, end3 -> n);
	}
	
	return 0;
} 


