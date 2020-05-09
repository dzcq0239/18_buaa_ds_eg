#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char ko[9]={};
struct books
{
	char bn[59];
	char wn[29];
	char pn[39];
	char da[9];
}lib[509],t;

void save (char *s, int *n )
{	
	int i, j=0, co=0;
	for (i = 0; s[i] != 0; i ++)
	{
		if (co == 3 && j == 4)
		{
			(*n) ++;
			break;
		}
		if (s[i] == ' ')
		{
			co ++;
			j = 0;
		}
		else
		{
			if (co == 0)
			lib[*n].bn[j++] = s[i];
			if (co == 1)
			lib[*n].wn[j++] = s[i];
			if (co == 2)
			lib[*n].pn[j++] = s[i];
			if (co == 3)
			lib[*n].da[j++] = s[i];
		}
	}
	strcpy (s, ko);	
	return ;
}

void ord(int *n)
{
	int i, j;
	for (i = 0; i<= *n; i ++)
	{
		for (j = i+1; j <= *n; j ++ )
		{
			int c = strcmp(lib[i].bn, lib[j].bn);
			if ( c > 0)
			{
				t = lib[j];
				lib[j] = lib [i];
				lib[i] = t;
			}
		}
	}
	return ;
}

int search(int *n, int i, char *s)
{
	char ko[9] = {};
	int j, k, l;
	for (j = 0; lib[i].bn[j] != 0; j ++)
	{
		for (k = j, l = 0; s[l] != 0 && tolower(lib[i].bn[k]) == tolower(s[l]); k ++, l ++);
			if (strcmp (ko, lib[i].da) != 0 && l == strlen (s))
				return i;
	}
	return -1;
}

int main()
{
	FILE *op = fopen ("books.txt", "r")	, *wr = fopen ("ordered.txt", "w");
	
	char s[150];
	int n = 0, *f = &n;
	while (fgets (s, 149, op) != NULL)
	save (s, f);
	fclose (op);
	
	int z;
	while (~ scanf ("%d ", &z))
	{
		ord (f);
		
		if (z == 0)
		{
			int i;
			for (i = 0; i <= n; i ++)
			if (strcmp (ko, lib[i].da) != 0)
			fprintf(wr, "%-50s%-20s%-30s%-10s\n", lib[i].bn,lib[i].wn,lib[i].pn,lib[i].da);
			fclose (wr);
			return 0;
		}
		
		if (z == 1)
		{
			n ++;
			gets (s);
			save (s, f);
		}
		
		if (z == 2)
		{
			gets (s);
			int i;
			for (i = 0; i <= n; i ++)
			{
				int j = search (f, i, s);
				if (~j)
				printf("%-50s%-20s%-30s%-10s\n", lib[i].bn,lib[i].wn,lib[i].pn,lib[i].da);	
			}
		}
		
		if (z == 3)
		{
			gets (s);
			int i;
			for (i = 0; i <= n; i ++)
			{
				int j = search (f, i, s);
				if (~j)
				strcpy (lib[i].da, ko );
			}
		}
	}
}


