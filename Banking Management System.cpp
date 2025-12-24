#include <iostream>
#include <string>
using namespace std;

struct Account {
    int accountNumber;
    string name;
    string type;
    double balance;
    double loan;
    string lastTransaction;
};

int main() {
    Account accounts[100];
    int totalAccounts = 0;
    int choice;

    do {
        cout << "\n===== Simple Banking System =====\n";
        cout << "1. Create Account\n2. Display Account\n3. Deposit Money\n4. Withdraw Money\n5. Take Loan\n6. Pay Loan\n7. Show All Accounts\n8. Exit\n9. Access Account by Relative\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if(choice == 1) {
            cout << "Enter Account Number: ";
            cin >> accounts[totalAccounts].accountNumber;
            cin.ignore();
            cout << "Enter Name: ";
            getline(cin, accounts[totalAccounts].name);
            cout << "Enter Account Type (Savings/Current/Student): ";
            cin >> accounts[totalAccounts].type;
            cout << "Enter Initial Balance: ";
            cin >> accounts[totalAccounts].balance;
            accounts[totalAccounts].loan = 0;
            accounts[totalAccounts].lastTransaction = "Account Created";
            totalAccounts++;
            cout << "Account Created Successfully!\n";
        }
        else if(choice == 2) {
            int num, found = 0;
            cout << "Enter Account Number: ";
            cin >> num;
            for(int i=0; i<totalAccounts; i++) {
                if(accounts[i].accountNumber == num) {
                    cout << "\nAccount Number: " << accounts[i].accountNumber;
                    cout << "\nName: " << accounts[i].name;
                    cout << "\nType: " << accounts[i].type;
                    cout << "\nBalance: " << accounts[i].balance;
                    cout << "\nLoan: " << accounts[i].loan;
                    cout << "\nLast Transaction: " << accounts[i].lastTransaction << "\n";
                    found = 1;
                }
            }
            if(!found) cout << "Account Not Found!\n";
        }
        else if(choice == 3) {
            int num, found = 0;
            double amt;
            cout << "Enter Account Number: ";
            cin >> num;
            for(int i=0; i<totalAccounts; i++) {
                if(accounts[i].accountNumber == num) {
                    cout << "Enter Amount to Deposit (min 500): ";
                    cin >> amt;
                    if(amt < 500) {
                        cout << "Deposit must be at least 500!\n";
                    } else {
                        accounts[i].balance += amt;
                        accounts[i].lastTransaction = "Deposited: " + to_string(amt);
                        cout << "Deposit Successful!\n";
                    }
                    found = 1;
                }
            }
            if(!found) cout << "Account Not Found!\n";
        }
        else if(choice == 4) {
            int num, found = 0;
            double amt;
            cout << "Enter Account Number: ";
            cin >> num;
            for(int i=0; i<totalAccounts; i++) {
                if(accounts[i].accountNumber == num) {
                    cout << "Enter Amount to Withdraw: ";
                    cin >> amt;

                    if(accounts[i].type == "Student" && amt > 2000) {
                        cout << "Students cannot withdraw more than 2000 at a time!\n";
                    }
                    else if(accounts[i].type == "Current" && (accounts[i].balance - amt) < 1000) {
                        cout << "Cannot withdraw! Minimum balance of 1000 required.\n";
                    }
                    else if(amt <= accounts[i].balance) {
                        accounts[i].balance -= amt;
                        accounts[i].lastTransaction = "Withdrew: " + to_string(amt);
                        cout << "Withdrawal Successful!\n";
                    } else {
                        cout << "Insufficient Balance!\n";
                    }
                    found = 1;
                }
            }
            if(!found) cout << "Account Not Found!\n";
        }
        else if(choice == 5) {
            int num, found = 0;
            double loanAmt, maxLoan;
            cout << "Enter Account Number: ";
            cin >> num;
            for(int i=0; i<totalAccounts; i++) {
                if(accounts[i].accountNumber == num) {
                    if(accounts[i].type == "Student") maxLoan = 50000;
                    else if(accounts[i].type == "Savings") maxLoan = 200000;
                    else maxLoan = 500000;

                    cout << "Enter Loan Amount (Max " << maxLoan << "): ";
                    cin >> loanAmt;
                    if(loanAmt > maxLoan) {
                        cout << "Loan exceeds maximum allowed!\n";
                    } else {
                        accounts[i].loan += loanAmt;
                        accounts[i].balance += loanAmt;
                        accounts[i].lastTransaction = "Loan Taken: " + to_string(loanAmt);
                        cout << "Loan Granted! Balance Updated.\n";
                    }
                    found = 1;
                }
            }
            if(!found) cout << "Account Not Found!\n";
        }
        else if(choice == 6) {
            int num, found = 0;
            double payAmt;
            cout << "Enter Account Number: ";
            cin >> num;
            for(int i=0; i<totalAccounts; i++) {
                if(accounts[i].accountNumber == num) {
                    cout << "Your current loan: " << accounts[i].loan << "\n";
                    cout << "Enter amount to pay: ";
                    cin >> payAmt;
                    if(payAmt > accounts[i].loan) {
                        cout << "Cannot pay more than loan!\n";
                    } else if(payAmt > accounts[i].balance) {
                        cout << "Insufficient balance to pay!\n";
                    } else {
                        accounts[i].loan -= payAmt;
                        accounts[i].balance -= payAmt;
                        accounts[i].lastTransaction = "Loan Paid: " + to_string(payAmt);
                        cout << "Loan payment successful! Remaining loan: " << accounts[i].loan << "\n";
                    }
                    found = 1;
                }
            }
            if(!found) cout << "Account Not Found!\n";
        }
        else if(choice == 7) {
            cout << "\n===== All Accounts =====\n";
            for(int i=0; i<totalAccounts; i++) {
                cout << "Account#: " << accounts[i].accountNumber
                     << " | Name: " << accounts[i].name
                     << " | Type: " << accounts[i].type
                     << " | Balance: " << accounts[i].balance
                     << " | Loan: " << accounts[i].loan
                     << " | Last Transaction: " << accounts[i].lastTransaction << "\n";
            }
            if(totalAccounts == 0) cout << "No accounts to show.\n";
        }
        else if(choice == 8) {
            char confirm;
            cout << "Are you sure you want to exit? (y/n): ";
            cin >> confirm;
            if(confirm == 'y' || confirm == 'Y') break;
        }
        else if(choice == 9) {
            int num, found = 0;
            string relative;
            cout << "Enter Account Number: ";
            cin >> num;
            cin.ignore();
            for(int i=0; i<totalAccounts; i++) {
                if(accounts[i].accountNumber == num) {
                    cout << "Enter Relative Name: ";
                    getline(cin, relative);
                    cout << "Access Granted to Relative: " << relative << "\n";
                    int relChoice;
                    cout << "1. Deposit\n2. Withdraw\n3. Take Loan\nEnter Choice: ";
                    cin >> relChoice;
                    double amt, maxLoan;
                    if(relChoice == 1) {
                        cout << "Enter Amount to Deposit (min 500): ";
                        cin >> amt;
                        if(amt < 500) cout << "Deposit must be at least 500!\n";
                        else {
                            accounts[i].balance += amt;
                            accounts[i].lastTransaction = "Deposited by relative " + relative + ": " + to_string(amt);
                            cout << "Deposit Successful!\n";
                        }
                    }
                    else if(relChoice == 2) {
                        cout << "Enter Amount to Withdraw: ";
                        cin >> amt;
                        bool allowed = true;
                        if(accounts[i].type == "Student" && amt > 2000) {
                            cout << "Students cannot withdraw more than 2000 at a time!\n";
                            allowed = false;
                        }
                        else if(accounts[i].type == "Current" && (accounts[i].balance - amt) < 1000) {
                            cout << "Cannot withdraw! Minimum balance must be maintained.\n";
                            allowed = false;
                        }
                        else if(amt > accounts[i].balance) {
                            cout << "Insufficient balance!\n";
                            allowed = false;
                        }
                        if(allowed) {
                            accounts[i].balance -= amt;
                            accounts[i].lastTransaction = "Withdrawn by relative " + relative + ": " + to_string(amt);
                            cout << "Withdrawal Successful!\n";
                        }
                    }
                    else if(relChoice == 3) {
                        if(accounts[i].type == "Student") maxLoan = 50000;
                        else if(accounts[i].type == "Savings") maxLoan = 200000;
                        else maxLoan = 500000;
                        cout << "Enter Loan Amount (Max " << maxLoan << "): ";
                        cin >> amt;
                        if(amt > maxLoan) cout << "Loan exceeds maximum allowed!\n";
                        else {
                            accounts[i].loan += amt;
                            accounts[i].balance += amt;
                            accounts[i].lastTransaction = "Loan Taken by relative " + relative + ": " + to_string(amt);
                            cout << "Loan Granted! Balance Updated.\n";
                        }
                    }
                    else {
                        cout << "Invalid Choice!\n";
                    }
                    found = 1;
                }
            }
            if(!found) cout << "Account Not Found!\n";
        }
        else {
            cout << "Invalid Choice!\n";
        }

    } while(true);

    cout << "Exiting Banking System. Goodbye!\n";
    return 0;
}