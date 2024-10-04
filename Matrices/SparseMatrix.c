#include <stdio.h>
#include <stdlib.h>

// Define the structure for a sparse matrix element
struct Element {
    int i, j, value;
};

// Define the structure for a sparse matrix
struct SparseMatrix {
    int row;
    int cols;
    int nums;
    struct Element* elem;
};

// Function to create a sparse matrix
void create(struct SparseMatrix* sparse) {
    printf("Enter the dimensions (rows and columns):\n");
    scanf("%d %d", &sparse->row, &sparse->cols);

    printf("Enter the number of non-zero elements: ");
    scanf("%d", &sparse->nums);

    // Allocate memory for the non-zero elements
    sparse->elem = (struct Element*)malloc(sparse->nums * sizeof(struct Element));

    // Check if memory allocation was successful
    if (sparse->elem == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    printf("Enter the non-zero elements (row, col, value):\n");
    for (int i = 0; i < sparse->nums; ++i) {
        scanf("%d %d %d", &sparse->elem[i].i, &sparse->elem[i].j, &sparse->elem[i].value);
    }
}

// Function to display a sparse matrix
void Display(struct SparseMatrix sparse) {
    int k = 0;
    for (int i = 0; i < sparse.row; i++) {
        for (int j = 0; j < sparse.cols; j++) {
            if (k < sparse.nums && i == sparse.elem[k].i && j == sparse.elem[k].j) {
                printf("%d ", sparse.elem[k++].value);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() {
    struct SparseMatrix sparse;

    create(&sparse);

    printf("-------------- Here Is The Sparse Matrix --------------\n");

    Display(sparse);

    // Free the allocated memory
    free(sparse.elem);

    return 0;
}
