#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

//Practical 15: Merge Sort
//Pointer version

void merge_it(int *arr, int p, int q, int r)
{
	int n1, n2, i, j, *l, *ri, k;
	n1=q-p+1;
	n2=r-q;
	
	l=(int *)malloc((n1+2)*sizeof(int));
	ri=(int *)malloc((n2+2)*sizeof(int));
	
	for(i=1; i<=n1; i++)
	{
		*(l+i)=*(arr+p+i-1);
	}
	
	for(j=1; j<=n2; j++)
	{
		*(ri+j)=*(arr+q+j);
	}
	
	*(l+n1+1)=32867;
	*(ri+n2+1)=32867;
	
	i=1; j=1;
	
	for(k=p; k<=r; k++)
	{
		if(*(l+i)<=*(ri+j))
		{
			*(arr+k)=*(l+i);
			i++;
		}
		else
		{
			*(arr+k)=*(ri+j);
			j++;
		}
	}
	
}

void merge_sort(int *arr, int p, int r)
{
	int q;
	if(p<r)
	{
		q=(p+r)/2;
		merge_sort(arr, p, q);
		merge_sort(arr, q+1, r);
		merge_it(arr, p, q, r);
	}
}

int main()
{
	int *arr, n, i, j;
	printf("This is MERGE SORT.\n\n");
	printf("Enter 'n' the number of terms you want to enter: ");
	again1:
	scanf("%d",&n);
	if(n<=0)
	{
		printf("Enter a natural number. Please enter 'n' again: ");
		goto again1;
	}
	
	arr=(int *)malloc((n+1)*sizeof(int));
	
	printf("\nStart entering the numbers: \n");
	for(i=1; i<=n; i++)
	{
		scanf("%d", arr+i);
	}
	
	printf("\nBefore sorting the array: \n");
	for(i=1; i<=n; i++)
	{
		if(i==n)
		{
			printf("%d.", *(arr+i));
		}
		else{
			printf("%d, ", *(arr+i));
		}
	}
	
	merge_sort(arr, 1, n);
	
	printf("\n\nAfter sorting the array: \n");
	for(i=1; i<=n; i++)
	{
		if(i==n)
		{
			printf("%d.", *(arr+i));
		}
		else{
			printf("%d, ", *(arr+i));
		}
	}
	
	return 0;
	
}
