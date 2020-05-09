#include <stdio.h>
#include <stdlib.h>
typedef struct C {
	int n;
	int t;
	struct C *next;
} e;
int main() {
	int i, que = 0;
	double win = 3, con, No = 1;
	e *head, *end, *tem;
	head = (end = 0);
	int rnd;
	scanf ("%d", &rnd);
	while (rnd --) {
		scanf ("%lf",&con);
		que += (int) con;
		for (win = 3; (win < 5) && (que / win >= 7); win ++);
		for (i = 0; i < con; i ++) {
			if (! head)
				end = (head = malloc (sizeof (e)));
			else {
				end -> next = malloc (sizeof (e));
				end = end -> next;
			}
			end -> n = (No ++);
			end -> next = (end -> t) = 0;
		}
		for (i = 0; head && i < win; i ++) {
			printf ("%d : %d\n", head -> n, head -> t);
			tem = head, head = head -> next;
			free (tem);
			que --;
		}
		if (head)
			for (tem = head; tem; tem = tem -> next)
				tem -> t ++;
	}
	while (que > 0) {
		for (; que && (win > 3) && (que / win < 7); win --);
		for (i = 0; head && i < win; i ++) {
			printf ("%d : %d\n", head -> n, head -> t);
			tem = head, head = head -> next;
			free (tem);
			que --;
		}
		if (head)
			for (tem = head; tem; tem = tem -> next)
				tem -> t ++;
	}
	return 0;
}


