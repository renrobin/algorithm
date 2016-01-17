#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "common.h"

namespace ns_sort
{

static void swap(int* data, int i, int j)
{
	std::swap(data[i], data[j]);
}

static size_t sizePerInt(int n)
{
    return n * sizeof(int);
}

static int partion_1(int* data, int l, int u)
{
	if (l>=u) return l;
	int p=data[l];
	int i=l, j=u;
	while(i<j) {
		while(data[j]>p) --j;
		while(data[i]<=p) ++i;
		if (i<j) {
			swap(data, i, j);
		}
	}
	swap(data, l, j);
	return j;
}
void qs(int* data, int l, int u)
{
	if (l>=u) return;
	int m=partion_1(data, l, u);
	if (m>1) {
		qs(data, l, m-1);
	}
	if (m+1<u) {
		qs(data, m+1, u);
	}
}

static int partion_2(int a[], int left, int right, int pivotIndex)
{
	int p=a[pivotIndex];
	int m=left;
	swap(a, pivotIndex, right);
	for (int i=left; i<right; ++i) {
		if (a[i]<p) {
			swap(a, i, m);
			++m;
		}
	}
	swap(a, m, right);
	return m;
}

int select(int a[], int size, int k)
{
	if (k>size)
		return -1;

	int m = partion_2(a, 0, size-1, 0);
	if (k-1==m)
		return m;
	else if (k-1<m)//select in small part
		return select(a, m, k);
	else //select in large part
		return m+1+select(a+m+1, size-(m+1), k-(m+1));
}

void mergeSort(int a[], int n)
{
    if (n == 1)
        return;
        
    if (n == 2)
    {
        if (a[0] > a[1])
            std::swap(a[0], a[1]);
        return;
    }

    //divide,conquer
    int m = n/2;
    int lSize = m;
    int* lPart = (int*)malloc(sizePerInt(lSize));
    memcpy(lPart, a, sizePerInt(lSize));
    mergeSort(lPart, lSize);

    int rSize = n - m;
    int* rPart = (int*)malloc(sizePerInt(rSize));
    memcpy(rPart, &a[m], sizePerInt(rSize));
    mergeSort(rPart, rSize);

    //merge
    int i=0, j=0, k=0;
    while (i<lSize && j<rSize)
    {
        if (lPart[i]<rPart[j])
            a[k++] = lPart[i++];
        else
            a[k++] = rPart[j++];
    }

    if (i < j)
        memcpy(&a[k], &lPart[i], sizePerInt(lSize - i));
    else
        memcpy(&a[k], &rPart[j], sizePerInt(rSize - j));

    free(lPart);
    free(rPart);
}

void testQsort()
{
//	int data[] = {};
//	int data[]={1};
//int data[] = {1,2};
	int data[] = {2,1};
//	int data[] = {1,1,1,1,1};
//	int data[] = {0,1,5,8,2,0};
//	int data[] = {1,0,5,8,2,0};
//int data[] = {6,1,2,7,9,3,4,5,10,8};
//int data[] = {6,1,2,7,9,11,4,5,10,8};
	printArray(data, ARRAY_SIZE(data));
	qs(data, 0, ARRAY_SIZE(data)-1);
//	int m = partion(data, 0, ARRAY_SIZE(data)-1);
//	cout<<m<<"\n";
	printArray(data, ARRAY_SIZE(data));
}

void testSelect()
{
	int data[] = {6,1,2,7,9,11,4,5,10,8};
	int m = select(data, ARRAY_SIZE(data), 10);
	cout<<data[m]<<"\n";
}

}