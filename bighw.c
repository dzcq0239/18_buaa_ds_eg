#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//
typedef struct B {
	char word[59];
	struct B* next;
	struct B* end;
} b;
b book[666666];

//
typedef struct N {
	char word[59];
	struct N* next;
	struct P* link;
	struct N* end;
} n;
n note[666666], tem, aaa[55555];

typedef struct P {
	int pos;
	struct P *next;
} p;
int list[666666], mulu[55555], isV[666666];
int po, mu;
inline unsigned int hash(char*);
void save(char*);
void read(char*);
void showMe(void);
int cmp (const void*,const void*);
int main() {
	char word[59] = {},b, c;
	int i;
	i = 0;

	//´æ´¢´Êµä
	FILE *dic = fopen ("dictionary.txt", "r");
	while (~ (fscanf (dic, "%s", word))) {
		save(word);
	}

	//¶ÁÎÄÕÂ
	FILE *in = fopen ("article.txt", "r");
	while (~ b) {
		(c = fgetc (in));
		if (isalpha (c)) {
			word[i ++] = tolower (c);
		} else {
			word[i] = 0;
			i = 0;
			if (*word) {
				read(word);
				po += strlen (word);
			}
			po ++;
		}
		b = c;
	}

	//¶ÁÊ÷
	showMe();
	return 0;
}

unsigned int hash(char *word) {
	unsigned int z = 0;
	char *p;
	for (p = word; *p; p ++)
		z = (z * 23 + *p) ;
	return z %  666666;
}
void save(char *word) {
	int h = hash(word);
	/*
	if (! *(book[h].word)) {
		strcpy (book[h].word, word);
	} else {
		b* t;
		for (t = &book[h]; t -> next; t = t -> next);
		t -> next = malloc (sizeof (b));
		t = t -> next;
		t -> next = 0;
		strcpy (t -> word, word);
	}
	*/
	if ((book[h].end) == NULL) {
		strcpy (book[h].word, word);
		book[h].end = &book[h];
	} else {
		
		b* t = book[h].end;
		//for (t = &book[h]; t -> next; t = t -> next);
		t -> next = malloc (sizeof (b));
		t = t -> next;
		t -> end =  t -> next = 0;
		strcpy (t -> word, word);
		book[h].end = t;
		
	}
	return ;
}

void read(char *word) {
	int h = hash (word);
	b* tb;
	for (tb = &book[h]; tb ; tb = tb -> next) {
		if (strcmp (tb -> word, word) == 0)
			break;
	}
	if (tb == NULL) {
		mulu[mu ++] = h;
		isV[h] ++;
		//Î´Æ¥Åä
		n* tn = &note[h];
		if (strlen (tn -> word) == 0) {
			strcpy (tn -> word, word);
			tn -> link = malloc (sizeof(p));
			tn -> link -> pos = 0;
			tn -> link -> next = 0;
		} else {
			n* pn = tn;
			for (; pn; pn = pn -> next) {
				if (strcmp (pn -> word, word) == 0)
					break;
			}
			if (pn) {
				tn = pn;
			} else {
				for(; tn -> next; tn = tn -> next);
				tn -> next = malloc(sizeof (n));
				tn = tn -> next;
				tn -> next = 0;
				strcpy (tn -> word, word);
				tn -> link = malloc (sizeof(p));
				tn -> link -> pos = 0;
				tn -> link -> next = 0;
			}
		}
		p* tp = tn -> link;
		tp -> pos ++;
		for (; tp -> next; tp = tp -> next);
		tp -> next = malloc (sizeof (p));
		tp = tp -> next, tp -> next = 0;
		tp -> pos = po;

		list[h] ++;
	}
	return;
}

void showMe(void) {
	po = 0;
	FILE *out = fopen ("misspelling.txt","w");
	n* np ;
	p* pp;

	int i, j = 0, k;
	for (i = 0; i < mu; i ++) {
		j = mulu[i];
		k = isV[j];
		if (k) {
			isV[j] = 0;
			for (np = &note[j]; np; np = np -> next) {
				aaa[po ++] = *np;
			}
		}
	}

	qsort (aaa, po, sizeof (n), cmp);


	int z;
	for (z = 0; z < po; z ++) {
		fprintf (out , "%s %d", aaa[z].word, aaa[z].link -> pos);

		printf ("%s %d", aaa[z].word, aaa[z].link -> pos);

		for (pp = aaa[z].link -> next; pp; pp = pp -> next) {
			printf (" %d", pp -> pos);
			fprintf (out, " %d", pp -> pos);
		}
		printf ("\n");
		fprintf (out, "\n");
	}
	return;
}

int cmp (const void *p1, const void *p2) {
	n *c1 = (n *)p1, *c2= (n *)p2;
	if (c1 -> link -> pos == c2 -> link -> pos)
		return strcmp (c1 -> word, c2 -> word);
	else
		return  (c2 -> link -> pos) - (c1 -> link -> pos);
}





