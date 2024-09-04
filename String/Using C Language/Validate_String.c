#include <stdio.h>

int valid_name(char *user_name) {
    for (int i = 0; user_name[i] != '\0'; i++) {
        if (!(user_name[i] >= 65 && user_name[i] <= 90) && !(user_name[i] >= 97 && user_name[i] <= 122) && !(user_name[i] >= 48 && user_name[i] <= 57)) {
            return 0;
        }
    }

    return 1;
}

int main() {
    
    char user_name[1024];
    printf("Enter A User Name : ");
    scanf("%s", user_name);

    
    if (valid_name(user_name)) {
        printf("Valid User Id.\n");
    } else {
        printf("Please Enter A Valid User Id.\n");
    }


}