#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int row;
	int col;
	float** data;
} Matrix;

int checkmatrix(Matrix A, Matrix B) {
	if ((A.row == B.row)&&(A.col == B.col))
		return 1;
	else {
		printf("that is wrong\n");
		return 0;
	}	
}

void fillArray(Matrix* A) {
	// Allocate Memory
    A->data = (float**) malloc(sizeof(float*) * A->row);
	for (int i = 0;i<A->row;i++) {
		A->data[i] = (float*)calloc(A->col,sizeof(float));
	}

	for (int i = 0;i<A->row;i++) {
		for(int j =0;j<A->col;j++) {
			printf("Enter Data[%d][%d]: ", i + 1, j + 1);
			scanf("%f",&A->data[i][j]);
		}
	}
	printf("\n");

}

void printMatrix(Matrix* A,char name) {
	printf("Matrix %c\n",name);
	for (int i = 0;i<A->row;i++) {
		for(int j=0;j<A->col;j++) {
			printf("%.02f\t",A->data[i][j]);
		}
		printf("\n");
	}printf("\n");
}

Matrix add(Matrix* A,Matrix* B){
	Matrix C;
	C.row = A->row;
	C.col = A->col;
	C.data = (float**) malloc(sizeof(float*) * C.row);
	for (int i = 0;i<C.row;i++) {
		C.data[i] = (float*)calloc(C.col,sizeof(float));
	}

	for (int i = 0;i<A->row;i++) {
		for(int j =0;j<A->col;j++) {
			C.data[i][j] = A->data[i][j]+ B->data[i][j];
		}
	}
	return C;
	
}

Matrix minus(Matrix* A,Matrix* B){
	Matrix C;
	C.row = A->row;
	C.col = A->col;
	C.data = (float**) malloc(sizeof(float*) * C.row);
	for (int i = 0;i<C.row;i++) {
		C.data[i] = (float*)calloc(C.col,sizeof(float));
	}

	for (int i = 0;i<A->row;i++) {
		for(int j =0;j<A->col;j++) {
			C.data[i][j] = A->data[i][j]- B->data[i][j];
		}
	}
	return C;
	
}

Matrix tranpose(Matrix*A){
	Matrix C;
	C.row = A->col;
	C.col = A->row;
	C.data = (float**) malloc(sizeof(float*) * C.row);
	for (int i = 0;i<C.row;i++) {
		C.data[i] = (float*)calloc(C.col,sizeof(float));
	}

    for (int i = 0; i <C.row; i++){
        for (int j = 0; j < C.col; j++){
            C.data[i][j] = A->data[j][i];
		}
	}
	return C;
}

int main() {
	Matrix A ;  
	Matrix B ; 
	Matrix C ; 
	
	do {
		printf("Enter rowA: ");
		scanf("%d",&A.row);
		printf("Enter colA: ");
		scanf("%d",&A.col);
		printf("Enter rowB: ");
		scanf("%d",&B.row);
		printf("Enter colB: ");
		scanf("%d",&B.col);
		printf("\n");

	} while (!checkmatrix(A,B));
	fillArray(&A);
	printMatrix(&A,'A');
	// fillArray(&B);
	// printMatrix(&B,'B');

	C = tranpose(&A);
	printMatrix(&C,'C');
	
}