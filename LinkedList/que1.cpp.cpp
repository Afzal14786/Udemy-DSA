#include <iostream>
#include <iomanip>

class Term {
public:
    int coefficient;
    int exponent;
    Term* next;

    Term(int coeff, int exp) : coefficient(coeff), exponent(exp), next(nullptr) {}
};

class Polynomial {
private:
    Term* head;

public:
    Polynomial() : head(nullptr) {}

    void addTerm(int coeff, int exp) {
        Term* newTerm = new Term(coeff, exp);
        if (!head || exp > head->exponent) {
            newTerm->next = head;
            head = newTerm;
        } else {
            Term* current = head;
            while (current->next && current->next->exponent >= exp) {
                current = current->next;
            }
            if (current->exponent == exp) {
                current->coefficient += coeff;
                delete newTerm;
            } else {
                newTerm->next = current->next;
                current->next = newTerm;
            }
        }
    }

    void display() const {
        Term* current = head;
        while (current) {
            std::cout << current->coefficient << "x^" << current->exponent;
            current = current->next;
            if (current) std::cout << " + ";
        }
        std::cout << std::endl;
    }

    friend Polynomial addPolynomials(const Polynomial& p1, const Polynomial& p2);
};

Polynomial addPolynomials(const Polynomial& p1, const Polynomial& p2) {
    Polynomial result;
    Term* t1 = p1.head;
    Term* t2 = p2.head;

    while (t1 && t2) {
        if (t1->exponent > t2->exponent) {
            result.addTerm(t1->coefficient, t1->exponent);
            t1 = t1->next;
        } else if (t1->exponent < t2->exponent) {
            result.addTerm(t2->coefficient, t2->exponent);
            t2 = t2->next;
        } else {
            int sum = t1->coefficient + t2->coefficient;
            if (sum != 0) {
                result.addTerm(sum, t1->exponent);
            }
            t1 = t1->next;
            t2 = t2->next;
        }
    }

    while (t1) {
        result.addTerm(t1->coefficient, t1->exponent);
        t1 = t1->next;
    }

    while (t2) {
        result.addTerm(t2->coefficient, t2->exponent);
        t2 = t2->next;
    }

    return result;
}

int main() {
    Polynomial p1, p2;

    // Input for first polynomial
    std::cout << "Enter terms for first polynomial (coefficient exponent), end with 0 0:\n";
    int coeff, exp;
    while (true) {
        std::cin >> coeff >> exp;
        if (coeff == 0 && exp == 0) break;
        p1.addTerm(coeff, exp);
    }

    // Input for second polynomial
    std::cout << "Enter terms for second polynomial (coefficient exponent), end with 0 0:\n";
    while (true) {
        std::cin >> coeff >> exp;
        if (coeff == 0 && exp == 0) break;
        p2.addTerm(coeff, exp);
    }

    std::cout << "First polynomial: ";
    p1.display();

    std::cout << "Second polynomial: ";
    p2.display();

    Polynomial sum = addPolynomials(p1, p2);
    std::cout << "Sum of polynomials: ";
    sum.display();

    return 0;
}