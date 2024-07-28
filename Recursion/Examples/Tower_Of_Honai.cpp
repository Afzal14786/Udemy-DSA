#include <iostream>
using namespace std;

void tower(int disk, int towerA, int towerB, int towerC) {
    if (disk > 0) {
        tower(disk - 1, towerA, towerC, towerB);
        cout << "(" << towerA << ", " << towerC << ")" << "   ";
        tower(disk-1, towerB, towerA, towerC);
    }
}

void tower(int disk, char towerA, char towerB, char towerC) {
    if (disk > 0) {
        tower(disk - 1, towerA, towerC, towerB);
        cout << "(" << towerA << ", " << towerC << ")" << "   ";
        tower(disk-1, towerB, towerA, towerC);
    }
}
int main() {

    tower(3, 1,2,3);
    cout << endl;
    tower(3, 'A', 'B', 'C');
    cout << endl;
    return 0;
}