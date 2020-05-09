#include<stdio.h>
#include<string.h>

char Err[9] = "error";

int main () {
	int stack[299], order, temp, cor = -1;
	
	while (~ scanf ("%d", &order)) {
		switch (order) {
			case 1 :
				scanf ("%d ", &temp);
				if (cor > 99)
					printf ("%s ", Err);

				else
					stack[++ cor] = temp;
				break;
			case 0 :
				if (cor < 0)
					printf ("%s ", Err);
				else
					printf ("%d ", stack[cor --]);
				break;
			case -1 :
				return 0;
				break;
		}
	}
}


