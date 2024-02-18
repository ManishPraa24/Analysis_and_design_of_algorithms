#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//PRACTICAL 8
//KNAP SACK PROGRAM USING GREEDY TECHNIQUE

void find_ratio(float *w, float *v, float *r, int n)   //Ratio calculation
{
	int i;
	
	for(i=0; i<n; i++)
	{
		*(r+i)=(float)(*(w+i))/(float)(*(v+i));
	}
}

void sort_by_weight_value(float *w, float *v, float *r, int n)    //Sorting according to ratios in increasing order
{
	int i, j, temp;
	
	for(i=0; i<n-1; i++)
	{
		for(j=0; j<n-1-i; j++)
		{
			if(*(r+j)>=*(r+j+1))
			{
				temp=*(r+j);
				*(r+j)=*(r+j+1);
				*(r+j+1)=temp;
				
				temp=*(w+j);
				*(w+j)=*(w+j+1);
				*(w+j+1)=temp;
				
				temp=*(v+j);
				*(v+j)=*(v+j+1);
				*(v+j+1)=temp;
			}
		}
	}
	
}

float knap_sack_greedy(float *w, float *v, float *r, int n, float limits)
{
	int i, j, k, f=0;
	float l=limits;
	float sum=0.0, ratio;
	
	for(i=0; i<n; i++)
	{
		if(*(w+i)>l)
		{
			f=1;
			break;
		}
		else{
			sum=sum+*(v+i);
			l=l-*(w+i);
		}
	}
	
	if(f!=0)
	{
		ratio=l/(*(w+i));
		sum=sum + ratio*(*(v+i));
	}
	
	return sum;
	
}

int main()
{
	int n,  i;
	float *w, *v, *r, weight_limit, max;
	
	printf("This is KNAP SACK GREEDY TECHNIQUE Program.\n");
	
	printf("\nEnter the number of the objects you want to enter: ");
	scanf("%d", &n);
	
	w=(float *)malloc(n*(sizeof(float)));
	v=(float *)malloc(n*(sizeof(float)));
	r=(float *)malloc(n*(sizeof(float)));
	
	for(i=0; i<n; i++)
	{
		printf("Enter the weight of object %d: ", i+1);
		scanf("%f", w+i);
		printf("Enter the value of object %d: ", i+1);
		scanf("%f", v+i);
	}
	
	printf("\nEnter the constraint weight for maximum profit: ");
	scanf("%f", &weight_limit);
	
	printf("\nThe entered data of objects is as follows: \n\n");
	printf("       WEIGHT     VALUE  \n\n");
	
	for(i=0; i<n; i++)
	{
		printf("%10.2f%10.2f\n", *(w+i), *(v+i));
	}
	
	find_ratio(w, v, r, n);
	
	printf("\nThe ratios of value/weight is as follows:\n");
	for(i=0; i<n; i++)
	{
		printf("%.2f\n", *(r+i));
	}
	printf("\n");
	
	sort_by_weight_value(w, v, r, n);
	
	max=knap_sack_greedy(w, v, r, n, weight_limit);
	
	printf("\nThe maximum profit possible from given data is %.2f.", max);
	
	return 0;
}
