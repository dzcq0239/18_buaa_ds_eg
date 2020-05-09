#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
struct S {
	int id;
	char name[29];
	int po;
} book[109], tem;
int count[999];
void showMe(int, int);
void Ord(int, int);
int main() {
	FILE *in = fopen ("in.txt", "r");
	//T1
	int n, i, j, m = -1;
	scanf ("%d", &n);
	for (i = 0; i < n; i ++) {
		fscanf (in, "%d %s %d", &book[i].id, book[i].name, &book[i].po);
		if (book[i].po > m) {
			m = book[i].po;
		}
		count [book[i].po] ++;
	}
	//showMe(n, m);

	//T1 -> T2
	Ord(n, 1);
	//showMe(n,m);

	int q = m > n ? n : m, p = n - 1;
	for (i = 1; i <= q; i ++) {
		if (i < book[p].po) {
			if (count [i] == 0) {
				book[p --].po = i;
				m = book[p].po;
			}
		}
	}


//showMe(n, m);

	for (i = 1; i < n; i ++) {
		if (book[i].po == book[i - 1].po) {
			for (j = i; book[j + 1].po ==  book[j].po; j ++);
			book[j].po = ++ m;
			i --;
		}
	}
//showMe(n,m);

	Ord (n, 0);
//showMe(n, m);

	FILE *out = fopen ("out.txt", "w");
	for (i = 0; i < n; i ++)
		fprintf (out, "%d %s %d\n", book[i].id, book[i].name, book[i].po);
	return 0;
}
void showMe(int n, int m) {
	printf ("\n%d\n", m);
	int i;
	for (i = 0; i < n; i ++)
		printf ("%d %s %d\n", book[i].id, book[i].name, book[i].po);
	printf ("*********************\n\n");
}
void Ord(int n, int f) {
	int i, j;
	for (i = 0; i < n - 1; i ++) {
		if (f) {
			for (j = 0; j < n - 1; j ++) {
				if (book[j].po > book[j + 1].po) {
					tem = book[j];
					book[j] = book [j + 1];
					book[j + 1] = tem;
				}
			}
		} else {
			for (j = 0; j < n - 1; j ++) {
				if (book[j].id > book[j + 1].id) {
					tem = book[j];
					book[j] = book [j + 1];
					book[j + 1] = tem;
				}
			}
		}
	}
	return;
}

