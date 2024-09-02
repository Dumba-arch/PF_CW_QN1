#include <iostream>
#include <string>

using namespace std;

struct Account {
    string userID;
    string password;
    double balance;
};

Account account; // Global account structure

void createAccount() {
    cout << "Please enter your user id: ";
    cin >> account.userID;
    cout << "Please enter your password: ";
    cin >> account.password;
    account.balance = 0.0;
    cout << "Thank you! Your account has been created!\n";
}

bool login() {
    string inputUserID, inputPassword;
    cout << "Please enter your user id: ";
    cin >> inputUserID;
    cout << "Please enter your password: ";
    cin >> inputPassword;

    if (inputUserID == account.userID && inputPassword == account.password) {
        cout << "Access Granted!\n";
        return true;
    } else {
        cout << "*** LOGIN FAILED! ***\n";
        return false;
    }
}

void withdraw() {
    double amount;
    cout << "Amount of withdrawal: $";
    cin >> amount;

    if (amount > account.balance) {
        cout << "Insufficient funds.\n";
    } else {
        account.balance -= amount;
        cout << "Withdrawal successful. Your new balance is $" << account.balance << ".\n";
    }
}

void deposit() {
    double amount;
    cout << "Amount of deposit: $";
    cin >> amount;

    account.balance += amount;
    cout << "Deposit successful. Your new balance is $" << account.balance << ".\n";
}

void requestBalance() {
    cout << "Your balance is $" << account.balance << ".\n";
}

int main() {
    char option;

    cout << "Hi! Welcome to the ATM Machine!\n";

    while (true) {
        cout << "Please select an option from the menu below:\n";
        cout << "l -> Login\n";
        cout << "c -> Create New Account\n";
        cout << "q -> Quit\n";
        cout << "> ";
        cin >> option;

        if (option == 'q') {
            cout << "Thank you for using the ATM Machine. Goodbye!\n";
            break;
        } else if (option == 'c') {
            createAccount();
        } else if (option == 'l') {
            if (login()) {
                char subOption;
                while (true) {
                    cout << "d -> Deposit Money\n";
                    cout << "w -> Withdraw Money\n";
                    cout << "r -> Request Balance\n";
                    cout << "q -> Quit\n";
                    cout << "> ";
                    cin >> subOption;

                    if (subOption == 'd') {
                        deposit();
                    } else if (subOption == 'w') {
                        withdraw();
                    } else if (subOption == 'r') {
                        requestBalance();
                    } else if (subOption == 'q') {
                        break;
                    } else {
                        cout << "Invalid option. Please try again.\n";
                    }
                }
            }
        } else {
            cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}

