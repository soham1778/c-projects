 #include <stdio.h>
#include <string.h>
#include <windows.h>

// Structure to represent a bank account
struct BankAccount {
    char accountHolderName[50];
    int accountNumber;
    float balance;
};

// Function to create a new bank account
struct BankAccount createAccount(char name[], int accNumber, float initialBalance) {
    struct BankAccount account;
    strcpy(account.accountHolderName, name);
    account.accountNumber = accNumber;
    account.balance = initialBalance;
    return account;
}

// Function to deposit money into the account
void deposit(struct BankAccount *account, float amount) {
    account->balance += amount;
    printf("Deposited %.2f. New balance: %.2f\n", amount, account->balance);
}

// Function to withdraw money from the account
void withdraw(struct BankAccount *account, float amount) {
    if (amount <= account->balance) {
        account->balance -= amount;
        printf("Withdrawn %.2f. New balance: %.2f\n", amount, account->balance);
    } else {
        printf("Insufficient funds. Withdrawal failed.\n");
    }
}

// Function to check account balance
void checkBalance(struct BankAccount *account) {
    printf("Account Balance for %s (Account #%d): %.2f\n", account->accountHolderName, account->accountNumber, account->balance);
}

int main() {
    // Example usage
    struct BankAccount myAccount = createAccount("John Doe", 123456, 1000.0);

    int choice;
    float amount;

    do {
        // Display menu
        printf("\n1. Deposit\n2. Withdraw\n3. Check Balance\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the deposit amount: ");
                scanf("%f", &amount);
                deposit(&myAccount, amount);
                break;
            case 2:
                printf("Enter the withdrawal amount: ");
                scanf("%f", &amount);
                withdraw(&myAccount, amount);
                break;
            case 3:
                checkBalance(&myAccount);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
           