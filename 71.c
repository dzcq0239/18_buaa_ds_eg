#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
int map[109][109], isV[109], que[109];
//
void showMe(int);
//
void D(int);
void DFS(int, int);
//
void B(int);
void BFS(int, int);
int main() {
	//读入无向图
	int v, e;
	scanf ("%d%d", &v, &e);
	int i,j,k;
	for (k = 0; k < e; k ++) {
		scanf ("%d %d", &i, &j);
		map[i][j] = map[j][i] = 1;
	}
	//showMe (v);
	D(v);
	B(v);

	int d;
	scanf ("%d", &d);
	for (i = 0; i < v; i ++) {
		map[i][d] = 0;
		map[d][i] = 0;
	}
	//showMe(v);
	D(v);
	B(v);

	return 0;
}

void showMe(int v) {
	int i, j;
	for (i = 0; i < v; i ++) {
		for (j = 0; j < v; j ++)
			printf ("%d ", map[i][j]);
		printf ("\n");
	}
}

//
void D(int v) {
	//初始化
	int i, j;
	for (i = 0; i < v; i ++)
		isV[i] = 0;
	//遍历
	for (i = 0; i < v; i ++)
		for (j = 0; j < v ; j ++)
			if (map[i][j])
				if (~ isV[i]) {
					DFS(v, i);
					break;
				}
	printf ("\n");
	return;
}
void DFS (int v, int t) {
	//访问
	isV[t] = -1;
	printf ("%d ",t);
	//递归
	int i;
	for (i = 0; i < v; i ++) {
		if (map[t][i]) {
			if (~ isV[i]) {
				DFS(v, i);
			}
		}
	}
}
//
void B(int v) {
	//初始化
	int i, j;
	for (i = 0; i < v; i ++) {
		isV[i] = 0;
		que[i] = -1;
	}
	//遍历
	for (i = 0; i < v; i ++) {
		for (j = 0; j < v; j ++)
			if (map[i][j])
				if (~ isV[i]){
					BFS(v, i);
					break;
				}
	}
	printf ("\n");
	return;
}
void BFS(int v, int t) {
	int i, start = 0, end = -1;
	//访问
	printf ("%d ", t);
	isV[t] = -1;
	//进队
	que[++ end] = t;
	//出队
	while(start <= end) {
		t = que[start ++];
		for (i = 0; i < v; i ++) {
			if (map[t][i])
				if (~ isV[i]) {
					printf ("%d ", i);
					isV[i] = -1;
					que[++ end] = i;
				}
		}
	}
	return;
}

