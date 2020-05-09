#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
typedef struct C {
	char name[29];
	int gen;
	struct C *f;
	struct C *l;
	struct C *r;
} c;
c root, *ad;
int low (int a);
void add (char *f, char *cl, char *cr);
void seek (char *f, c* t);
int main() {
	root.gen = 1;
	FILE *in = fopen ("in.txt", "r");
	char a, b, s[4][29];
	int n;
	fgets (s[0], 19, in);
	n = atoi (s[0]);
	int i,j,k;
	i = j = k = 0;
	while ((a = fgetc (in)) != EOF) {
		//0b = lower
		if (a == ' ') {
			s[i][j] = 0;
			i ++, j = 0;
		} else if (a == '\n') {
			s[i][j] = 0;
			i = j = 0;
			//上树
			if (s[0][0]) {
				//换儿子
				if (strcmp (s[1], s[2]) > 0) {
					strcpy (s[3], s[1]);
					strcpy (s[1], s[2]);
					strcpy (s[2], s[3]);
				}
				if (strcmp (s[1], "NULL") == 0) {
					strcpy (s[3], s[1]);
					strcpy (s[1], s[2]);
					strcpy (s[2], s[3]);
				}
				//上儿子
				add (s[0], s[1], s[2]);
			}
		} else {
			s[i][j ++] = a;
		}
	}
	scanf ("%s", s[1]);
	scanf ("%s", s[2]);
	c *p1, *p2;
	seek (s[1], &root);
	p1 = ad;
	seek (s[2], &root);
	p2 = ad;
	if (p1 -> gen < p2 -> gen)
		printf ("%s %s %d\n", p2 -> name, p1 -> name, p2 -> gen -p1 -> gen);
	else if ((p1 -> gen > p2 -> gen))
		printf ("%s %s %d\n", p1 -> name, p2 -> name, p1 -> gen -p2 -> gen);
	else {
		c *f1, *f2 ;
		for (f1 = p1, f2 = p2; strcmp(f1 -> name, f2 -> name) != 0; f1 = f1 -> f, f2 = f2 -> f);

		printf ("%s %s %d\n", f1 -> name, p1 -> name, p1 -> gen - f1 -> gen);
		printf ("%s %s %d\n", f2 -> name, p2 -> name, p2 -> gen - f2 -> gen);
	}
	return 0;
}
int low (int a) {
	int z = tolower (a);
	if (z <= 'z' && z >= 'a' )
		return z;
	else
		return 0;
}
void add (char *f, char *cl, char *cr) {
	c *tem;
	if (ad == NULL)
		ad = &root;
	else
		seek (f, &root);
	tem = ad;
	strcpy (tem -> name, f);
	tem -> l = malloc (sizeof (c));
	tem -> r = malloc (sizeof (c));
	tem -> l -> l =tem -> l -> r =tem -> r -> l =tem -> r -> r = NULL;
	tem -> l -> f = tem -> r -> f = tem;
	strcpy (tem -> l -> name, cl);
	tem -> r -> gen = tem -> l -> gen = tem -> gen + 1;
	strcpy (tem -> r -> name, cr);
	return ;
}
void seek (char *f, c* t) {
	if (t == NULL)
		return ;
	if (strcmp (f, t -> name) == 0) {
		ad = t;
		return ;
	} else {
		seek (f, t -> l);
		seek (f, t -> r);
	}
}

