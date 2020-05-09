#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define F -'a'+1
struct WL {
	char word[29];
} wl[3999];
struct Ind {
	int start;
	int n;
} ind[29];

struct H {
	char word[29];
	struct H* next;
} hb[3999];


void addW (char *, int);
void addh (char *);
void find (char *, int);
unsigned int hash (char *s);

int main() {
	FILE *dic = fopen ("dictionary3000.txt", "r");
	char s[29]= {},c;
	int i,j,k;
	i = j = k =0;
	//读词典
	while ((c = fgetc (dic)) != EOF) {
		if (isalpha (c)) {
			s[i ++] = c;
		} else  {
			s[i] = 0;
			if (*s) {
				//生成单词表,索引
				addW (s, j ++);
				//生成hash表
				addh (s);
			}
			i = 0;
		}
	}
	while (~scanf ("%s", s)) {
		scanf ("%d", &i);
		find (s,i);
	}
	return 0;
}

void addW (char *s, int j) {
	//生成单词表
	strcpy (wl[j].word, s);

	//生成索引
	int t = *s F;
	if (! ind[t].start) {
		ind[t].start = ind[0].n;
		//ind[t].n --;
	}
	ind[t].n ++;
	ind[0].n ++;
}

unsigned int hash (char *s) {
	unsigned int h = 0;
	char *p;
	for(p = s; *p != '\0'; p ++)
		h = h * 37 + *p;
	return h % 3001;
}
void addh (char *s) {
	int h = hash (s);
	if (! hb[h].word[0]) {
		strcpy (hb[h].word, s);
	} else {
		struct H* t = malloc (sizeof (struct H));
		hb[h].next =  t;
		t -> next = NULL;
		strcpy (t -> word, s);
	}
	return;
}
void find (char *s, int way) {
	int flag = 0, step = 0;
	switch (way) {

		case 1: {
			for (; strcmp (wl[step].word, s) <= 0; step ++) {
				if (strcmp (wl[step].word, s) == 0) {
					flag = 1;
					break;
				}
			}
			step ++;
			break;
		}

		/**/

		case 2: {
			int down = 0, up;
			int l = ind[0].n, m;
			up = down + l;

			while (up >= down) {
				m = (up + down)/2;
				step ++;

				if (strcmp (wl[m].word, s) == 0) {
					flag = 1;
					break;
				} else if (strcmp (wl[m].word, s) < 0) {
					down = m+1;

				} else {
					up = m-1;
				}
			}
			break;
		}
		/**/

		case 3: {
			int t = *s F;
			int down = ind[t].start, up;
			int l = ind[t].n - 1, m;
			up = down + l;

			while (up >= down) {
				m = (up + down)/2;
				step ++;

				if (strcmp (wl[m].word, s) == 0) {
					flag = 1;
					break;
				} else if (strcmp (wl[m].word, s) < 0) {
					down = m + 1;
				} else {
					up = m - 1;
				}
			}
			break;
		}

		/**/

		case 4: {
			int m = hash (s);
			struct H* t = &hb[m];
			while (t) {
				step ++;
				if (strcmp (t->word, s) == 0) {
					flag = 1;
				}
				t = t -> next;
			}
			break;
		}
		/**/
	}
	printf ("%d %d\n", flag, step);
	return ;
}

