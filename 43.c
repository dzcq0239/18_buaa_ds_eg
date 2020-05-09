#include <stdio.h>
#include <stdlib.h>
typedef struct E {
	struct E *before;
	char f;
	int n;
	char o;
	struct E *next;
} e;
int isOp (int c) {
	if (c == '+' || c == '-' )
		return 2;
	else if (c == '*' || c == '/' || c == '%' )
		return 3;
	else if (c == '=' || c == ')')
		return 1;
	else
		return 0;
}
int isNum (int c) {
	if (c >= '0' && c <= '9')
		return 1;
	else
		return 0;
}
int main() {
	e *stack = (e*) malloc (sizeof (e)), *top = stack;
	top -> before = stack, top -> next = NULL, top -> f = 0;
	e *form = (e*) malloc (sizeof (e)), *end = form;
	end -> before = form, end -> next = NULL, end -> f = 0, form -> f = 1;
	int i = 0;
	char c, s[22];
	while ((c = getchar ()) != EOF) {
		if (c != ' ') {
			if (isNum (c))
				s[i ++] = c;
			else {
				s[i] = 0, i = 0;
				if (*s) {
					end -> next = (e*) malloc (sizeof (e));
					end -> next -> before = end, end = end -> next;
					end -> n = atoi (s), end -> f = 0, end -> next = NULL;
					s[i]=0;
				}
				if (c != '(')
					while (isOp (c) <= top -> f) {
						end -> next = (e*) malloc (sizeof (e));
						end -> next -> before = end, end = end -> next;
						end -> o = top -> o, end -> f = 1, end -> next = NULL;
						top = top -> before;
						free (top -> next);
					}
				if (c == '=') {
					end -> next = (e*) malloc (sizeof (e));
					end -> next -> next = (e*) malloc (sizeof (e));
					end -> next -> before = end;
					end -> next -> next -> before = end -> next;
					end -> next -> n = (end -> next -> f = (end -> next -> next -> next = 0));
					end -> next -> next -> o = '+';
					end -> next -> next -> f = 9;
					break;
				}

				if (c != ')') {
					top -> next = (e*) malloc (sizeof (e));
					top -> next -> before = top, top =  top -> next;
					top -> o = c, top -> f = isOp (c);
				}

				else {
					while (top -> o != '(') {
						end -> next = (e*) malloc (sizeof (e));
						end -> next -> before = end, end = end -> next;
						end -> o = top -> o, end -> next = NULL, end -> f = 1;
						top = top -> before;
						free (top -> next);
					}
					top = top -> before;
					free (top -> next);
				}
			}
		}
	}
	for (top = form -> next; form -> f; top = top -> next) {
		if (top -> f) {
			end = (e* ) malloc (sizeof (e));
			end -> f = 0;
			switch (top -> o) {
				case'+':
					end -> n = top -> before -> n + top -> before -> before -> n;
					break;
				case'-':
					end -> n = top -> before -> before -> n - top -> before -> n;
					break;
				case'*':
					end -> n = top -> before -> n * top -> before -> before -> n;
					break;
				case'/':
					end -> n = top -> before -> before -> n / top -> before -> n;
					break;
				case'%':
					end -> n = top -> before -> before -> n % top -> before -> n;
					break;
			}
			if (top -> next != NULL) {
				end -> next = top -> next, end -> before = top -> before -> before -> before;
				top -> next -> before = end;
				top = end -> before;
				free (top -> next -> next -> next);
				free (top -> next -> next);
				free (top -> next);
				top -> next = end;
			} else
				form -> n = end -> n, form -> f = 0;

		}
	}
	printf ("%d", form -> n);
	return 0;
}


