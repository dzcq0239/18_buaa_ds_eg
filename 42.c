#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Bracket {
	char brac;
	int line;
	char f;
	struct Bracket* next;
} ele;
int isBrac (int B);

int main () {

	////读入；
	FILE *in = fopen ("example.c","r");
	ele *start = (ele*)malloc (sizeof (ele)), *end = start;
	char c, t;
	int l = 1, count = 0;
	while (~ (c = fgetc (in))) {
		//字符常量；
		if ((c == '\''))
			while ((c = fgetc (in)) != '\'');
		//字符串常量
		if ((c == '\"'))
			while ((c = fgetc (in)) != '\"');
		//注释(单行）
		if ((c == '/') && c == t)
			while (((c = fgetc (in)) != '\n'));
		//注释（多行）
		if ((t == '/') && (c == '*'))
			while (~ (c = fgetc (in))) {
				if ((t == '*') && (c == '/')) {
					break;
				}
				if ((c == '\n'))
					l ++;
				t = c;
			}
		//括号入栈
		if (isBrac (c)) {
			//printf ("%c",c);
			end -> brac = c;
			count ++;
			end -> line = l;
			end -> f = 1;
			end -> next = (ele*)malloc (sizeof (ele));
			end = end -> next;
		}
		//缓存，行数
		if ((c == '\n') )
			l ++;

		t = c;
	}
	fclose (in);
	end -> f = 0;
	end -> next = NULL;

	////匹配；
	ele *judge, *top, *ne, *be;
	while (count > 1) {
		//初始化
		//栈顶&&后续
		for (top = start; top != NULL; top = top -> next) {
			if (((top -> brac == '(') || (top -> brac == '{')) && top -> f)
				judge = top;
			if (((top -> brac == ')') || (top -> brac == '}')) && top -> f) {
				ne = top;
				break;
			}
		}
		//前序
		for (top = start, be = end; top != judge; top = top -> next) {
			if (((top -> brac == '(') || (top -> brac == '{')) && top -> f)
				be = top;
		}
		//报错
		if (judge -> brac == '{') {
			//前不匹配；
			if (be -> brac == '(') {
				printf ("without maching '%c' at line %d", be -> brac, be -> line);
				return 0;
			}
			//后不匹配；
			if (ne -> brac == ')') {
				printf ("without maching '%c' at line %d", ne -> brac, ne -> line);
				return 0;
			}
		}
		if (judge -> brac == '(') {
			//后不匹配；
			if (ne -> brac == '}') {
				printf ("without maching '%c' at line %d", ne -> brac, ne -> line);
				return 0;
			}
		}
		//匹配
		judge -> f = 0, ne -> f = 0;
		count -= 2;
	}

	////未匹配
	if (count) {
		for (top = start; top != NULL; top = top -> next)
			if (top -> f)
				printf ("without maching '%c' at line %d", top -> brac, top -> line);;

	} else
		//全匹配
		for (top = start; top != NULL; top = top -> next)
			printf ("%c",top -> brac);
	return 0;
}

int isBrac(int B) {
	if (B == '{' ||B == '}'||B == '(' ||B == ')')
		return 1;
	return 0;
}


