#include <stdio.h>

int main() {
    char s[] = "Welcome";

    int length;

    for (int i = 0; s[i] != '\0'; i++) {
        length++;
    }

    printf("Length Of The String Is %d :\n", length);
}