#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

typedef struct T {
	int c;
	int n;
	struct T *l;
	struct T *r;
} t;
typedef struct S {
	struct T *tr;
	struct S *before;
	struct S *next;
} s;

t* Ptr(char c, int q);
s* inS (s* top,t* e);
s* Cut(s* stack);
void Ord (s* start);
int Read(t* b,int c, int d);

int a[129], z = 0;
char book[129][99], ans[88888888], tem[9];
int main() {
	FILE *in = fopen ("input.txt", "r");
	int c;
	//¼ÓÈ¨
	a[0] ++;
	while ( (c = fgetc (in)) != EOF) {
		if (c != '\n') {
			a[c] ++;
		}
	}
	//ÖÖÊ÷
	s *stack, *end;
	end = stack = malloc (sizeof(s));
	end -> before = end -> next = NULL;
	end -> tr = Ptr (0, 1);
	for (c = 1; c < 129; c ++) {
		if (a[c]) {
			end = inS(end, Ptr (c, a[c]));
		}
	}
	//ÅÅÐò
	Ord(stack);
	//¿³Ê÷
	while (stack -> next) {
		stack = Cut (stack);
	}
	//ÅÀÊ÷
	in = fopen ("input.txt", "r");
	while ((c = fgetc (in)) != EOF) {
		int i;
		read (stack -> tr, c,1);
		strcat (ans, book[c]);
	}
	read (stack -> tr, 0,1);
	strcat (ans, book[0]);
	while (strlen (ans) %8 != 0)
		strcat (ans,"0");
	FILE *out = fopen ("output.txt","w");
	fputs (ans, out);

	int i, j,k;
	char *p = ans;
	while (*p) {
		for (i = j = 0, z = 0; j < 8; j ++, p ++) {
			tem[j] = *p;
			z += (*p - '0' ) *pow (2,7 - j);
		}
		tem [j] = 0;
		printf ("%x",z);
	}
	return 0;
}

t* Ptr(char c, int q) {
	t* p = malloc (sizeof (t));
	p -> l = p -> r = NULL;
	p -> c = c;
	p -> n = q;
	return p;
}

s* inS(s* top, t* e) {
	top -> next = malloc (sizeof (s));
	top -> next -> before = top;
	top = top -> next;
	top -> next = NULL;
	top -> tr = e;
	return top;
}

void Ord (s* start) {
	s*p1,*p2;
	for (p1 = start; p1 -> next; p1 = p1 -> next) {
		for (p2 = start; p2 -> next; p2 = p2 -> next) {
			if (p2 -> tr -> n > p2 -> next -> tr -> n) {
				t* tem = p2 -> tr;
				p2 -> tr = p2 -> next -> tr;
				p2 -> next -> tr = tem;
			}
		}
	}
	return;
}

s* Cut (s* start) {
	t* n = malloc (sizeof (t));
	n -> l = start -> tr;
	n -> r = start -> next -> tr;
	n -> n = n -> l -> n + n -> r -> n;
	n -> c = -1;
	start = start -> next;
	//free(start -> before -> before);
	start -> before = NULL;
	start -> tr = n;
	s* sw;
	for (sw = start; sw -> next; sw = sw -> next ) {
		if (sw -> tr -> n >= sw -> next -> tr -> n) {
			t* tem = sw -> tr;
			sw -> tr = sw -> next -> tr;
			sw -> next -> tr = tem;
		} else break;
	}
	return start;
}

int read(t* b,int c, int d) {
	if (b -> c != -1) {
		if (b -> c == c)
			return d;
		else
			return 0;
	} else {
		if (read (b -> l, c, d +1)) {
			book[c][d-1] = '0';
			return d;
		}
		if (read (b -> r, c, d +1)) {
			book[c][d-1] = '1';
			return d;
		}
	}
}


