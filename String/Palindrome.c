#include <stdio.h>

void palindrome(char *ch) {
    char temp;
    int i, j;

    for (j = 0; ch[j] != '\0'; j++) {
    }

    j -= 1;

    for (i = 0; i < j; i++, j--) {
        if (ch[i] == ch[j]) {
            printf("Palindrome\n");
        } else {
            printf("Not A Palindrome\n");
        }
    }
}


int main() {
    // Palindrome //

    char str[] = "MADAM";
    // char palindrome[100];

    // step 1 -> Reverse The Array And Store A Copy Of It //

    palindrome(str);
    // int i, j;

    // for (i = 0; str[i] != '\0'; i++) {
    // }
    // i -= 1;

    // for (j = 0; i >= 0; j++, i--) {
    //     palindrome[j] = str[i];
    // }
    // palindrome[j] = '\0';
    // printf("%s\n", str);
    // printf("%s\n", palindrome);

    // // now comparying the strings //

    // for (i = 0, j = 0; str[i] != '\0' && palindrome[j] != '\0'; j++, i++) {
    //     if (str[i] == palindrome[j]) {
    //         printf("It's A Palindrome\n");
    //     } else {
    //         printf("Not A Palindrome\n");
    //     }
    // }

}