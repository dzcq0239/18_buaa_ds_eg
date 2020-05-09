#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main()
{
	char code[59], book[26];
	gets (code);
	
	int i=1, j, k=1;
	book[0] = code[0];
	
	while ( code[i] != 0)
	{
		for (j=0;j<i;j++)
		if (code[i] == code[j])
		break;
		
		if (j==i)
		book[k++] = code[i];
		
		i++;
	}
	
	for ( j = 'z'; j >= 'a'; j--)
	{
		for ( i= 0; i < k; i ++ )
		if (book[i] == j)
		break;
		
		if (i == k)
		book[k++] = j;
	}
	book[k] = 0;
	
	char c;
	FILE *fr, *fw;
	fr = fopen ("encrypt.txt", "r");
	fw = fopen ("output.txt", "w");
	
	
	while ((c = fgetc (fr)) != EOF )
	{
		if (c >= 'a' && c <= 'z')
		fprintf (fw, "%c", book[c-'a']);		
		
		else
		fprintf (fw, "%c", c);		
	}
	
	fclose (fr);
	fclose (fw);
	return 0;
}



