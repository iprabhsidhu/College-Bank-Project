#pragma once

#include <stdio.h>
#include <stdbool.h>

// Define account type constants
#define SAVING 1
#define BUSINESS 2
#define PERSONAL 3

// Define the Bank struct
typedef struct Bank {
    char name[50];
    int age;
    int accnumber;
    float balance;
    int pin;
    int accountType;
} Bank;

// Function prototypes
void SignUp(Bank* bank);
void menu(Bank* bank);
bool isPin(const Bank* bank, int pin);
int getBalance(const Bank* bank);
void withdraw(Bank* bank, float amount);
void deposit(Bank* bank, float amount);
void accinfo(const Bank* bank);
int generateNumber(int length);


