#include <iostream>
#include <string>

using namespace std;

int main() {
    string userID, password;
    string enteredUserID, enteredPassword;
    char option;
    double account = 0.0;  // Initial account balance
    double amount;
    bool loggedIn = false;

    cout << "Hi! Welcome to the ATM Machine!" << endl;

    while (true) {
        if (!loggedIn) {
            cout << "\nPlease select an option from the menu below:" << endl;
            cout << "l -> Login" << endl;
            cout << "c -> Create New Account" << endl;
            cout << "q -> Quit" << endl;
           // cout << "For Example" << endl;
            cout << "> ";
            cin >> option;

            if (option == 'c') {
                cout << "Please enter your user name: ";
                cin >> userID;
                cout << "Please enter your password: ";
                cin >> password;
                cout << "Thank You! Your account has been created!" << endl;
            } else if (option == 'l') {
                cout << "Please enter your user id: ";
                cin >> enteredUserID;
                cout << "Please enter your password: ";
                cin >> enteredPassword;

                if (enteredUserID == userID && enteredPassword == password) {
                    loggedIn = true;
                    cout << "Access Granted!" << endl;
                } else {
                    cout << "*** LOGIN FAILED! ***" << endl;
                }
            } else if (option == 'q') {
                cout << "Goodbye!" << endl;
                break;
            } else {
                cout << "Invalid option, please try again." << endl;
            }
        } else {
            cout << "\nd -> Deposit Money" << endl;
            cout << "w -> Withdraw Money" << endl;
            cout << "r -> Request Balance" << endl;
            cout << "q -> Quit" << endl;
            cout << "> ";
            cin >> option;

            if (option == 'd') {
                cout << "Amount of deposit: $";
                cin >> amount;
                if (amount > 0) {
                    account += amount;
                    cout << "Deposit successful!" << endl;
                } else {
                    cout << "Invalid deposit amount!" << endl;
                }
            } else if (option == 'w') {
                cout << "Amount of withdrawal: $";
                cin >> amount;
                if (amount > 0 && amount <= account) {
                    account -= amount;
                    cout << "Withdrawal successful!" << endl;
                } else if (amount > account) {
                    cout << "Insufficient funds!" << endl;
                } else {
                    cout << "Invalid withdrawal amount!" << endl;
                }
            } else if (option == 'r') {
                cout << "Your balance is $" << account << "." << endl;
            } else if (option == 'q') {
                cout << "Goodbye!" << endl;
                break;
            } else {
                cout << "Invalid option, please try again." << endl;
            }
        }
    }

    return 0;
}

