#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Count
{
	char word[19];
	int n;
	struct Count *next;
}dic;

int main()
{
	char i = 0, c;
	FILE *r = fopen ("article.txt", "r");
	char save[99];
	dic *start = (dic*) malloc (sizeof (dic)), *end = start;
	start -> next = NULL;
	//读入单词； 
	while (~(c = fgetc (r)))
	{
		if (isalpha (c))
		save[i ++ ] = tolower (c);
		else
		{
		save[i] = 0;
		i = 0; 
			if (strlen(save) > 0)
			{
				end -> next = (dic*) malloc (sizeof (dic));
				end = end -> next;
				strcpy (end -> word, save);
				end -> n = 1;
				end -> next = NULL;
			}
		}
	}
	//统计个数;
	dic *tmp;
	for (end = start -> next; end != NULL; end = end -> next)
	{
		for (tmp = end -> next; tmp != NULL; tmp = tmp -> next)
		{
			if (tmp -> n != -1)
			if (strcmp (tmp -> word, end -> word) == 0)
			{
				end -> n ++;
				tmp -> n = -1;
			}
		}
	}
	//字典排序； 
	for (end = start -> next; end != NULL; end = end -> next)
	{
		for (tmp = end -> next; tmp != NULL; tmp = tmp -> next)
		{
			if (strcmp (end -> word, tmp -> word) > 0)
			{
				i = end -> n;
				strcpy (save, end -> word);
				
				end -> n = tmp -> n;
				strcpy (end -> word, tmp -> word);
				
				tmp -> n = i;
				strcpy (tmp -> word, save);		
			}
		}
	}
	//输出结果;
	for (end = start -> next; end != NULL; end = end -> next)
	if (end -> n != -1)
	printf ("%s %d\n", end -> word, end -> n);
	
	fclose (r); 
	return 0;
}


