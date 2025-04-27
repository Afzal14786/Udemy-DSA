#include <iostream>
#include <math.h>
using namespace std;

// conversion from binary to decimal
/* return answer*/
int binaryToDecimal(int binaryNumber) {
    int n = binaryNumber;
    int power = 1;
    int ans = 0;

    while (n > 0) {
        int lastDigit = n % 10;     // getting the last number
        ans += lastDigit * power;   // multipley the last digit with the power
        power = power * 2;          // update the power 
        n = n / 10;     // reduce the number 
    }

    return ans;
}


/* return nothing */
void binToDec(int bin) {
    int ans = 0;
    int power = 1;

    while (bin > 0) {
        int lastDigit = bin % 10;
        ans += lastDigit * power;
        power *= 2;
        bin /= 10;
    }

    cout << "Decimal Number Is : " << ans << endl;
}

/* function return the answer */
int decToBin(int dec) {
    int  binaryNum = 0;
    int power = 1;
    while (dec > 0) {
        int rem = dec % 2;      // calculate the remainder
        binaryNum += rem * power;   // multiplay the reminder with power
        dec /= 2;               // half the number 
        power *= 10;        // increase the piwer by 10
    }

    return binaryNum;
}

/* only print the answer : return nothing*/
void decimalToBinary(int decimal) {
    int result = 0;
    int power = 1;

    while (decimal > 0 ){
        int reminder = decimal % 2;
        result += reminder * power;
        power *= 10;
        decimal /= 2;
    }

    cout << "Binary Format Of The Given Decimal Number Is : " << result << endl;
}

int main() {
    cout << sizeof(int)  << " bytes" << endl;       // 4 bytes
    cout << sizeof(long int) << " bytes" << endl;   // 8 bytes
    cout << sizeof(double) << " bytes" << endl;     // 8 bytes
    cout << sizeof(long double) << " bytes" << endl; // 16 bytes
    cout << sizeof(long long int) << " bytes" << endl;  // 8 bytes
    cout << sizeof(unsigned int) << " bytes" << endl;   // 4 bytes

    binToDec(1010);
    cout << "Decimal to Binary : " << decToBin(7) << endl;
    decimalToBinary(10);
    return 0;
}