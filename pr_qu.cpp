#include<iostream>
using namespace std;

void buildHeap(int [],int);
void maxHeapify(int[], int,int);
void swap(int*, int*);

int main()
{
	int n;
	cin>>n;
	
	int a[n];
	for(int i=1;i<=n;i++)
		cin>>a[i];
		
	buildHeap(a,n);
	
	return(0);
}

void buildHeap(int a[],int n)
{
	for(int k=n/2;k>=1;k--)
		maxHeapify(a,k,n);
}

void heapSort(int a[], int n)
{
	for(int j=n;j>=2;j++)
	{
		swap(&a[1],&a[i]);
		maxHeapify(a,1,n);
	}
}


void maxHeapify(int a[],int i, int n)
{
	int l=2*i;
	int r=(2*i)+1;
	int largest;
	
	if(l<=n and a[l]>a[i])
		largest=l;
	else
		largest=i;
	if(r<=n and a[r]>a[largest])
		largest=r;
	if(largest!=i)
	{
		swap(&a[i],&a[largest]);
		maxHeapify(a,largest,n);
	}
}

void swap(int *a, int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
