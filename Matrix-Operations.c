#include <stdio.h>

void inputMatrix(int rows, int cols, int matrix[10][10]) {
    int i, j;
    printf("Enter matrix elements:\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int rows, int cols, int matrix[10][10]) {
    int i, j;
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(int rows, int cols, int A[10][10], int B[10][10]) {
    int C[10][10], i, j;

    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    printf("\nMatrix Addition Result:\n");
    displayMatrix(rows, cols, C);
}

void multiplyMatrix(int r1, int c1, int A[10][10], int r2, int c2, int B[10][10]) {
    int C[10][10], i, j, k;

    if(c1 != r2) {
        printf("\nMatrix multiplication is not possible.\n");
        return;
    }

    for(i = 0; i < r1; i++) {
        for(j = 0; j < c2; j++) {
            C[i][j] = 0;
            for(k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("\nMatrix Multiplication Result:\n");
    displayMatrix(r1, c2, C);
}

void transposeMatrix(int rows, int cols, int A[10][10]) {
    int T[10][10], i, j;

    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            T[j][i] = A[i][j];
        }
    }

    printf("\nTranspose of Matrix:\n");
    displayMatrix(cols, rows, T);
}

int main() {
    int A[10][10], B[10][10];
    int r1, c1, r2, c2;

    printf("Enter rows and columns of Matrix A: ");
    scanf("%d%d", &r1, &c1);

    inputMatrix(r1, c1, A);

    printf("Enter rows and columns of Matrix B: ");
    scanf("%d%d", &r2, &c2);

    inputMatrix(r2, c2, B);

    if(r1 == r2 && c1 == c2)
        addMatrix(r1, c1, A, B);
    else
        printf("\nMatrix addition is not possible.\n");

    multiplyMatrix(r1, c1, A, r2, c2, B);

    printf("\nTranspose of Matrix A:\n");
    transposeMatrix(r1, c1, A);

    return 0;
}