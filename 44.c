#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct O {
	struct O *before;
	char f;
	int pos;
	int l;
	char s[599];
	struct O *next;
} e;
void in (char *s, int pos, char *in) {
	int i, j, k;
	i = (j = ( k = 0));
	char tem[599] = {};
	while (i < pos)
		tem[i ++] = s[k ++];
	while (in[j])
		tem [i ++] = in[j ++];
	while (s[k])
		tem[i ++] = s[k ++];
	strcpy (s, tem);
	return ;
}
void de (char *s, char* sa, int pos, int l) {
	int i, j, k;
	i = (j = (k = 0));
	char tem[599] = {};
	while (i < pos)
		tem[i ++] = s[k ++];
	while ((j < l) && s[k])
		sa[j ++] = s[k ++];
	sa[j] = 0;
	while (s[k])
		tem[i ++] = s[k ++];
	strcpy (s, tem);
	return ;
}
int main() {
	char s[599] = {};
	int n, ord;
	gets (s);
	scanf ("%d", &n);
	e *stack = (e*) malloc (sizeof (e)), *top = stack;
	top -> before = stack, top -> next = (top -> f = 0);
	while (n --) {
		top -> next = (e*) malloc (sizeof (e));
		top -> next -> before = top, top = top -> next, top -> next = 0;
		scanf("%d%d", &top -> f, &top -> pos);
		getchar ();
		gets(top -> s);
	}
	while (1) {
		top -> next = (e*) malloc (sizeof (e));
		top -> next -> before = top;
		scanf ("%d", &ord);
		switch (ord) {
			case -1:
				puts (s);
				return 0;
			case 1:
				top = top -> next, top -> next = 0, top -> f = ord;
				scanf("%d", &top -> pos);
				getchar ();
				gets(top -> s);
				in (s, top -> pos, top -> s);
				break;
			case 2:
				top = top -> next, top -> next = 0, top -> f = ord;
				scanf("%d%d", &top -> pos, &top -> l);
				de (s, top -> s, top -> pos, top -> l);
				break;
			case 3:
				free (top -> next);
				switch (top -> f) {
					case 0:
						break;
					case 1:
						de (s, top -> s, top -> pos, strlen (top -> s));
						top = top -> before;
						free (top -> next);
						break;
					case 2:
						in (s, top -> pos, top -> s);
						top = top -> before;
						free (top -> next);
						break;
				}
				break;
		}
	}
}


