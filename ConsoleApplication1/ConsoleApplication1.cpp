// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include<stdlib.h>
int part(int a[], int first, int last)
	{
	int temp;
	while (first<last)
		{
		while (first<last&&a[first]<=a[last])
			last--;
		if (first < last) {
			temp = a[first];
			a[first] = a[last];
			a[last] = temp;
			first++;
			}
		while (first < last&&a[first] <= a[last])
			first++;
		if (first < last) {
			temp = a[first];
			a[first] = a[last];
			a[last] = temp;
			last--;
			}
		}
	return first;
	}
void quicksort(int a[], int i,int j)
	{
	int pivot;
	if (i < j) {
		pivot = part(a, i, j);
		quicksort(a, i, pivot - 1);
		quicksort(a, pivot + 1, j);
		}
	}
void BinaryInsertSort(int a[], int left, int right) {
	int low, middle, high;
	int temp;
	for (int i = left + 1; i <= right; i++) {
		temp = a[i];
		low = left;
		high = i - 1;
		while (low <= high) {
			middle = (low + high) / 2;
			if (a[i] < a[middle])
				high = middle - 1;
			else
				low = middle + 1;
			}

		for (int j = i - 1; j >= low; j--)
			a[j + 1] = a[j];

		a[low] = temp;
		}
	}

int main()
{
	int a[10];
	int i;
	for (i = 0;i <=9;i++)
		{
		scanf("%d ", &a[i]);
		}
	for (i=0;i<=9;i++)
	printf("%d ", a[i]);
	printf("\n");
	quicksort(a, 0,9);
	for (i = 0;i <= 9;i++)
		printf("%d ", a[i]);
	printf("\n");
	BinaryInsertSort(a, 0, 9);
	for (i = 0;i <= 9;i++)
		printf("%d ", a[i]);
	system("pause");
    return 0;
}

