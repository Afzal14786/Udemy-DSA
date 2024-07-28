#include <stdio.h>

int main() {
    char name[] = "Afzal";

    int vcount, ccount;

    for (int i = 0; name[i] != '\0'; i++) {
        if (name[i] == 'a' || name[i] == 'A' || name[i] == 'e' || name[i] == 'E' || name[i] == 'i' || name[i] == 'I' || name[i] == 'o' || name[i] == 'O' || name[i] == 'u' || name[i] == 'U') {
            vcount++;
        } else if ((name[i] >= 65 && name[i] <= 90) || (name[i] >= 97 && name[i] <= 122)) {
            ccount++;
        }
    }

    printf("Number Of Vowel's : %d\n", vcount);
    printf("Number Of Consonents : %d\n", ccount);
}