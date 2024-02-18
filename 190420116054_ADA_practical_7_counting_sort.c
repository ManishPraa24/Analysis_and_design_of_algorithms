#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//Practical 7
//Implementation and Time analysis of Linear sorting algorithms: Counting sort


void counting_sort(int *a, int *b, int *c, int n, int k, int flag)
{
	int i, j, l;
	
	if(flag==0)
	{
		flag=1;
	}
	else{
		flag=0;
	}
	
	for(i=0; i<n; i++)
	{
		l=*(a+i);		
		*(c+l-flag)=*(c+l-flag)+1;
	}
	
	for(i=1; i<k; i++)
	{
		*(c+i)=(*(c+i) + *(c+i-1));
	}
	
	for(i=n-1; i>=0; i--)
	{
		l=*(a+i);
		j=*(c+l-flag);
		j=j-(1-flag);
		*(b+j-flag)=*(a+i);
		*(c+l-flag)=*(c+l-flag)-1;
	}
}

int main()
{
	int n, i, max;
	int *p, *b, *c;
	int flag=0;
	
	printf("This is COUNTING SORT.\n\n");
	
	printf("Enter the number of elements you want to enter: ");
	scanf("%d", &n);
	
	
	p = (int *) malloc((n)*(sizeof(int)));
	b = (int *) malloc((n)*(sizeof(int)));
	
	printf("Enter the terms: \n");
	for(i=0; i<n; i++)
	{
		again:
		scanf("%d", (p+i));
		if(*(p+i)<0)
		{
			printf("\nNegative Number is prohibited. Enter that number again.\n");
			goto again;
		}
		if(*(p+i)==0)
		{
			flag=1;
		}
		if(i==0)
		{
			max=*(p+i);
		}
		else{
			if(*(p+i)>max)
			{
				max=*(p+i);
			}
		}
	}
	
	if(flag!=0){
		max++;
		printf("\nThe key value is %d. There is/are atleast one '0' number.\n", max);
	}
	else{
		printf("\nThe key value is %d.\n", max);
	}
	
	c = (int *) malloc((max+3)*(sizeof(int)));
	for(i=0; i<max+3; i++)
	{
		*(c+i)=0;				
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
	
	counting_sort(p, b, c, n, max, flag);
	
	printf("\n\n");
	
	
	printf("The list AFTER sorting:\n");
	
	for(i=0; i<n; i++)
	{
		if(i==n-1)
		{
			printf("%d.", *(b+i));
		}
		else
		{
			printf("%d, ", *(b+i));
		}				
	}
	
	
	return 0;
	
}
