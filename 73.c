#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#define MAX 666666
//
struct E {
	int no;
	int co[2];
	int wg;
} edge[MAX], sw;
typedef struct P {
	int e;
	struct P* next;
} po;
struct PC {
	int count;
	po *next;
} p[MAX];
//
void bubbS(void);
//
void ST(void);
void Pro(void);
//
int v,e, stack[MAX][2], poi[MAX], ans[MAX], W;
int main() {
	//读入数据
	scanf ("%d%d", &v, &e);
	int i;
	for (i = 0; i < e; i ++) {
		scanf ("%d%d%d%d", &edge[i].no, &edge[i].co[0], &edge[i].co[1], &edge[i].wg);
	}
	//冒泡排序
	bubbS();
	//shoW();
	ST();
	//排序输出
	Pro();
	return 0;
}
void bubbS() {
	int i, j, f = 1;
	for (i = e - 1; f && (i >= 0); i --) {
		f = 0;
		for (j = 0; j < i; j ++) {
			if (edge[j].wg > edge[j+1].wg) {
				sw = edge[j];
				edge[j] = edge[j+1];
				edge[j + 1] = sw;
				f = 1;
			}
		}
	}
	return ;
}

//
void ST(void) {
	int i, j, x, y, o, f, count, end,z;
	//栈初始化
	for (i = 0; i <= v; i ++) {
		stack[i][1] = stack[i][0] = -1;
	}
	//贪心
	for (i = 0, end = -1; end < v - 2; i ++) {
		f = 1;
		count = 0;
		for (z = 0; z < v; z ++) {
			poi[z] = 0;
		}

		//入栈
		stack[++ end][0] = i;
		//生成图
		for (j = 0; j <= end; j ++) {
			o = stack[j][0];
			x = edge[o].co[0];
			y = edge[o].co[1];
			poi[x] ++, poi[y] ++;
			stack[j][1] = -1;
			count ++;
		}
		//删除边
		while (f) {
			f = 0;
			for (j = 0; j <= end; j ++) {
				o = stack[j][0];
				x = edge[o].co[0];
				y = edge[o].co[1];
				if (stack[j][1]) {
					if ((poi[x] == 1) || (poi[y] == 1)) {
						stack[j][1] = 0;
						poi[x] --;
						poi[y] --;
						count --;
						f = 1;
						break;
					}
				}
			}
		}
		//有环出栈
		if (count) {
			stack[end][0] = -1;
			end --;
		}
	}
	return;
}
void Pro(void) {
	int i = 0,j = -1, o, f = 1;
	for (i = 0; i < v - 1; i ++) {
		o = stack[i][0];
		ans[++ j] = edge[o].no;
		W += edge[o].wg;
	}
	for (i = v - 2; f && (i >= 0) ; i --) {
		f =0;
		for (j = 0; j < i; j ++ ) {
			if (ans[j] > ans[j + 1]) {
				int swi = ans[j];
				ans[j] = ans[j + 1];
				ans[j + 1] = swi;
				f = 1;
			}
		}
	}
	printf ("%d\n", W);
	for (i = 0; i < v - 1; i ++) {
		printf ("%d ", ans[i]);
	}
}

