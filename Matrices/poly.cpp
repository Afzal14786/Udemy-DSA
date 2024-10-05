#include <iostream>
using namespace std;

class Term {

    public:
        int coff;
        int exp;
};

class Poly {
    private:
        int num;
        Term *terms;
    
    public:
        Poly(int num) {
            this->num = num;
            terms = new Term[this->num];
        }

        ~Poly() {
            delete [] terms;
        }


    Poly operator+(Poly &p);
    friend istream & operator>>(istream &is, Poly &p);
    friend ostream & operator<<(ostream &os, Poly &p);
};

istream & operator>>(istream &is, Poly &p)
{
    for (int i = 0; i < p.num; ++i) {
        cout << "Enter The Term No : (" << i + 1 << ") ";
        cin >> p.terms[i].coff >> p.terms[i].exp;
    }

    return is;
}

ostream & operator<<(ostream &os, Poly &p)
{
    cout << "Polynomail Is : ";
    for (int i = 0; i < p.num; ++i) {
        cout << p.terms[i].coff <<"x^"<<p.terms[i].exp;
        if (i < p.num - 1) {
            cout << " + ";
        }
    }

    cout << endl;

    return os;
}

Poly Poly::operator+(Poly &p) {
    Poly *sum = new Poly(num + p.num);

    int i = 0, j = 0, k = 0;

    while (i < num && j < p.num) {
        if (terms[i].exp > p.terms[j].exp) {
            sum->terms[k++] = terms[i++];
        } else if (p.terms[j].exp > terms[i].exp) {
            sum->terms[k++] = p.terms[j++];
        } else {
            sum->terms[k].exp = terms[i].exp;
            sum->terms[k++].coff = terms[i++].coff + p.terms[j++].coff;
        }
    }

    // copy the remaning elements //
    for (; i < num; ++i) {
        sum->terms[k++] = terms[i];
    }

    for (; j < p.num; ++j) {
        sum->terms[k++] = p.terms[j];
    }

    sum->num = k;

    return *sum;
}

int main() {

    Poly p1(5);
    Poly p2(3);

    cout << "Enter The Terms (coefficient And Exponent Of First Polynomials : )\n";
    cin >> p1;
    cout << "Enter The Terms (coefficient And Exponent Of Second Polynomials : )\n";
    cin >> p2;

    Poly sum = p1 + p2;

    cout << "First " << p1 << endl;
    cout << "Second " << p2 << endl;

    cout << "The Sum Of Two " << sum << endl;


    return 0;
}