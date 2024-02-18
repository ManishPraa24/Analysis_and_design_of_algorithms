#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//PRACTICAL 4
//Implementation and Time analysis of sorting algorithms: Insertion sort
int count=0;

int * insertion_sort(int *ptr, int len)
{
	int i, j, k;
	
	for(i=1; i<len; i++)
	{
		j=i-1;
		while(j>=0)
		{
			count++;
			if(*(ptr+j+1)<*(ptr+j))
			{
				k=*(ptr+j+1);
				*(ptr+j+1)=*(ptr+j);
				*(ptr+j)=k;
			}			
			j--;
		}
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
	
	p = insertion_sort(p, n);
	
	printf("\n\n");
	printf("The time complexity of Insertion sorting is O(n^2).\n\n");
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
