#include <stdio.h>
#include <math.h>
#include <inttypes.h>
#include <string.h>
#include <malloc.h>

void output(int **matrix1)
{
	char column_style[] = "%4d|";
	char number_style[] = "%4d" ;
	printf("\n    |");
	int ret = 5;
	for(int i = 0; i < 9; i++)
	{
		ret += printf(number_style, i);
	}
	printf("\n");
	for(int i = 0; i < ret; i++)
	{
		printf("-");
	}
	printf("\n");
	for(int i = 0; i < 9; i++)
	{
		printf(column_style, i);
		for(int j = 0; j < 9; j++)
		{
			printf(number_style, matrix1[i][j]);
		}
		printf("|\n");
	}
	return;
}
int **multi(int **matrix_a,int **matrix_b)
{
	int **new_matrix = (int **)malloc(sizeof(int)*81); 
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			for(int k = 0; k < 9; k++)
			{
				new_matrix[i][j] += matrix_a[i][k] * matrix_b[k][j];
			}
		}
	}
	return new_matrix;
}
int main()
{

	int *matrix1[9] = (int **)malloc(sizeof(int *)*9);
	for(int i = 0; i < 9; i++)
	{
		for(int j = i + 1; j < 9; j++)
		{
			if(j - i == 1 && j % 3 == 0) continue;
			if(j - i != 1 && j - i != 3) continue;
			matrix1[i][j] = 1;
			matrix1[j][i] = 1;
		}
	}	
/*	output(matrix1);
	matrix1 = multi(matrix1,matrix1);
	output(matrix1);*/
}