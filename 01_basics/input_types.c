#include <stdio.h>
#include <string.h> // Added for strcspn

int main() {
    int number;
    char letter;
    float decimal;

    // Read integer
    printf("Enter an integer: ");
    scanf("%d", &number);
    while (getchar() != '\n'); // Clear input buffer

    // Read character
    printf("Enter a character: ");
    scanf("%c", &letter);
    while (getchar() != '\n'); // Clear input buffer

    // Read decimal
    printf("Enter a decimal number: ");
    scanf("%f", &decimal);
    while (getchar() != '\n'); // Clear input buffer

    // Print scanf inputs
    printf("You entered: %d, %c, %.2f\n", number, letter, decimal);

    // Read single character with getchar
    printf("Enter a single character: ");
    int ch = getchar();
    printf("You entered: %c\n", ch);
    while (getchar() != '\n'); // Clear input buffer

    // Read string with fgets
    char name[50];
    printf("Enter your name (up to 49 characters): ");
    fgets(name, sizeof(name), stdin);
    // Remove trailing newline from fgets
    name[strcspn(name, "\n")] = '\0';
    printf("Your name is: %s\n", name);

    return 0;
}
