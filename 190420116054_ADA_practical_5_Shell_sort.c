#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//PRACTICAL 5
//Implementation and Time analysis of sorting algorithms: Shell sort
int count=0;

void insertion_sort(int *ptr, int start, int gap, int len)
{
	int i, j, k;
	
	for(i=start+gap; i<len; i=i+gap)
	{
		j=i-gap;
		while(j>=0)
		{
			count++;
			if(*(ptr+j+gap)<*(ptr+j))
			{
				k=*(ptr+j+gap);
				*(ptr+j+gap)=*(ptr+j);
				*(ptr+j)=k;
			}			
			j=j-gap;
		}
	}
	
}

int * shell_sort(int *ptr, int len)
{
	int gap, i, j;
	int *receive;
	
	gap=len/2;
	
	while(gap>0)
	{
		for(i=0; i<len-gap; i++)
		{
			insertion_sort(ptr,i, gap, len);
		}
		gap=gap/2;
	}
	
	return ptr;
	
}

int main()
{
	int n, i;
	int *p;
	
	printf("Enter the number of elements you want to enter: ");
	scanf("%d", &n);
	
	p = (int *) malloc(n*(sizeof(int)));
	
	printf("Enter the terms: \n");
	for(i=0; i<n; i++)
	{
		scanf("%d", p+i);
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
	
	p = shell_sort(p, n);
	
	printf("\n\n");
	printf("The time complexity of Shell sorting is O(n^2).\n\n");
	printf("According to given formula, theoritically, iterations are %d.\n\n", n*n);
	printf("Practically performing, the number of iterations taken are %d.\n\n", count);
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
