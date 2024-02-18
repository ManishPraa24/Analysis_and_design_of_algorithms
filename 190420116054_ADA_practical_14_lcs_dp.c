#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//PRACTICAL 14
//Implementation Longest Common subsequence Algorithm using Dynamic Programming
//190420116054
//Pointer Version

void print_lcs(char **b, char *x, int xc, int yc)
{
	if(xc==0 || yc==0)
	{
		return;
	}
	
	if(*(*(b+xc)+yc)=='1')
	{
		print_lcs(b, x, xc-1, yc-1);
		printf("%c", *(x+xc-1));
	}
	else if(*(*(b+xc)+yc)=='2')
	{
		print_lcs(b, x, xc-1, yc);
	}
	else if(*(*(b+xc)+yc)=='3'){
		print_lcs(b, x, xc, yc-1);
	}
}

void long_cmon_seque(char *x, int xc, char *y, int yc, char **b, int **c)
{
	int i, j, k;
	for(i=1; i<=xc; i++)
	{
		for(j=1; j<=yc; j++)
		{
			if(*(x+i-1)==*(y+j-1))
			{
				*(*(c+i)+j)=*(*(c+i-1)+j-1) + 1;
				*(*(b+i)+j)='1';
			}
			else if(*(*(c+i-1)+j)>=*(*(c+i)+j-1))
			{
				*(*(c+i)+j)=*(*(c+i-1)+j);
				*(*(b+i)+j)='2';
			}
			else{
				*(*(c+i)+j)=*(*(c+i)+j-1);
				*(*(b+i)+j)='3';
			}
		}
	}
	
	printf("\nPrinting the Longest Common Sequence: ");
	
	print_lcs(b, x, xc, yc);
}

int main()
{
	char *x, *y, **b;
	int xc=0, yc=0, **c, i, j;
	
	printf("This is LONGEST COMMON SUBSEQUENCE program.\n\n");
	printf("NOTE:- Enter only alphabets in the string.\n\nNOTE:- Enter '0' sign to stop.\n\n");
	
	x=(char *)malloc(sizeof(char));
	xc++;
	
	printf("Enter your first string: ");
	scanf("%c", x);
	
	while(*(x+xc-1)!='0')
	{
		xc++;
		x=(char *)realloc(x, (xc)*sizeof(char));
		scanf("%c", &(*(x+xc-1)));
	}
	xc--;
	
	y=(char *)malloc(sizeof(char));
	yc++;
	
	printf("\nEnter your second string: ");
	scanf("%c", y);
	
	while(*(y+yc-1)!='0')
	{
		yc++;
		y=(char *)realloc(y, (yc)*sizeof(char));
		scanf("%c", &(*(y+yc-1)));
	}
	yc--;
	
	b=(char **)malloc((xc+1)*sizeof(char *));
	for(i=0; i<=xc; i++)
	{
		*(b+i)=(char *)malloc((yc+1)*(sizeof(char)));
	}
	
	c=(int **)malloc((xc+1)*sizeof(int *));
	
	for(i=0; i<=xc; i++)
	{
		*(c+i)=(int *)malloc((yc+1)*(sizeof(int)));
	}
	
	for(i=0; i<=xc; i++)
	{
		*(*(c+i)+0)=0;
	}
	
	for(i=0; i<=yc; i++)
	{
		*(*(c+0)+i)=0;
	}
	
	printf("\nEntered string 'x' is: ");
	for(i=0; i<xc; i++)
	{
		printf("%c", *(x+i));
	}
	
	printf("\nEntered string 'y' is: ");
	for(i=0; i<yc; i++)
	{
		printf("%c", *(y+i));
	}
	
	long_cmon_seque(x, xc, y, yc, b, c);
	
	return 0;
}
