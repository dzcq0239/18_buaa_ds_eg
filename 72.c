#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#define M 3009
//
struct E {
	int no;
	int from;
	int to;
} edge[M];
//
typedef struct A {
	char ans[M];
	struct A* next;
} a;
a * start;
//
int v,e, isV[M], tmp, from, to, Que[M];
char s[M];
//
void D(void);
void DFS(int, int);
void sAve(char *s);
void shoW(void);
//
int main() {
	scanf ("%d%d", &v, &e);
	int i;
	for (i = 0; i < 2 * e; i += 2) {
		scanf ("%d%d%d", &edge[i].no, &edge[i].from, &edge[i].to);
		edge[i + 1].no = edge[i].no;
		edge[i + 1].from = edge[i].to;
		edge[i + 1].to = edge[i].from;
	}
	D();
	shoW();
	return 0;
}
void D() {
	from = 0, to = v - 1;
	int i;
	isV[0] = -1;
	for (i = 1; i < v; i ++) {
		isV[i] = 0;
	}
	DFS (0, 0);
}
void DFS(int p, int d) {
	int i, k, start, end;
	if (p == to) {
		s[d] = 0;
		sAve(s);
		return ;
	}

	for (i = 0; i < 2 * e; i ++) {
		start = edge[i].from;
		end = edge[i].to;
		k = edge[i].no;
		if (start == p) {
			if (~ isV[end]) {
				s[d] = '0' + k;
				isV[end] = -1;
				DFS(end, d + 1);
				isV[end] = 0;
			}
		}
	}
}

void sAve(char *s) {
	if (start == NULL) {
		start = malloc(sizeof (a));
		start -> next = NULL;
		strcpy (start -> ans, s);
	} else {
		a *t = malloc(sizeof (a));
		t -> next = start;
		start = t;
		strcpy (t -> ans, s);
		for (t = start; t -> next; t = t -> next) {
			if (strcmp (t -> ans, t -> next -> ans) > 0) {
				char sw[M];
				strcpy (sw, t -> ans);
				strcpy (t -> ans, t -> next -> ans);
				strcpy (t -> next -> ans, sw);
			}
		}
	}
	return;
}
void shoW() {
	a *t;
	for (t = start; t; t = t -> next) {
		char *p;
		for (p = t -> ans; *p; p ++) {
			printf ("%d ", *p - '0');
		}
		printf ("\n");
	}
	return;
}



