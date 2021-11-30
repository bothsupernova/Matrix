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

int checkmatrix2(Matrix A, Matrix B)
{
    if ((A.row == B.col) && (A.col == B.row))
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
    Matrix A, B, C;
    int runner = 1;
    int usin, usin2;
    int row, col;
    int checker1 = 0, checker2 = 0;
    while (runner)
    {
        printf("which function do you fucking want from me:\n");
        printf("[1] Define\n");
        printf("[2] Addition\n");
        printf("[3] Subtraction\n");
        printf("[4] Multiplication\n");
        printf("[5] Transpose\n");
        printf("[0] End program\n");
        printf("> ");
        scanf("%d", &usin);

        switch (usin)
        {
        case 0:
            runner = 0;
            break;

        case 1:
            printf("you want create Matrix A or Matrix B: \n");
            printf("[1] A\n");
            printf("[2] B\n");
            printf("> ");
            scanf("%d", &usin2);
            if (usin2 == 1)
            {
                printf("Enter row and col: ");
                scanf("%d %d", &row, &col);
                A = createMatrix(row, col);
                fillArray(&A);
                printMatrix(&A, 'A');
                checker1 = 1;
            }
            else if (usin2 = 2)
            {
                printf("Enter row and col: ");
                scanf("%d %d", &row, &col);
                B = createMatrix(row, col);
                fillArray(&B);
                printMatrix(&B, 'B');
                checker2 = 1;
            }
            break;

        case 2:
            if (checker1 == 0)
            {
                printf("Not define A \n");
            }
            if (checker2 == 0)
            {
                printf("Not define B \n");
            }
            if (checkmatrix(A, B))
            {
                C = add(&A, &B);
                printMatrix(&C, 'C');
            }
            break;

        case 3:
            if (checker1 == 0)
            {
                printf("Not define A \n");
            }
            if (checker2 == 0)
            {
                printf("Not define B \n");
            }
            if (checkmatrix(A, B))
            {
                C = minus(&A, &B);
                printMatrix(&C, 'C');
            }
            break;

        case 4:
            if (checker1 == 0)
            {
                printf("Not define A \n");
            }
            if (checker2 == 0)
            {
                printf("Not define B \n");
            }
            if (checkmatrix2(A, B))
            {
                C = multi(&A, &B);
                printMatrix(&C, 'C');
            }
            break;

        case 5:
            if (checker1 == 0)
            {
                printf("Not define A \n");
            }
            if (checker2 == 0)
            {
                printf("Not define B \n");
            }

            if (checker1 && checker2)
            {
                printf("transpose: \n");
                printf("[1] A\n");
                printf("[2] B\n");
                printf("> ");
                scanf("%d", &usin2);
                if (usin2 == 1){
                    C = tranpose(&A);
                    printMatrix(&C,'C');
                }
                if (usin2 == 2){
                    C = tranpose(&B);
                    printMatrix(&C,'C');
                }
            }
            break;
        }
    }
    return 0;
}