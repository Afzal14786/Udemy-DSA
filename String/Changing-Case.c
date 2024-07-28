#include <stdio.h>

/*
    Changing Cases 
        Upper to Lower
        Lower to Upper
        Or Alternative 
*/

int main() {
    char name[] = "AFZAL";
    
    // changing upper to lower //

    for (int i = 0; name[i] != '\0'; i++) {
        name[i] += 32;
    }

    printf("%s\n", name);

    char lowerToUpper[] = "afzal";

    // Changing Lower To Upper //

    for (int i = 0; lowerToUpper[i] != '\0'; i++) {
        lowerToUpper[i] -= 32;
    }

    printf("%s\n", lowerToUpper);


    // changer alternative /

    char alternativeChar[] = "AfZaL";

    for (int i = 0; alternativeChar[i] != '\0'; i++) {
        if (alternativeChar[i] >= 65 || alternativeChar[i] <=90) {
            alternativeChar[i] += 32;
        } else if (alternativeChar[i] >= 'a' || alternativeChar[i] <= 122) {
            alternativeChar[i] = alternativeChar[i] - 32;
        }
    }

    printf("%s\n", alternativeChar);
}