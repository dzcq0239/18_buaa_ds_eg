#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int min(a,b)
{
	if(a>b)
	return b;
	return a;
}
int main ()
{
	char a[99] = {}, b[99] = {};	
	gets (a);
	gets (b);
	
	FILE *fr, *fa;
	fr = fopen ("filein.txt", "r");
	fa = fopen ("fileout.txt", "w");	
	char s[99] = {};
	
	while( fgets (s, 90, fr) != NULL)
	{
		int i, j, k;
		for(i = 0; s[i] != 0; i++ )
		{
			for( j = i, k = 0; a[k] != 0 && tolower (s [j]) == tolower (a[k]); j++, k++);
			
			if (k == strlen (a))
			{
				for (j = 0; j < strlen (b); j++ )
				fprintf (fa, "%c", b[j]);
				i += min (j, k-1);
			}			
			else
			fprintf ( fa, "%c", s[i]);
		}
	}
	fclose (fr);
	fclose (fa);
	return 0;
}


