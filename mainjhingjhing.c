#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int row;
	int col;
	float **data;
} Matrix;

Matrix createMatrix(int row, int col)
{
	Matrix res;
	res.row = row;
	res.col = col;
	res.data = (float **)malloc(sizeof(float *) * res.row);
	for (int i = 0; i < res.row; i++)
	{
		res.data[i] = (float *)calloc(res.col, sizeof(float));
	}
	return res;
}

int checkmatrix(Matrix A, Matrix B)
{
	if ((A.row == B.row) && (A.col == B.col))
		return 1;
	else
	{
		printf("that is wrong\n");
		return 0;
	}
}

void fillArray(Matrix *A)
{
	// Allocate Memory
	A->data = (float **)malloc(sizeof(float *) * A->row);
	for (int i = 0; i < A->row; i++)
	{
		A->data[i] = (float *)calloc(A->col, sizeof(float));
	}

	for (int i = 0; i < A->row; i++)
	{
		for (int j = 0; j < A->col; j++)
		{
			printf("Enter Data[%d][%d]: ", i + 1, j + 1);
			scanf("%f", &A->data[i][j]);
		}
	}
	printf("\n");
}

void printMatrix(Matrix *A, char name)
{
	printf("Matrix %c\n", name);
	for (int i = 0; i < A->row; i++)
	{
		for (int j = 0; j < A->col; j++)
		{
			printf("%.02f\t", A->data[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

Matrix add(Matrix *A, Matrix *B)
{
	Matrix C = createMatrix(A->row, A->col);

	for (int i = 0; i < A->row; i++)
	{
		for (int j = 0; j < A->col; j++)
		{
			C.data[i][j] = A->data[i][j] + B->data[i][j];
		}
	}
	return C;
}

Matrix minus(Matrix *A, Matrix *B)
{
	Matrix C = createMatrix(A->row, A->col);

	for (int i = 0; i < A->row; i++)
	{
		for (int j = 0; j < A->col; j++)
		{
			C.data[i][j] = A->data[i][j] - B->data[i][j];
		}
	}
	return C;
}

Matrix tranpose(Matrix *A)
{
	Matrix C = createMatrix(A->row, A->col);

	for (int i = 0; i < C.row; i++)
	{
		for (int j = 0; j < C.col; j++)
		{
			C.data[i][j] = A->data[j][i];
		}
	}
	return C;
}

Matrix multi(Matrix *A, Matrix *B)
{
	Matrix C = createMatrix(A->row, B->col);

	for (int i = 0; i < A->row; i++)
	{
		for (int j = 0; j < B->col; j++)
		{
			C.data[i][j] = 0;

			for (int k = 0; k < B->row; k++)
				C.data[i][j] += A->data[i][k] * B->data[k][j];
		}
	}
	return C;
}

int main()
{
	Matrix A;
	Matrix B;
	Matrix C;

	do
	{
		printf("Enter rowA: ");
		scanf("%d", &A.row);
		printf("Enter colA: ");
		scanf("%d", &A.col);
		printf("Enter rowB: ");
		scanf("%d", &B.row);
		printf("Enter colB: ");
		scanf("%d", &B.col);
		printf("\n");

	} while (!checkmatrix(A, B));
	fillArray(&A);
	printMatrix(&A, 'A');
	fillArray(&B);
	printMatrix(&B, 'B');

	C = multi(&A,&B);
	printMatrix(&C, 'C');
}