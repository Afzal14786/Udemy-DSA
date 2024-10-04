#include <stdio.h>
#include <stdlib.h>

// create a structure of elements
struct Element {
    int i;
    int j;
    int value;
};

// create a structure of sparse matrix
struct Sparse {
    int row_no;
    int cols_no;
    int non_zeros;
    struct Element *array;
};

void Create(struct Sparse *sparse) {
    printf("Enter the dimensions of the matrix: ");
    scanf("%d %d", &sparse->row_no, &sparse->cols_no);

    printf("Enter the number of non-zeros: ");
    scanf("%d", &sparse->non_zeros);

    // Allocating memory in heap
    sparse->array = (struct Element *)malloc(sparse->non_zeros * sizeof(struct Element));

    if (sparse->array == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    printf("Enter all the non-zero elements (row, col, value).\n");
    for (int i = 0; i < sparse->non_zeros; ++i) {
        scanf("%d %d %d", &sparse->array[i].i, &sparse->array[i].j, &sparse->array[i].value);
    }
}

void Display(struct Sparse sparse) {
    int k = 0;
    for (int i = 0; i < sparse.row_no; ++i) {
        for (int j = 0; j < sparse.cols_no; ++j) {
            if (k < sparse.non_zeros && i == sparse.array[k].i && j == sparse.array[k].j) {
                printf("%d ", sparse.array[k++].value);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

struct Sparse *Add(struct Sparse *s1, struct Sparse *s2) {
    // Check for dimension mismatch
    if (s1->row_no != s2->row_no || s1->cols_no != s2->cols_no) {
        return NULL;
    }

    // Storing the sum values
    struct Sparse *sum = (struct Sparse *)malloc(sizeof(struct Sparse));
    sum->array = (struct Element *)malloc((s1->non_zeros + s2->non_zeros) * sizeof(struct Element));

    int i = 0, j = 0, k = 0;
    while (i < s1->non_zeros && j < s2->non_zeros) {
        if (s1->array[i].i < s2->array[j].i) {
            sum->array[k++] = s1->array[i++];
        } else if (s1->array[i].i > s2->array[j].i) {
            sum->array[k++] = s2->array[j++];
        } else {
            if (s1->array[i].j < s2->array[j].j) {
                sum->array[k++] = s1->array[i++];
            } else if (s1->array[i].j > s2->array[j].j) {
                sum->array[k++] = s2->array[j++];
            } else {
                // Add the values
                sum->array[k] = s1->array[i];
                sum->array[k++].value = s1->array[i++].value + s2->array[j++].value;
            }
        }
    }
    

    // Copy remaining elements
    for (; i < s1->non_zeros; ++i) {
        sum->array[k++] = s1->array[i];
    }
    for (; j < s2->non_zeros; ++j) {
        sum->array[k++] = s2->array[j];
    }

    sum->row_no = s1->row_no;
    sum->cols_no = s1->cols_no;
    sum->non_zeros = k; // Set the number of non-zero elements in the sum

    return sum;
}

int main() {
    struct Sparse s1, s2, *s3;

    Create(&s1);
    Create(&s2);

    s3 = Add(&s1, &s2);

    if (s3 == NULL) {
        printf("Matrices cannot be added due to dimension mismatch.\n");
    } else {
        printf("The first matrix:\n");
        Display(s1);
        printf("The second matrix:\n");
        Display(s2);
        printf("The result matrix is:\n");
        Display(*s3);

        // Free the allocated memory
        free(s1.array);
        free(s2.array);
        free(s3->array);
        free(s3);
    }

    return 0;
}
