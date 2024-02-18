#include<stdio.h>
#include<conio.h>

//Practical No. 12
//Implementation and Time analysis of 0/1 Knapsack Problem using dynamic Programming
//Array Version

int max(int a, int b){      //Function returning maximum of both values
	if(a>b)
		return a;
	else if(b>a)
		return b;
}

void knapsack_0_1_dynamic(int v[100][100], int V[], int w[], int W, int n)       //Knap_sack_0_1 Function
{
	int i, j;
	
	for(i=0; i<=n; i++)
	{
		v[i][0]=0;
	}
	
	for(i=0; i<=W; i++)
	{
		v[0][i]=0;
	}
	
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=W; j++)
		{
			if(j-w[i]<0)
			{
				v[i][j]=v[i-1][j];
			}
			else{
				v[i][j]=max(v[i-1][j], V[i]+v[i-1][j-w[i]]);
			}
		}
	}
	
}

int main()                  //Actual MAIN Function
{
	int v[100][100], V[100], w[100], W, n, i, k, j;
	
	printf("This is 0/1 Knapsack Program using dynamic programming.\n\n");
	
	printf("Enter the weight for which you want maximum value: ");
	again1:
		scanf("%d", &W);
		if(W<=0)
		{
			printf("Please enter a natural number. Enter it again: ");
			goto again1;
		}
		
	printf("\nEnter the number of weights and value pairs you have: ");
	again2:
		scanf("%d", &n);
		if(n<=0)
		{
			printf("Please enter a natural number. Enter it again: ");
			goto again2;
		}
	
	w[0]=0; V[0]=0;
	
	printf("\nStart entering the data: \n");
	
	for(i=1; i<=n; i++)
	{
		printf("Enter the weight: ");
		again3:
			scanf("%d", &w[i]);
			if(w[i]<=0)
			{
				printf("Please enter a natural number. Enter it again: ");
				goto again3;				
			}
			
		printf("Enter the value for weight %d: ", w[i]);
		again4:
			scanf("%d", &V[i]);
			if(V[i]<=0)
			{
				printf("Please enter a natural number. Enter it again: ");
				goto again4;
			}
	}
	
	knapsack_0_1_dynamic(v, V, w, W, n);	
	
	printf("\nDisplaying the tabular answer: \n");
	
	for(i=0; i<=n; i++)
	{
		for(j=0; j<=W; j++)
		{
			printf("%6d", v[i][j]);
		}
		printf("\n");
	}
	
	printf("\nThe maximum value for weight %d is %d.\n", W, v[n][W]);
	
	return 0;
}
