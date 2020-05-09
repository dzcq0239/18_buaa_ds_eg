#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define MAX 360
#define SUP 256
#define LIN 88
//
struct hAshbOok {
	char name[99];
	int next;
} HB[MAX];
struct sImplIfymAp {
	char name[99];
	struct sImplIfymAp* next;
} *SM[MAX][MAX];

//
int hash (char*, int), ctoh (char*);
char *htoc (int);
void Ini(void), Fy(int),draw(void), On(void), sEa(int, int, int);
//
char from[99], to[99], pAt[2][MAX][99];
int L, Inl[LIN][MAX][MAX], sym[2][MAX][LIN], swl[2][MAX], isV[LIN], dIs, mIn, Ans[LIN],bUf, skIp;
int main() {
	Ini();
	FILE *in = fopen ("bgstations.txt", "r");
	char station[99], last[99];
	int ex, now, num, count;
	fscanf (in, "%d", &L);

	while (~ (fscanf (in, "%s  %d",station, &ex))) {
		if (atoi (station)) {
			count = 0, now = atoi (station), num = ex;
			//printf ("*****************************Line : %d \tTotal : %d\n", now, num);
		} else {
			int i = ctoh (last), j = ctoh(station);
			//printf ("Sta:%20s HASH:%d\n", station, ctoh(station));
			//printf ("%d\t", count);
			if (count) {
				//printf ("%20s ->  %20s\t(%d,%d)", htoc(i), htoc(j), i, j);
				Inl[now][i][j] = Inl[now][j][i] = 1;
			}
			//printf ("\n");
			if (count == num -1) {
				Fy(now);
				//system ("pause");
			}
			if (ex) {
				sym[1][j][now] = 1;
			}
			sym[0][j][now] = 1;
			count ++;
			strcpy (last, station);
		}
	}
	draw();
	//scanf ("%s%s", from, to);
	while (~(scanf ("%s%s", from, to)))
		On();
	/**/
	return 0;
}
//
void Ini(void) {
	int i,j,k;
	for (k = 0; k < LIN; k ++) {
		for (j = 0; j < MAX; j ++) {
			for(i = 0; i < MAX; i ++)
				Inl[k][i][j] = MAX;
		}
	}
	HB[0].next = SUP;
	strcpy (HB[0].name, "NULL");
	//mIn = 239;
}
int hash (char *s, int m) {
	unsigned int h = 0, a, se = 7,i;
	char *p;
	for (p = s; *p; p ++)
		h = h*se + *p;
	h = h % SUP + 1;
	if (m) {
		if (strlen (HB[h].name)) {
			for (a = h; HB[a].next; a = HB[a].next);
			h = ++ HB[0].next;
			HB[a].next = h;
			strcpy (HB[h].name, s);
			return h;
		} else {
			strcpy (HB[h].name, s);
			return h;
		}
	}
	for (; strcmp (HB[h].name, s) && h; h = HB[h].next);
	//printf ("Finded: %20s::%d\n",HB[h].name, h);
	return h;
}
int ctoh (char *s) {
	return hash (s, 0) ? hash (s, 0) : hash(s, 1);
}
char *htoc (int h) {
	//printf("*****%s\n", HB[h].name);
	return HB[h].name;
}
void Fy(int l) {
	int i , j , k;
	for (k = 0; k < MAX; k ++) {
		for (i = 0; i < MAX; i ++) {
			for (j = 0; j < MAX; j ++) {
				if (i == j) {
					Inl[l][i][j] = 0;
				} else if ((Inl[l][i][k] + Inl[l][k][j] < Inl[l][i][j])) {
					Inl[l][i][j] = Inl[l][i][k] + Inl[l][k][j];
					//printf ("%20s \t-> %20s \tDis:%d\n", htoc(i), htoc(j), Inl[l][i][j]);
				}
			}
		}
	}
}
void draw () {
	int k,i,j;
	for (k = 0; k < MAX; k ++) {
		for (i = 0; i < LIN; i ++) {
			if (sym[1][k][i])
				for (j = 0; j < LIN; j ++)
					if ((i != j) && (sym[1][k][j])) {
						if (SM[i][j]) {
							struct sImplIfymAp* p;
							for (p = SM[i][j]; p -> next; p = p -> next);
							p -> next = malloc(sizeof (struct sImplIfymAp));
							p = p -> next;
							p -> next = NULL;
							strcpy (p -> name, htoc(k));
						} else {
							SM[i][j] = malloc(sizeof (struct sImplIfymAp));
							SM[i][j]->next = NULL;
							strcpy (SM[i][j]->name, htoc(k));
						}
						//printf ("%20s (%d,%d)\n",htoc(k),i,j);
					}
		}
	}
	/*
	for (i = 0; i < LIN; i ++)
		for (j = i + 1; j < LIN; j ++)
			if (SM[i][j]) {
				printf ("(%d,%d)\t",i,j);
				struct sImplIfymAp* p = SM[i][j];
				while (p) {
					printf ("%20s  ", p->name);
					p = p -> next;
				}
				printf ("\n");
			}
	*/
}
void On(void) {
	int f = ctoh(from), t = ctoh(to),i,j,k;
	bUf = mIn = MAX;
	for (i = 0; i < MAX; i ++)
		swl[0][i] = swl[1][i] = pAt[0][i][0] = pAt[1][i][0] = 0;
	for (i = 0; i < LIN; i ++)
		isV[i] = 0;
	if (f != t) {
		for (i = 0; i < LIN; i ++)
			if (sym[0][f][i])
				for (j = 0; j < LIN; j ++)
					if ((sym[0][t][j])) {
						//printf ("%d-------------->%d\n",i,j);
						sEa(i,j,0);
					}

		int x = ctoh (from), y, l;
		printf ("%s",from);
		for (i = 0; swl[0][i]; i ++) {
			l = swl[0][i];
			y = x;
			x = strlen(pAt[0][i]) ? ctoh (pAt[0][i]) : ctoh(to);
			printf ("-%d(%d)-%s", l, Inl[l][y][x], pAt[0][i]);
			//swl[0][i] = pAt[0][i][0] = 0;
		}
		//swl[0][i] = pAt[0][i][0],
		printf ("%s\n",to);
	} else {
		for (i = 0; i < LIN; i ++) {
			if (sym[0][f][i]) {
				printf ("%s-%d(0)-%s", from,i, from);
				return;
			}
		}
	}
	return;
}
void sEa(int F, int T, int d) {
	int i,j;

	swl[1][d] = F;
	isV[F] = 1;

	if ((d == 0) && (F == T)) {
		isV[F] = 0;
	}
	if (d >= 6)
		return;
	for (i = 0; i < MAX; i ++) {
		if (SM[F][i]) {
			struct sImplIfymAp* p = SM[F][i];
			while (p) {
				if (! isV[i]) {
					strcpy (pAt[1][d], p->name);
					sEa(i,T,d+1);
					swl[1][d+1] = 0;
					isV[i] = 0;
					pAt[1][d][0] = 0;
				}
				p = p->next;
			}
		}
	}
	if (F == T) {
		int x = ctoh (from), y, l;

		skIp = dIs = 0;
		//printf ("%s",from);
		for (i = 0; swl[1][i]; i ++) {
			l = swl[1][i];
			y = x;
			x = strlen(pAt[1][i]) ? ctoh (pAt[1][i]) : ctoh(to);
			dIs += Inl[l][y][x];
			skIp ++;
			//strcpy (pAt[0][i],pAt[1][i]);
			//printf ("-%d(%d)-%s", l, Inl[l][y][x], pAt[1][i]);
			if (dIs > mIn) {
				//printf ("XXXXXXXXXXXXXXXXXX\n");
				return;
			}
		}
		if ((dIs == mIn) && (skIp > bUf))
			return;

		bUf = skIp;
		//printf ("%s\n",to);
		mIn = dIs;
		//printf ("SAVESAVESAVESAVE\n%s",from);
		for (i = 0; swl[1][i]; i ++) {
			l = swl[0][i] = swl[1][i];
			strcpy (pAt[0][i],pAt[1][i]);
			swl[0][i+1] = 0;
			pAt[0][i+1][0] = 0;
			//swl[1][i+1] = 0;
			//printf ("-%d(%d)-%s", l, Inl[l][y][x], pAt[0][i]);
		}
		//printf ("%s\nSAVESAVESAVESAVE\n\n",to);
		return;
	}
	return;
}

