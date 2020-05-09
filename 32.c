#include <stdio.h>
#include <stdlib.h>
typedef  struct Monkey
{
	int num;
	struct Monkey *next; 	
}mo;
int main ()
{
	mo *start = (mo*) malloc (sizeof (mo));
	mo *end = start;
	int n, m, q;
	scanf ("%d%d%d", &n, &m, &q);
	
	int i;
	for (i = 1, start -> num = 0; i <= n ;i ++, start -> num ++ )
	{
		end -> next = malloc (sizeof (mo));
		end = end -> next;
		end -> num = i;
	}
	end -> next = start -> next;
	
	for (i = 1; i < q; i ++)
	start -> next = (start -> next) -> next;	
	
	for (; start -> num >1; start -> num --)
	{
		end = start -> next;
		for (i = 1; i < m - 1; i ++)
		end = end -> next;
		
		start -> next =  end -> next -> next;		
		free (end -> next);
		end -> next = start -> next;
	}
	printf ("%d", start -> next -> num);	
	return 0;
}


