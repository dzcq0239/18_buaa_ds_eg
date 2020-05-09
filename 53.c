#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//元素
typedef struct T {
	int n;
	char o;
	struct T *l;
	struct T *r;
} t;

//树栈
typedef struct S {
	t* p;
	struct S *before;
	struct S *next;
} s;
s *stack, *Top;
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
void Ptree(e* p);
int main() {
	//初始化栈
	e *stack = (e*) malloc (sizeof (e)), *top = stack;
	top -> before = stack, top -> next = NULL, top -> f = 0;
	//初始化表达式
	e *form = (e*) malloc (sizeof (e)), *end = form;
	end -> before = form, end -> next = NULL, end -> f = 0, form -> f = 1;
	//中序-》后续
	int i = 0;
	char c, s[22];
	while ((c = getchar ()) != EOF) {
		if (c != ' ') {
			//数字缓存
			if (isNum (c))
				s[i ++] = c;
			else {
				s[i] = 0, i = 0;
				//数字入式
				if (*s) {
					end -> next = (e*) malloc (sizeof (e));
					end -> next -> before = end, end = end -> next;
					end -> n = atoi (s), end -> f = 0, end -> next = NULL;
					s[i]=0;
				}

				//出栈
				if (c != '(')
					while (isOp (c) <= top -> f) {
						end -> next = (e*) malloc (sizeof (e));
						end -> next -> before = end, end = end -> next;
						end -> o = top -> o, end -> f = 1, end -> next = NULL;
						top = top -> before;
						free (top -> next);
					}
				if (c == '=')
					break;

				//入栈
				if (c != ')') {
					top -> next = (e*) malloc (sizeof (e));
					top -> next -> before = top, top =  top -> next;
					top -> o = c, top -> f = isOp (c);
				}

				else {
					//括号出栈
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
/*
	for (top = form -> next; top != NULL; top = top -> next) {
		if (top -> f != 0)
			printf ("%c ", top -> o);
		else
			printf ("%d ", top -> n);
	}
	printf ("\n");
*/
	Ptree(form -> next);
	//t* tmp = top;
	Top -> p -> o != 0 ? printf ("%c ", Top -> p -> o):printf ("%d ", Top -> p -> n);
	if (Top -> p -> l != NULL) {
		Top -> p -> l ->  o != 0 ? printf ("%c ", Top -> p -> l -> o):printf ("%d ", Top -> p -> l -> n);
	}
	if (Top -> p -> r != NULL) {
		Top -> p -> r ->  o != 0 ? printf ("%c ", Top -> p -> r -> o):printf ("%d ", Top -> p -> r -> n);
	}
	printf ("\n");
/*
	return 0;
	*/

	//后缀计算
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
			} else {
				form -> n = end -> n, form -> f = 0;
			}


/*
			e* t;
			for (t = form -> next; t != NULL; t = t -> next) {
				if (t -> f != 0)
					printf ("%c ", t -> o);
				else
					printf ("%d ", t -> n);
			}
			printf ("\n");
*/


		}
	}
	printf ("%d", form -> n);
	return 0;
}
void Ptree(e* p) {
	for (; p != NULL; p = p -> next) {
		if(p -> f == 0) {
			if (Top == NULL) {
				Top = stack = malloc (sizeof (s));
				Top -> before = Top -> next = NULL;
				Top -> p = malloc (sizeof (t));
				Top -> p -> n = p->n;
				Top -> p -> o = 0;
				Top -> p -> r = Top -> p -> l = NULL;
			} else {
				Top -> next = malloc (sizeof (s));
				Top -> next -> before = Top;
				Top = Top -> next;
				Top -> next = NULL;
				Top -> p = malloc (sizeof (t));
				Top -> p -> n = p->n;
				Top -> p -> o = 0;
				Top -> p -> r = Top -> p -> l = NULL;
			}
		} else {
			t* tem = malloc (sizeof (t));
			tem -> o = p -> o;
			tem -> r = Top -> p;
			Top = Top -> before;
			tem -> l = Top -> p;
			Top -> p = tem;
		}
	}
}



