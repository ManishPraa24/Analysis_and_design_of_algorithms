#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//PRACTICAL 13
//Floyd's Algorithm (All pair shortest path)
//190420116054

int min(int a, int b)
{
	if(a<b)
		return a;
	else
		return b;
}

void floyd_short_it(int **d, int n)
{
	int i, k, j;
	
	for(k=0; k<n; k++)
	{
		for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				if(i==j)
				{
					continue;
				}
				else{
					if((*(*(d+i)+k) + *(*(d+k)+j))!=0 && *(*(d+i)+j)==0 && *(*(d+k)+j)!=0 && *(*(d+i)+k)!=0)
					{
						*(*(d+i)+j)=*(*(d+i)+k) + *(*(d+k)+j);
					}
					else if(*(*(d+i)+j)!=0 && *(*(d+i)+k)!=0 && *(*(d+k)+j)!=0)
					{
						*(*(d+i)+j)=min(*(*(d+i)+j), *(*(d+i)+k) + *(*(d+k)+j));
					}
				}
			}
		}
	}
	
}

int main()
{
	int **d, i, j, n;
	printf("This is FLOYD ALGORITHM.\n\n");
	printf("Enter the no. of nodes you want: ");
	again1:
		scanf("%d", &n);
		if(n<=0)
		{
			printf("Enter a natural number. Please enter it again: ");
			goto again1;
		}
	
	d=(int **)malloc(n*sizeof(int *));
	for(i=0; i<n; i++)
	{
		*(d+i)=(int *)malloc(n*(sizeof(int)));
	}
	
	printf("\nStart entering the value of edges:\n\nNOTE:- Enter '0' if there's no edge of particular direction or not present at all.\n\n");
	
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			if(i==j)
			{
				*(*(d+i)+j)=0;
				continue;
			}
			printf("Value of edge from %d to %d: ", i+1, j+1);
			again2:
				scanf("%d", &*(*(d+i)+j));
				if(*(*(d+i)+j)<0)
				{
					printf("Please enter a whole number. Enter the value again: ");
					goto again2;
				}
		}
	}
	
	printf("\nThe matrix is looking like this:\n");
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			printf("%3d", *(*(d+i)+j));
		}
		printf("\n");
	}
	
	floyd_short_it(d, n);
	
	printf("\nAfter applying Floyd alogorithm, the matrix looks like this:\n");
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			printf("%3d", *(*(d+i)+j));
		}
		printf("\n");
	}
	
	return 0;
}
