#include <iostream>
using namespace std;

class Diagonal {
    private:
        int n;
        int *array;

    public:

        Diagonal(int n) {
            this->n = n;
            array = new int[n];
        }

        void Set(int row, int cols, int value);
        int Get(int row, int cols);
        void Display();

        ~Diagonal() {
            delete []array;
        }
};

void Diagonal :: Set(int row, int cols, int value) {
    if (row == cols) {
        array[row - 1] = value;
    }
}

int Diagonal :: Get(int row, int cols) {
    if (row == cols) {
        return array[row - 1];
    }
    return 0;
}

void Diagonal :: Display() {
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            if (i == j) {
                cout << array[i - 1] << " ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

int main() {

    Diagonal D(5);
    // D.Set(0,0,5);
    // D.Set(1,1,10);
    // D.Set(2,2,20);
    // D.Set(3,3,30);
    // D.Set(4,4,40);

    for (int i = 1; i < 5; ++i) {
        for (int j = 1; j < 5; ++j) {
            if (i == j) {
                D.Set(i,j, (i*j));
            } else {
                D.Set(i,j,0);
            }
        }
    }

    D.Display();

    return 0;
}