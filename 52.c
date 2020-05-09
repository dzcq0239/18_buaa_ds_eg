#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
typedef struct T {
	char w[59];
	int c;
	struct T *f;
	struct T *l;
	struct T *r;
} t;
t root;


int isA (int c);


void save (char *s);
void print (t* tp);
int main () {
	int i = 0;
	char s[59] = {}, c;
	FILE *in = fopen ("article.txt", "r");
//初始化root
	while (c = fgetc (in)) {
		if (isA (c)) {
			s[i ++] = tolower (c);
		} else {
			s[i ++] = 0;

			if (*s) {
				strcpy (root.w, s);
				root.c ++;
				i = s[0] = 0;
				break;
			}
			i = s[0] = 0;
		}
	}
//生成树
	while ((c = fgetc (in)) != EOF) {
		if (isA (c)) {
			s[i ++] = tolower (c);
		} else {
			i = s[i ++] = 0;
			if (*s)
				save (s);
		}
	}
	t *tem = &root;
	for (tem = &root, i = 0; tem != NULL && i <3; tem = tem -> r, i ++ )
		printf ("%s ", tem -> w);
	printf ("\n");
	print(&root);
	return 0;
}

void save (char *s) {
	t* tem = &root;
	while (1) {
		//左节点
		if (strcmp (s,tem -> w) < 0) {
			if (tem->l == NULL) {
				tem->l = malloc (sizeof (t));
				tem->l->f = tem;
				tem->l->c = 1;
				tem = tem->l;
				strcpy (tem -> w,s);
				tem->l = tem->r = NULL;
				break;
			} else {
				tem = tem -> l;
			}
		} else if (strcmp (s,tem -> w) > 0) {
			if (tem -> r == NULL) {
				tem->r = malloc (sizeof (t));
				tem->r->f = tem;
				tem->r->c = 1;
				tem = tem->r;
				strcpy (tem -> w,s);
				tem->l = tem->r = NULL;
				break;
			} else {
				tem = tem -> r;
			}
		} else {
			tem -> c ++;
			break;
		}
	}
}

void print (t* tp) {
	if (tp == NULL) {
		return;
	}
	print (tp->l);
	printf ("%s %d\n", tp->w, tp->c);
	print (tp->r);

}
/**/

int isA (int c) {
	if ((c <= 'Z' &&c >= 'A') || (c <= 'z' &&c >= 'a'))
		return 1;
	return 0;
}


