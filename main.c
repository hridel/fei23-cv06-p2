#include <stdio.h>
#include <stdlib.h>

int main() {
    int **matrix;  // declare pointer to pointer to integer
    int n, i, j;

    // prompt user for matrix size
    printf("Zadejte n určující velikost matice (n x n): ");
    scanf("%d", &n);

    // dynamically allocate memory for matrix
    matrix = (int**) malloc(n * sizeof(int*));
    for (i = 0; i < n; i++) {
        matrix[i] = (int*) malloc(n * sizeof(int));
    }

    // check if allocation was successful
    if (matrix == NULL) {
        printf("Error: Nelze alokovat pamet.\n");
        return 1;
    }

    // prompt user to enter values for matrix
    printf("Zadejte hodnoty pro matici %d x %d:\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // print out the values in the matrix
    printf("Hodnoty matice jsou:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }

    // free dynamically allocated memory
    for (i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
