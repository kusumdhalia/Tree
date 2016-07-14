#include<iostream>
using namespace std;


heap* createheap(int);
void swap(int*,int*);
void buildheap(heap*,int [],int);
void minHeapify(int[],int,int);

struct heap
{
	int count,
	int cap;		//capacity
	int *a;
};

heap* createheap(int capacity)
{
	heap* h=(minheap*)malloc(sizeof(heap));
	if(h==NULL)
	{
		printf("Memory error");
		return;
	}
	h->capacity=capacity;
	h->count=0;
	h->array=(int*)malloc(sizeof(int)*h->capacity);
	if(h->array==NULL)
	{
		printf("Memory error");
		return;
	}
	return h;
}

oid resizeheap(heap*h)
{
	int *arr_old,i;
	arr_old=h->array;

	h->array=(int*)malloc(sizeof(int)*2*h->capacity);
	if(h==NULL)
	{
	printf("memory error");
	return;
	}
	for(i=0;i<h->capacity;i++)
	h->array[i]=arr_old[i];

	h->capacity=2*h->capacity;
	free(arr_old);
}


void buildheap(heap* h,int a[],int k)
{
	if(h==NULL)
	return;
	if(k>h->capacity)
	resizeheap(h);

	int i;
	for(i=0;i<k;i++)
	h->array[i]=a[i];

	h->count=k;

	for(i=(k-1)/2;i>=0;i--)
	minHeapify(h,i);
}

void minHeapify (int Arr[], int i, int N)
{
    int left = 2*i;                  //left child
    int right = 2*i +1; 				//right child
	int small;          
    if(left<= N and Arr[left] < Arr[i] )
          small = left;
    else
         small = i;
    if(right <= N and Arr[right] < Arr[small] )
        small = right;
    if(small != i )
    {
        swap (&Arr[i] , &Arr[small]);
        maxHeapify (Arr, small,N);
    } 
 }



int main()
{
	int n;
	cin>>n; //capacity of heap

	int array[n];
	for (int i = 1; i < =n; ++i)
		cin>>array[i];


	return(0);
}

void swap(int* a,int *b)
{
	int temp= *a;
	*a=*b;
	*b=temp;
}