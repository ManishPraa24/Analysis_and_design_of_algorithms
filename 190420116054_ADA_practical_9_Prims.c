#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//PRACTICAL- 9
//Analysis And design of Algorithms
//190420116054

void initialize_it(int **e, int len)  //Commom index initialization
{
	int i=0;
	for(i=0; i<len; i++)
	{
		*(*(e+i)+i)=0;
	}
}

int check_b(int j, int *b, int count)   //Function for checking the value in B 
{
	int i;
	for(i=0; i<count; i++)
	{
		if(j==*(b+i))
		{
			return 1;
		}
	}
	
	return 0;
}


int get_me_next_b(int *b, int j)  //Function for getting next value in B
{
	return *(b+j);
}

int main()
{
	int a, n, i, j, **e, *b, count=1, sum=0, min, min2, min3, flag;
	
	printf("This is PRIM's Algorithm.\n\n");
	printf("Enter the number of vertices: ");
	again1:
	scanf("%d", &n);                                          //Taking the number of nodes in graph
	if(n<=0)
	{
		printf("\nPlease enter a Natural number. Enter again:\n");
		goto again1;
	}
	
	e=(int**)malloc(n*sizeof(int *));
	
	for(i=0; i<n; i++)
	{
		*(e+i)=(int *)malloc(n*(sizeof(int)));
	}
	
	initialize_it(e, n);
	
	printf("\nPlease enter the edge weights(Enter '0' if there's no edge): \n");    //Taking values of edges
	for(i=0; i<n; i++)
	{
		printf("\n");
		for(j=i+1; j<n; j++)
		{
			printf("Enter the edge value from node %d to node %d: ", i+1, j+1);
			again:
			scanf("%d", &*(*(e+i)+j));
			if(*(*(e+i)+j)<0)
			{
				printf("\nPlease enter a whole number. Enter again.\n");
				goto again;
			}
			*(*(e+j)+i)=*(*(e+i)+j);
		}
	}
	
	printf("\nEntered matrix looks like:\n");   //Displaying the matrix form of graph
	
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			printf("%d  ", *(*(e+i)+j));
		}
		printf("\n");
	}
	
	printf("\n");
	
	b=(int *)malloc(sizeof(int));
	
	*b=0;
	
	while(count!=n)    //Main loop for finding length of MST
	{
		min=0;
		min2=0;
		min3=0;
		j=0;
		flag=0;
		while(j<count)
		{
			a=get_me_next_b(b, j);
			
			for(i=0; i<n; i++)                                             //Loop for finding minimum length from nodes that are connected
			{
				if(*(*(e+a)+i)!=0 && check_b(i, b, count)==0 && flag==0)
				{
					min=*(*(e+a)+i);
					min2=i;
					min3=a;
					flag=1;
				}
				else if(*(*(e+a)+i)!=0 && min>*(*(e+a)+i) && check_b(i, b, count)==0 &&flag!=0)
				{
					min=*(*(e+a)+i);
					min2=i;
					min3=a;
				}
			}
			j++;
		}
		
		count++;
		b=(int *)realloc(b, count*sizeof(int));
		
		*(b+count-1)=min2;
		sum=sum+min;                        //Calculation
	}
	
	printf("\nThe length of Minimum Spanning Tree is: %d\n", sum);      //Final Answer
	
	return 0;
}
