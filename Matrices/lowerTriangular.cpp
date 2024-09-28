#include <iostream>
using namespace std;

class Lower_Triangular_Matrix {
    private:
        int *array;
        int size;

    public:
        Lower_Triangular_Matrix(int size) {
            this->size = size;

            // total number of elements are required to store in array : (size + (size + 1) / 2);
            array = new int[size * (size + 1)/2];
        }

        void Set(int row, int cols, int value);
        int Get(int row, int cols);

        void Display();

        ~Lower_Triangular_Matrix() {
            delete []array;
        }
};

void Lower_Triangular_Matrix :: Set(int row, int cols, int value) {
    if (row >= cols) {

        // using row major formula //
        array[(row * (row - 1)) / 2 + (cols - 1)] = value;
    }
}

int Lower_Triangular_Matrix :: Get(int row, int cols) {
    if (row >= cols) {
        // using row-major formula
        return array[(row * (row - 1))/2 + (cols - 1)];
    }

    return 0;
}

void Lower_Triangular_Matrix :: Display() {
    for (int i = 1; i <= size; ++i) {
        for (int j = 1; j <= size; ++j) {
            if (i >= j) {
                cout << array[(i * (i - 1)) / 2 + (j - 1)] << " ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

int main() {

    int dimension;
    int value;
    cout << "Enter The Dimension Of The Array : ";
    cin >> dimension;


    Lower_Triangular_Matrix LT(dimension);
    cout << "Enter All The Elements : " << endl;
    for (int i = 1; i <= dimension; ++i) {
        for (int j = 1; j <= dimension; ++j) {
            cin >> value;
            LT.Set(i, j, value);
        }
    }
    LT.Display();

    cout << LT.Get(2,2) << endl;

    return 0;
}

