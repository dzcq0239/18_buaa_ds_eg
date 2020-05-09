#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
typedef struct T {
	int n;
	int c;
	struct T *f;
	struct T *l;
	struct T *r;
} t;
t root;
void save (int b);
void print (t* tp);
int main () {
	int a, b;
	scanf ("%d", &a);
	scanf ("%d", &b);
	root.n = b, a --, root.c = 1;
	while (a --) {
		scanf ("%d", &b);
		save (b);
	}
	print (&root);
	return 0;
}

void save (int b) {
	t* tem = &root;
	while (1) {
		//×ó½Úµã
		if (b < tem->n) {
			if (tem->l == NULL) {
				tem->l = malloc (sizeof (t));
				tem->l->f = tem;
				tem->l->c = tem->c + 1;
				tem = tem->l;
				tem -> n = b, tem->l = tem->r = NULL;
				break;
			} else {
				tem = tem -> l;
			}
		} else {
			if (tem -> r == NULL) {
				tem->r = malloc (sizeof (t));
				tem->r->f = tem;
				tem->r->c = tem->c + 1;
				tem = tem->r;
				tem -> n = b, tem->l = tem->r = NULL;
				break;
			} else {
				tem = tem -> r;
			}
		}
	}
}
void print (t* tp) {
	if (tp == NULL) {
		return;
	}
	if (tp->l == NULL && tp->r == NULL) {
		printf ("%d %d\n", tp->n, tp->c);
	}
	print (tp->l);
	print (tp->r);
}


