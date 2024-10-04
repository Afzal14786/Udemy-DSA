#include <stdio.h>
#include <stdlib.h>

// create an struct of elements ///

struct Element {
    int i;
    int j;
    int value;
};

// create a structure of sparse matrix.

struct Spares_Matrix {
    int row_no;
    int col_no;
    int num_of_non_zeros;

    struct Element *arr;

    
};

void Create (struct Spares_Matrix *sparse) {
    printf("Enter The Dimentions Of The Matrix : ");
    scanf("%d %d", &sparse->row_no, &sparse->col_no);

    printf("Enter The no of non-zeros : ");
    scanf("%d", &sparse->num_of_non_zeros);


    // Allocating The Memory In Heap //
    sparse->arr = (struct Element *)malloc(sparse->num_of_non_zeros * sizeof (struct Element));

    if (sparse->arr == NULL) {
        printf("Memory Allocation Is Failed. \n");
        exit(1);
    }


    printf("Enter All The Non-Zero Elements.\n");
    for (int i = 0; i < sparse->num_of_non_zeros; ++i) {
        scanf("%d %d %d", &sparse->arr[i].i, &sparse->arr[i].j, &sparse->arr[i].value);
    }
}

void Display (struct Spares_Matrix sparse) {
    int k = 0;
    for (int i = 0; i < sparse.row_no; ++i) {
        for (int j = 0; j < sparse.col_no; ++j) {
            if (i == sparse.arr[k].i && j == sparse.arr[k].j) {
                printf("%d ", sparse.arr[k++].value);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

void main() {
    struct Spares_Matrix sparse;

    Create(&sparse);
    printf("-------------- Here Is The Sparse Matrix --------------\n");
    Display(sparse);

    free(sparse.arr);
}
