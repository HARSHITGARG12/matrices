// AUTHOR : HARSHIT GARG
// DATE : JUNE 7, 2015
// PROGRAM : MATRICES
// STAUS :

#include <stdio.h>

#define M 100 
#define N 100

struct matrix
{
	int e[M][N];
	int row,
		col;
	int isSymmetric;
	int isHamilton;
	int isNull,
		isUnitary,
		isDaignol; 
}; 

//______rotate the matrix by 90 degree

void rotate90(struct matrix A)
{
	int i = 0,
		j = 0;
	
	struct matrix ans;
	ans.row = A.row;
	ans.col = A.col;
	for(i = 0 ; i < A.row; i++)
	{
		for(j = 0 ; j < A.col; j++)
		{
			ans.e[A.row-1-j][i] = A.e[i][j];
		}
	}		
	
	for(i = 0; i < A.row; i++)
	{
		for(j = 0; j < A.col; j++)
		{
 			printf("%d ",ans.e[i][j]); 
		} 
		printf("\n");
	}	
	
	for(i = 0 ; i < A.row; i++)
	{
		for(j = 0 ; j < A.col; j++)
		{
			ans.e[j][A.row-1-i] = A.e[i][j];
		}
	}
	
	for(i = 0; i < A.row; i++)
	{
		for(j = 0; j < A.col; j++)
		{
 			printf("%d ",ans.e[i][j]); 
		} 
		printf("\n");
	}	
}

//______mirrror image of a matrix 

void mirrorimage(struct matrix A)
{
	int i = 0,
		j = 0;
	
	struct matrix ans;
	ans.row = A.row;
	ans.col = A.col;
		
	for(i = 0; i < A.row; i++)
	{
		for(j = 0; j < A.col; j++)
		{
 			ans.e[i][A.col-1-j] = A.e[i][j]; 
		} 
	}	
	
	for(i = 0; i < A.row; i++)
	{
		for(j = 0; j < A.col; j++)
		{
 			printf("%d ",ans.e[i][j]); 
		} 
		printf("\n");
	}	
	
	// another possible matrix
	
	for(i = 0; i < A.row; i++)
	{
		for(j = 0; j < A.col; j++)
		{
 			ans.e[A.row-i-1][j] = A.e[i][j]; 
		} 
	}	
	
	for(i = 0; i < A.row; i++)
	{
		for(j = 0; j < A.col; j++)
		{
 			printf("%d ",ans.e[i][j]); 
		} 
		printf("\n");
	}
}
 
void circularPrint(struct matrix A)
{
	int r1 = 0,
		r2 = A.row - 1,
		c1 = 0,
		c2 = A.col - 1;
	int i = 0,
		j = 0;
	while(c1!=c2 && r1!=r2)
	{
		i = r1;
		for(j = c1; j <= c2; j++)
		{
			printf("%d ", A.e[i][j]);
		}
		r1 = r1 + 1;
		
		j = j - 1;
		for(i = r1; i <= r2; i++)
		{
			printf("%d ", A.e[i][j]);
		}
		c2 = c2 - 1;
		
		i = r2;
		for(j = c2; j >= c1; j--)
		{
			printf("%d ", A.e[i][j]);
		}
		if(r1 == r2)
			break;
		else
			r2 = r2 - 1;
		
		j = c1;
		for(i = r2; i >= r1; i--)
		{
			printf("%d ", A.e[i][j]);
		}
		
		if(c1 == c2)
			break;
		else
			c1 = c1 + 1;	
	}  	
	
	if(r1 == r2 && c1 == c2 )
	{
		if(A.row % 2)
			printf("%d ", A.e[r1][c1]);
	}
	else
	{
		if(r1 == r2)
		{
			for(j = c1; j <=c2; j++) 
				printf("%d ", A.e[r1][j]);
	
		}
		
		if(c1 == c2)
		{
			for(i = r1; i <=r2; i++) 
				printf("%d ", A.e[i][j]);
		}
	}	
}

void circularAntiPrint(struct matrix A)
{
	int r1 = 0,
		r2 = A.row - 1,
		c1 = 0,
		c2 = A.col - 1;
	int i = 0,
		j = 0;
	while(c1!=c2 && r1!=r2)
	{
		i = r1;
		for(j = c1; j <= c2; j++)
		{
			printf("%d ", A.e[i][j]);
		}
		r1 = r1 + 1;
		
		j = j - 1;
		for(i = r1; i <= r2; i++)
		{
			printf("%d ", A.e[i][j]);
		}
		c2 = c2 - 1;
		
		i = r2;
		for(j = c2; j >= c1; j--)
		{
			printf("%d ", A.e[i][j]);
		}
		if(r1 == r2)
			break;
		else
			r2 = r2 - 1;
		
		j = c1;
		for(i = r2; i >= r1; i--)
		{
			printf("%d ", A.e[i][j]);
		}
		
		if(c1 == c2)
			break;
		else
			c1 = c1 + 1;	
	}  	
	
	if(r1 == r2 && c1 == c2 )
	{
		if(A.row % 2)
			printf("%d ", A.e[r1][c1]);
	}
	else
	{
		if(r1 == r2)
		{
			for(j = c1; j <=c2; j++) 
				printf("%d ", A.e[r1][j]);
	
		}
		
		if(c1 == c2)
		{
			for(i = r1; i <=r2; i++) 
				printf("%d ", A.e[i][j]);
		}
	}
	
}

//______main 

int main()
{	
	int cases = 0;
 
	scanf("%d", &cases);
	
	if(cases < 1)
		return;	
	int row,
		col;
	int i = 0,
		j = 0;
	int count = 0;
	
	struct matrix A;
	
	while(count < cases)
	{	
		scanf("%d%d", &row, &col);
		//printf("%d %d\n", row, col);
		A.row = row;
		A.col = col;
		
		for(i = 0; i < row; i++)
		{
			for(j = 0; j < col; j++)
			{
				scanf("%d", &A.e[i][j]);
			}
		}
		printf("\n");	
		for(i = 0; i < A.row; i++)
		{
			for(j = 0; j < A.col; j++)
			{
 				printf("%d ", A.e[i][j]); 
			} 
			printf("\n");
		}
		//printf("\n");
		//mirrorimage(A);
		//rotate90(A);
		circularPrint(A);
		count++;
	}		
	return 0;
}
