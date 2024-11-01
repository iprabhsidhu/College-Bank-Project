#include "Bank.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// Global instance of Bank
Bank accinstance;

// Function to initialize account
void SignUp(Bank *bank) {
    printf("Name: ");
    scanf("%49s", bank->name);

    while (1) {
        printf("Age: ");
        scanf("%d", &bank->age);
        if (bank->age >= 18) break;
        printf("You must be at least 18 years old to create an account.\n");
    }

    bank->accnumber = generateNumber(16);
    bank->pin = generateNumber(4);
    printf("Account Number: %d\n", bank->accnumber);
    printf("Account PIN: %d\n", bank->pin);

    printf("Deposit (0 for nothing): ");
    scanf("%f", &bank->balance);

    printf("Account Type\n1. Saving\n2. Business\n3. Personal\n >>> ");
    int type;
    scanf("%d", &type);

    if (type == SAVING) bank->accountType = SAVING;
    else if (type == BUSINESS) bank->accountType = BUSINESS;
    else if (type == PERSONAL) bank->accountType = PERSONAL;
    else printf("Invalid account type selected. Defaulting to Personal.\n");

    menu(bank);
}

// Main menu function
void menu(Bank *bank) {
    printf("\nWelcome to Shadow Bank\n1. Withdraw\n2. Deposit\n3. Check Balance\n4. Account Information\n>>> ");
    int opt, pin;
    scanf("%d", &opt);

    printf("Enter PIN: ");
    scanf("%d", &pin);
    
    if (isPin(bank, pin)) {
        float amount = 0.0f;
        switch (opt) {
            case 1:
                printf("Amount: ");
                scanf("%f", &amount);
                withdraw(bank, amount);
                break;
            case 2:
                printf("Amount: ");
                scanf("%f", &amount);
                deposit(bank, amount);
                break;
            case 3:
                printf("Current Balance: %.2f\n", getBalance(bank));
                break;
            case 4:
                accinfo(bank);
                break;
            default:
                printf("Invalid option selected.\n");
        }
    } else {
        printf("Incorrect PIN.\n");
    }
}

// Function to check if PIN is correct
bool isPin(const Bank *bank, int pin) {
    return bank->pin == pin;
}

// Retrieve balance
int getBalance(const Bank *bank) {
    return (int)bank->balance;
}

// Withdraw money
void withdraw(Bank *bank, float amount) {
    if (amount > bank->balance) {
        printf("Insufficient balance.\n");
    } else {
        bank->balance -= amount;
        printf("New Balance: %.2f\n", bank->balance);
    }
    menu(bank);
}

// Deposit money
void deposit(Bank *bank, float amount) {
    bank->balance += amount;
    printf("New Balance: %.2f\n", bank->balance);
    menu(bank);
}

// Display account information
void accinfo(const Bank *bank) {
    printf("Name: %s\n", bank->name);
    printf("Account Number: %d\n", bank->accnumber);
    printf("PIN: %d\n", bank->pin);
    printf("Balance: %.2f\n", bank->balance);
    printf("Account Type: ");
    switch (bank->accountType) {
        case SAVING:
            printf("Saving\n");
            break;
        case BUSINESS:
            printf("Business\n");
            break;
        case PERSONAL:
            printf("Personal\n");
            break;
        default:
            printf("Unknown\n");
    }
}

// Generate a random number of specified length
int generateNumber(int length) {
    if (length > 9) length = 9;  // Ensure length is manageable for int range

    srand((unsigned int)time(0));
    
    int lowerBound = (int)pow(10, length - 1);
    int upperBound = (int)pow(10, length) - 1;
    
    return rand() % (upperBound - lowerBound + 1) + lowerBound;
}


int main() {
    SignUp(&accinstance);
    return 0;
}

