#include <stdio.h>

int main() {
    // count the number of words //
    // eg : How Are You // No Of Words = 3 //

    char ch[] = "How Are You";
    int word_count = 1;
    for (int i = 0; ch[i] != '\0'; i++) {
        if (ch[i] == ' ' && ch[i-1] != ' ') {
            word_count++;
        }
    }

    printf("Number Of Words : %d\n", word_count);
}