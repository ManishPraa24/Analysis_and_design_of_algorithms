#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//PRACTICAL 10
//Dijkstra's Algorithm for finding Single source shortest path
//190420116054

int check_c_in_b(int *b, int bcount, int c)    //Checking uniqueness of the selected node haning minimum edge
{
	int i;
	for(i=0; i<bcount; i++)
	{
		if(*(b+i)==c)
		{
			return 1;
		}
	}
	
	return 0;
}

int minimun_of_c(int *d, int *c, int *b, int bcount, int n)     //Finding appropriate value for V
{
	int min=0, f=0, minc=0, i;
	for(i=0; i<n-1; i++)
	{
		if(i==0 && check_c_in_b(b, bcount, *(c+i))==0 && *(d+i)!=0 && f==0)
		{
			min=*(d+i);
			minc=*(c+i);
			f=1;
		}
		else if(f==0 && check_c_in_b(b, bcount, *(c+i))==0 && *(d+i)!=0)
		{
			min=*(d+i);
			minc=*(c+i);
			f=1;
		}
		else if(min>*(d+i) && check_c_in_b(b, bcount, *(c+i))==0 && *(d+i)!=0)
		{
			min=*(d+i);
			minc=*(c+i);
		}
	}
	*(b+bcount)=minc;
	return minc;
}

int min(int a, int b)        //Finding minimum value between two values entered here
{
	if(a<b)
		return a;
	else
		return b;
}


int * dijikstraa_give_me_answer(int **l, int n)    //Dijkstra algo: Function calculating optimum answer
{
	int *d, *c, *b, i, j, v, bcount=0, w;
	
	d=(int *)malloc((n-1)*(sizeof(int)));
	c=(int *)malloc((n-1)*(sizeof(int)));
	
	for(i=0; i<n-1; i++)
	{
		*(c+i)=i+1;
	}
	
	for(i=0; i<n-1; i++)
	{
		*(d+i)=*(*(l+0)+i+1);
	}
	
	b=(int *)malloc((n)*sizeof(int));
	*(b+bcount)=0;
	bcount++;
	
	while(bcount!=(n))
	{
		v=minimun_of_c(d, c, b, bcount, n);
		bcount++;
		
		for(j=0; j<n-1; j++)
		{
			w=*(c+j);
			if(*(*(l+v)+w)!=0 && *(d+v-1)!=0)
			{
				if(*(d+w-1)==0)
				{
					*(d+w-1)=*(*(l+v)+w) + *(d+v-1);
				}
				else{
					*(d+w-1)=min(*(d+w-1), *(*(l+v)+w) + *(d+v-1));
				}
			}
		}
		
	}
	
	return d;
}

int main()        //MAIN FUNCTION
{
	int **l, i, j, n, *d;
	printf("This is DIJIKSTRA'S ALGORITHM.\n\n");
	printf("Enter the no. of nodes graph is having: ");
	again1:
		scanf("%d", &n);
		if(n<=0)
		{
			printf("Enter a natural number. Please enter it again: ");
			goto again1;
		}
	
	l=(int **)malloc(n*sizeof(int *));
	for(i=0; i<n; i++)
	{
		*(l+i)=(int *)malloc(n*(sizeof(int)));
	}
	
	//NOTE: Here, circular edge is denied, it is not considered or accepted in this program.
	
	printf("\nStart entering the value of edges:\n\nNOTE:- Enter '0' if there's no edge of particular direction or not present at all.\n\n NOTE:- Starting index is considered node '1'.\n\n");
	
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			if(i==j)
			{
				*(*(l+i)+j)=0;
				continue;
			}
			printf("Value of edge from %d to %d: ", i+1, j+1);
			again2:
				scanf("%d", &*(*(l+i)+j));
				if(*(*(l+i)+j)<0)
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
			printf("%5d", *(*(l+i)+j));
		}
		printf("\n");
	}
	

	d=(int *)dijikstraa_give_me_answer(l, n);   //Calling the function that will give us answer using dijkstra's algorithm
	
	printf("\nPrinting the minimum length of nodes from node '1':\n");
	
	for(i=0; i<n-1; i++)
	{
		printf("Length from node '1' to node '%d': %d\n", i+2, *(d+i));
	}
	
	return 0;
}
