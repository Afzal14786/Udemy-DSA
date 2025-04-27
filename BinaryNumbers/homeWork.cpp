#include <iostream>
#include <math.h>
using namespace std;

int binaryToDecimal(int binary) {
    int result = 0;
    int position = 0;
    while (binary > 0) {
        int lastDigit = binary % 10;
        result += lastDigit * pow(2, position);
        position++;
        binary /= 10;
    }

    return result;
}

int decimalToBinary(int decimal) {
    int result = 0;
    int position = 0;

    while (decimal > 0) {
        int reminder = decimal % 2;
        result += reminder * pow(10, position);
        position++;
        decimal /= 2;
    }

    return result;
}

int main() {

    cout << "Decimal From Of 111 : "<< binaryToDecimal(111) << endl;
    cout << "Binary Form Of 7 : " << decimalToBinary(7) << endl;
    return 0;
}