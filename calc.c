#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LEN 50

int main() {
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+{}[];:,.<>?";
    int len, i, j, n;
    char password[MAX_LEN + 1];
    int complexity;

    printf("Enter the length of the password: ");
    scanf("%d", &len);

    printf("Enter the complexity level (1-3): ");
    scanf("%d", &complexity);

    srand(time(NULL));

    for (i = 0; i < len; i++) {
        n = rand() % (strlen(charset));
        if (complexity == 1) {
            while (!((n >= 0 && n <= 25) || (n >= 26 && n <= 51))) {
                n = rand() % (strlen(charset));
            }
        } else if (complexity == 2) {
            while (!((n >= 0 && n <= 25) || (n >= 26 && n <= 51) || (n >= 52 && n <= 61))) {
                n = rand() % (strlen(charset));
            }
        } else if (complexity == 3) {
            while (!((n >= 0 && n <= 25) || (n >= 26 && n <= 51) || (n >= 52 && n <= 61) || (n >= 62 && n <= 69))) {
                n = rand() % (strlen(charset));
            }
        }
        password[i] = charset[n];
    }
    password[len] = '\0';

    printf("Generated Password: %s\n", password);

    return 0;
}
