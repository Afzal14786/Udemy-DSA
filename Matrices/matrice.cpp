#include <iostream>
#include <stdio.h>
using namespace std;

class Element {
    public:
        int i;
        int j;
        int value;
};

class Sparse {
    private:
        int row_no;
        int cols_no;
        int non_zeros;

        Element *arr;

    public:
        Sparse(int row_no, int cols_no, int non_zeros) {
            this->row_no = row_no;
            this->cols_no = cols_no;
            this->non_zeros = non_zeros;

            arr = new Element[this->non_zeros];
        }

        ~Sparse() {
            delete [] arr;
        }

        Sparse operator+(Sparse &s);
        friend istream & operator>>(istream &is, Sparse &s);
        friend ostream & operator<<(ostream &os, Sparse &s);
};

istream & operator>>(istream &is, Sparse &s)
{
    cout << "Enter All non-zero elements.\n";
    for (int i = 0; i < s.non_zeros; ++i) {
        cin >> s.arr[i].i >> s.arr[i].j >> s.arr[i].value;
    }

    return is;
}

ostream & operator<<(ostream &os, Sparse &s)
{
    cout << "Here is The Matrix : \n";
    int k = 0;
    for (int i = 0; i < s.row_no; ++i) {
        for (int j = 0; j < s.cols_no; ++j) {
            if (s.arr[k].i == i && s.arr[k].j == j) {
                cout << s.arr[k++].value << " ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }

    return os;
}

// implementing the addition //
Sparse Sparse::operator+(Sparse &s1) {
    int i,j,k;

    if (row_no != s1.row_no || cols_no != s1.cols_no) {
        cout << "The Given Dimantions Are Wrongs. Kindly Run Again. \n";
        return Sparse(0,0,0);
    }

    Sparse *sum = new Sparse(row_no, cols_no, non_zeros+s1.non_zeros);

    i = j = k = 0;
    while (i < non_zeros && j < s1.non_zeros) {
        // check the conditions //

        if (arr[i].i < s1.arr[j].i) {
            sum->arr[k++] = arr[i++];
        } else if (arr[i].i > s1.arr[j].i) {
            sum->arr[k++] = s1.arr[j++];
        } else {
            if (arr[i].j < s1.arr[j].j) {
                sum->arr[k++] = arr[i++];
            } else if (arr[i].j > s1.arr[j].j) {
                sum->arr[k++] = s1.arr[j++];
            } else {
                sum->arr[k] = arr[i];
                sum->arr[k++].value = arr[i++].value + s1.arr[j++].value;
            }
        }
    }

    // copy the remaning elements from the arrays //
    for (; i < non_zeros; ++i) {
        sum->arr[k++] = arr[i];
    }

    for (; j < non_zeros; ++j) {
        sum->arr[k++] = s1.arr[j];
    }

    sum->non_zeros = k;

    return *sum;
}



int main() {

    Sparse s1(5,5,5);
    Sparse s2(5,5,5);

    cout << "Enter The Elements Of First Matrix : " << endl;
    cin >> s1;
    cout << "Enter The Elements Of Second Matrix : " << endl;
    cin >> s2;

    Sparse sum = s1 + s2;

    cout << "The First Matrix Is : " << endl << s1;
    cout << "The Second Matrix is : " << endl << s2;
    cout << "The Resultend Matrix Is : " << endl << sum;

    return 0;
}