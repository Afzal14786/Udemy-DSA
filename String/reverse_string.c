#include <stdio.h>


void reverse_method1(char *name) {
    char reverse[1024];

    int i, j;

    for (i = 0; name[i] != '\0'; i++) {
    }

    i -= 1;

    for (j = 0; i >= 0; i--, j++) {
        reverse[j] = name[i];
    }
    reverse[j] = '\0';
    printf("Method 1 For Reversing A String. %s\n", reverse);
}

void reverse_method2(char *value) {
    char swap;

    int i, j;
    for (j = 0; value[j] != '\0'; j++) {

    }
    j -= 1;

    // swaping the character's //
    for (i = 0; i < j; i++, j--) {
        swap = value[i];
        value[i] = value[j];
        value[j] = swap;
    }
}

int main() {
    // reverse a string //

    char name[1000];
    printf("Enter Your Name : ");
    scanf("%s", name);
    
    char course[1000];
    printf("Enter Your Course : ");
    scanf("%s", course);


    // method 2 for reverse a string //
    reverse_method1(name);
    reverse_method2(course);
    printf("Method 2 For Reverse A String : %s\n", course);
    

    // method 2 for reversing a string //
    


}
