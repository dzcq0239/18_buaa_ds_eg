#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct Line
{
	int c;
	int x1,y1;
	int x2,y2;
	struct Line *next;
}co;


int main ()
{
	int n;
	scanf ("%d", &n);
	
	co *start = (co*) malloc (sizeof (co));
	co *end;
		
	int i;
	for (i = 1, start -> c = 0, end = start; i <= n; i ++)
	{
		end -> next = (co*) malloc (sizeof (co));
		end = end -> next;
		end -> c = 1;
		scanf ("%d%d%d%d", &end -> x1, &end -> y1, &end -> x2, &end -> y2);
	}
	
	for (i = 1, end = start -> next; i <= n; i ++, end = end -> next)
	{
		co *tem;
		int isadd = 0, j;

		for (j = 1, tem = start -> next; j <= n; j ++, tem = tem -> next)
		{
			if (tem -> x1 == end -> x2 && tem -> y1 == end -> y2)
			{
				end -> c += tem -> c;
				end -> x2= tem -> x2;
				end -> y2= tem -> y2;
				isadd = 1;
				break;
			}
		}
		while (isadd)
		{
			isadd = 0;
			for (j = 1, tem = start -> next; j <= n; j ++, tem = tem -> next)
			{
				if (tem -> x1 == end -> x2 && tem -> y1 == end -> y2 )
				{
					end -> c += tem -> c ;
					end -> x2= tem -> x2;
					end -> y2= tem -> y2;
					isadd = 1;
					break;
				}
			}	
		}
		
		if (start -> c <= end -> c)
		start -> c = end -> c;
	}
	
	for (i = 1,  end = start -> next; i <= n; i ++, end = end -> next)
	if (start -> c == end -> c)
	{
		printf ("%d %d %d", end -> c, end -> x1, end -> y1);
		break;
	}	
	return 0;
}


