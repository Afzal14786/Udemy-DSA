#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Term {
    int coff;
    int exp;
};

struct Poly {
    int num;
    struct Term *term;
};

// Function to create a polynomial
void Create(struct Poly *pol) {
    printf("Enter The Number Of Terms: ");
    scanf("%d", &pol->num);

    // Allocate memory for the terms
    pol->term = (struct Term *)malloc(pol->num * sizeof(struct Term));
    printf("Enter Non-Zero Terms (coefficient and exponent):\n");
    for (int i = 0; i < pol->num; ++i) {
        printf("Enter (coefficient and exponent) Of %d: ", i + 1);
        scanf("%d %d", &pol->term[i].coff, &pol->term[i].exp);
    }
}

// Function to display a polynomial
void Display(struct Poly p) {
    for (int i = 0; i < p.num; ++i) {
        printf("%dx^%d", p.term[i].coff, p.term[i].exp);
        if (i < p.num - 1) {
            printf(" + ");
        }
    }
    printf("\n");
}

// Function to add two polynomials
struct Poly *Add(struct Poly *p1, struct Poly *p2) {
    // Create a sum structure
    struct Poly *sum;
    sum = (struct Poly *)malloc(sizeof(struct Poly));
    sum->term = (struct Term *)malloc((p1->num + p2->num) * sizeof(struct Term));

    int i = 0, j = 0, k = 0;

    // Compare and add terms
    while (i < p1->num && j < p2->num) {
        if (p1->term[i].exp > p2->term[j].exp) {
            sum->term[k++] = p1->term[i++];
        } else if (p2->term[j].exp > p1->term[i].exp) {
            sum->term[k++] = p2->term[j++];
        } else {
            sum->term[k].exp = p1->term[i].exp;
            sum->term[k++].coff = p1->term[i++].coff + p2->term[j++].coff;
        }
    }

    // Copy remaining terms
    while (i < p1->num) {
        sum->term[k++] = p1->term[i++];
    }
    while (j < p2->num) {
        sum->term[k++] = p2->term[j++];
    }

    // Assign the total number of terms
    sum->num = k;

    return sum;
}

struct Poly * Multiplay(struct Poly *p1, struct Poly *p2) {
    struct Poly *mul;
    mul = (struct Poly *)malloc(sizeof(struct Poly));
    mul->term = (struct Term *)malloc((p1->num * p2->num) * sizeof(struct Term));

    int k = 0;
    if (p1->num == 0 || p2->num == 0 ) {
        printf("Multiplecation Not Possible .\n");
        return NULL;
    } else {
        for (int i = 0; i < p1->num; i++) {
            for (int j = 0; j < p2->num; j++) {
                mul->term[k].coff = p1->term[i].coff * p2->term[j].coff;
                mul->term[k].exp = p1->term[i].exp + p2->term[j].exp;
                k++;
            }
        }

        mul->num = k;

        return mul;
    }
}

int main() {
    struct Poly p1, p2, *p3;
    Create(&p1);
    Create(&p2);

    // Correctly assign the result of the addition
    p3 = Multiplay(&p1, &p2);

    printf("First Polynomial Is: ");
    Display(p1);

    printf("\nSecond Polynomial Is: ");
    Display(p2);

    printf("\nSum Of Two Polynomials Is: ");
    Display(*p3);

    // Free allocated memory
    free(p1.term);
    free(p2.term);
    free(p3->term);
    free(p3);

    return 0;
}
