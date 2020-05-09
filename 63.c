#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
int a[109], A;

void sM(int);
//
void bubbSort(int*, int);
//
void heapSort(int*,int);
void adJ(int*,int,int);
//
void mergeSort(int k[ ],int n);
void mSort(int k[], int tmp[], int left, int right);
void merge(int x[ ],int tmp[ ],int left,int leftend,int rightend);
//
void quickSort(int k[],int n);
void qSort(int v[ ],int left, int right);
void swap(int v[ ],int i, int j) ;




int main() {
	int i, n, m;
	scanf ("%d%d", &n, &m);
	for (i = 0; i <n ; i ++) {
		scanf ("%d", &a[i]);
	}
	//sM(n);
	switch (m) {
		case 1: {
			//Íµ¼¦
			heapSort(a,n);
			A = n*(n - 1)/2;
			break;
		}
		case 2: {
			bubbSort(a,n);
			break;
		}
		case 3: {
			heapSort(a,n);
			break;
		}
		case 4: {
			mergeSort(a,n);
			break;
		}
		case 5: {
			quickSort(a,n);
			break;
		}
		default:
			break;
	}

	sM(n);
	return 0;
}


void sM(int n) {
	int i;
	for (i = 0; i < n; i ++)
		printf ("%d ", a[i]);
	printf ("\n%d", A);
	printf ("\n\n");
}
//
void bubbSort (int k[], int n) {
	int i,j,flag = 1,m = n;
	for (i = 0; flag && (i < n - 1); i ++, m --) {
		flag = 0;
		for (j = 0; j < m -1; j ++) {
			if ((++ A) && (k[j] > k[j + 1])) {
				int t = k[j + 1];
				k [j + 1] = k [j];
				k [j] = t;
				flag = 1;
			}
		}
	}
	return;
}
//
void heapSort (int k[ ], int n) {
	int i, temp;
	for(i = n / 2 - 1; i >= 0; i --)
		adJ (k, i, n);
	for(i = n - 1; i >= 1; i --) {
		temp = k[i];
		k[i] = k[0];
		k[0] = temp;
		adJ (k, 0, i);
	}
}
void adJ (int k[ ],int i,int n) {
	int j,temp;
	temp = k[i];
	j = 2*i+1;
	while (j<n) {
		if (j<n-1 && k[j]<k[j+1])
			j++;
		if ((++ A) && (temp >= k[j]))
			break;
		k[(j-1)/2] = k[j];
		j = 2*j + 1;
	}
	k[(j-1)/2] = temp;
}

//
void mergeSort (int k[ ],int n) {
	int *tmp;
	tmp = (int *)malloc(sizeof (int)*n);
	if (tmp != NULL) {
		mSort (k, tmp, 0, n-1);
		free (tmp);
	}
}
void mSort (int k[], int tmp[], int left, int right) {
	int center;
	if (left < right) {
		center = (left+right)/2;
		mSort (k, tmp, left, center);
		mSort (k, tmp, center + 1, right);
		merge (k, tmp, left,center, right);
	}
}
void merge (int x[ ],int tmp[ ],int left,int leftend,int rightend) {
	int i = left, j = leftend+1, q = left;
	while (i<=leftend && j<=rightend)
		if ((++ A) && (x[i]<=x[j]))
			tmp[q++]=x[i++];
		else
			tmp[q++]=x[j++];
	while (i<=leftend)
		tmp[q++]=x[i++];
	while (j<=rightend)
		tmp[q++]=x[j++];

	for (i=left; i<=rightend; i++)
		x[i]=tmp[i];
}

//
void quickSort (int k[],int n) {
	qSort (k,0,n - 1);
}
void qSort(int k[ ],int left,int right) {
	int i, last;
	if(left<right) {
		last=left;
		for(i=left+1; i<=right; i++)
			if((++A) && (k[i]<k[left]))
				swap(k,  ++last, i);
		swap(k, left, last);
		qSort(k,left,last-1);
		qSort(k,last+1,right);
	}
}
void swap (int v[ ],int i, int j) {
	int tmp;
	tmp = v[i];
	v[i] = v[j];
	v[j] = tmp;
}

