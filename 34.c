#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Code
{
	int f;
	char c;
	char C;
} book[99];
int main()
{
	//生成原本
	char tmp[99], save[129];
	int i, j, k, t, c;
	gets (tmp);
	book[0].c = tmp[0];
	for (i = 1, k = 1; tmp[i] != 0; i ++)
	{
		for (j = 0; j < i; j ++)
		if (tmp[j] == tmp[i])
		break;
		
		if (j == i)
		book[k++].c = tmp[i];
	}
	for (i = 32; i <= 126; i ++)
	{
		for (j = 0; j < 95; j ++)
		{
			if (i == book[j].c)
			break;
		}
		if(j == 95)
		book[k ++].c = i;
	}
	//生成密码本 
	for(i = 1, k = 0; ; i ++)
	{
		j = k;
		book[j].f = 1;
		
		if (i == 95)
		{
			book[j].C = book[0].c;
			save[book[j].c] = book[j].C;
			break;
		}
		
		for (t = 1; ; k ++)
		{
			if (k > 94)
			k -= 95;
			
			if (book[k].f == 0)
			{
				if (t < book[j].c )
				t ++;
				else
				break;
			}
		}
		book[j].C = book[k].c;
		save[book[j].c] = book[j].C;
	}
	//生成密文 
	FILE *r = fopen ("in.txt","r"), *w = fopen ("in_crpyt.txt","w");
	while (~(c = fgetc(r)))
	{
		if (c > 31 && c < 127)
		fprintf (w, "%c", save[c]);
		else
		fprintf (w, "%c", c);
	}
	
	fclose (w);
	fclose (r); 
	return 0;	
}


