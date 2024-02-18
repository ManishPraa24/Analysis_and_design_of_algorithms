#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//PRACTICAL 6
//Implementation and Time analysis of sorting algorithms: Heap sort
int size=0, length=0;

int left(int i)
{
	return (2*i);
}

int right(int i)
{
	return (2*i)+1;
}

void swap(int *ptr, int l, int i)
{
	int copy;
	copy=*(ptr+i);
	*(ptr+i)=*(ptr+l);
	*(ptr+l)=copy;
	
}

void heapify(int *a, int i)
{
	int l=left(i);
	int r=right(i);
	int largest=0;
	
	if(l<=size && (*(a+l)>*(a+i)))
	{
		largest=l;
	}
	else
	{
		largest=i;
	}
	
	if(r<=size && (*(a+r)>*(a+largest)))
	{
		largest=r;
	}
	
	if(largest!=i)
	{
		swap(a, largest, i);
		heapify(a, largest);
	}
	
	
}

void build_heap(int *b)
{
	int i=0;
	
	for(i=size/2; i>=0; i--)
	{
		heapify(b, i);
	}
}

void heap_sort(int *a)
{
	build_heap(a);
	
	int i;
	for(i=size; i>=1; i--)
	{
		swap(a, 0, i);
		size--;
		heapify(a, 0);
	}
}

int main()
{
	int n, i;
	int *p;
	
	printf("This is HEAP SORT.\n\n");
	
	printf("Enter the number of elements you want to enter: ");
	scanf("%d", &n);
	size=n;
	length=n;
	
	p = (int *) malloc(n*(sizeof(int)));
	
	printf("Enter the terms: \n");
	for(i=0; i<n; i++)
	{
		scanf("%d", (p+i));
	}
	printf("\n");
	
	printf("The list before sorting:\n");
	
	for(i=0; i<n; i++)
	{
		if(i==n-1)
		{
			printf("%d.", *(p+i));
		}
		else
		{
			printf("%d, ", *(p+i));
		}				
	}
	
	heap_sort(p);
	
	printf("\n\n");
	//printf("The time complexity of Shell sorting is O(n^2).\n\n");
	//printf("According to given formula, theoritically, iterations are %d.\n\n", n*n);
	
	printf("The list AFTER sorting:\n");
	
	for(i=0; i<n; i++)
	{
		if(i==n-1)
		{
			printf("%d.", *(p+i));
		}
		else
		{
			printf("%d, ", *(p+i));
		}				
	}
	
	
	return 0;
}
