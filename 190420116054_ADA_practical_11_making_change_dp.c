#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


//PRACTICAL 11
//Making Change Program using Dynamic Programming Technique: Pointer Version
//190420116054

void initialize_c(int **c, int n)     //Initializing the value of no. of coins to 0 for N=0
{
	int i;
	for(i=0; i<n; i++)
	{
		*(*(c+i)+0)=0;
	}
}

int min(int a, int b)      //Returning the minimum of 2 number
{
	if(a>b) return b;
	else return a;
}

void make_me_changes(int **c, int *d, int n, int N)      //Main function calculating the making changes
{
	int i, j;
	printf("\nNOTE: Any value being '-1' indicates infinity.\n\n");
	
	for(i=0; i<n; i++)                                         //Now, the main algorithm is running
	{
		for(j=1; j<N; j++)
		{
			if(i==0 && j<*(d+i))                             //Several conditions being checked
			{
				*(*(c+i)+j)=-1;
			}
			else if(i==0)
			{
				*(*(c+i)+j)=1+*(*(c+i)+(j-*(d+i)));
			}
			else if(j<*(d+i))
			{
				*(*(c+i)+j)=*(*(c+i-1)+j);
			}
			else{
				*(*(c+i)+j)=min(*(*(c+i-1)+j), 1+*(*(c+i)+(j-*(d+i))) );
			}
		}
	}                                                              
	
}														//End of 'making change' function

int main()
{
	int **c, *d, n, N, i, j;
	
	printf("This is MAKING CHANGE PROGRAM USING DYNAMIC PROGRAMMING TECHNIQUE.\n\n");
	printf("Enter the number of coins: ");
	again1:
	scanf("%d", &n);                                                                     //Taking values from user till down the line
	if(n<=0)
	{
		printf("\nPlease enter a natural number. Enter again: ");
		goto again1;
	}
	
	d=(int *)malloc(n*sizeof(int));
	
	printf("\nEnter the values of coin(in ascending order):\n");
	for(i=0; i<n; i++)
	{
		printf("Enter value for coin%d: ",  i+1);
		again2:
		scanf("%d", d+i);
		if(*(d+i)<=0)
		{
			printf("\nPlease enter a natural number. Enter again: ");
			goto again2;
		}
	}
	
	printf("\nEnter the value of 'N' for making changes of coins: ");
	again3:
	scanf("%d", &N);
	if(N<=0)
	{
		printf("\nPlease enter a natural number. Enter again: ");
		goto again3;
	}
	
	c=(int **)malloc(n*sizeof(int *));                                       
	for(i=0; i<n; i++)
	{
		*(c+i)=(int *)malloc((N+1)*sizeof(int));
	}
	
	initialize_c(c, n);                       //Calling for initialization
	
	make_me_changes(c, d, n, N+1);        //Calling for making changes function
	
	printf("Printing the table:\n\n");
	printf("COIN VALUE  ");
	for(i=0; i<=N; i++)
	{
		printf(" %d ", i);
	}
	printf("\n\n");
	
	for(i=0; i<n; i++)                                //Printing Final table
	{
		printf("  %d         ", *(d+i));
		for(j=0; j<=N; j++)
		{
			printf(" %d ", *(*(c+i)+j));
		}
		printf("\n");
	}
	
	printf("\nThe minimum number of coins required for value %d is/are %d.", N, *(*(c+n-1)+N));
	
	return 0;
}
