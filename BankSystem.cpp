#include <iostream>
#include <limits>
#include <windows.h>
#include <stdexcept> // for std::invalid_argument
#include "includes\Bank.h"
#include "includes\PrintUI.h"
using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    int choice, Account_Number;
    string bank_name, Customer_Name;
    double Account_balance;

    Customization("Welcome to the Bank System! Please enter your bank name (or type 'exit' to quit): ");
    getline(cin, bank_name);

    do
    {
        if (bank_name == "exit")
        {
            Customization("Exiting system. Goodbye!");
            return 0;
        }

        Bank temp(bank_name);
        cout << "Welcome to " << bank_name << " Bank!" << endl;

        // Menu Loop
        do
        {
            try
            {
                cout << "\nWhat do you want to do?\n"
                     << " 1. Add a new account\n"
                     << " 2. Display all accounts\n"
                     << " 3. Search by account number\n"
                     << " 4. Deposit and withdraw\n"
                     << " 5. Delete an account\n"
                     << " 6. Exit the system\n"
                     << "Enter your choice: ";

                cin >> choice;

                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw invalid_argument("Invalid input. Please enter a number between 1 and 6.");
                }

                if (choice < 1 || choice > 6)
                {
                    throw invalid_argument("Invalid choice. Please enter a number between 1 and 6.");
                }

                // Valid input, proceed with switch
                switch (choice)
                {
                case 1:
        
                try {
                    // Validate name input
                    cout << "Please Enter Your Name: ";
                    cin.ignore();
                    getline(cin, Customer_Name);
                    if (Customer_Name.empty()) {
                        throw invalid_argument("Name cannot be empty. Please enter a valid name.");
                    } 

                    // Validate account number input
                    while (true) {
                        cout << "Please Enter Your Account Number: ";
                        cin >> Account_Number;

                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Invalid input. Please enter a real number for account number.\n";
                        } else {
                            if (Account_Number <= 0) {
                            throw invalid_argument("Account number must be a positive integer. Please enter a valid account number.");
                            }
                            break;
                        }
                        
                    }

                    // check if account is interger
                    while (true) {
                        cout << "Please Enter Your Balance: ";
                        cin >> Account_balance;

                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Invalid input. Please enter a real number for balance.\n";
                        } else {
                            break;
                        }
                    
                    }

                    temp.New_Acc(Customer_Name, Account_Number, Account_balance);
                }
                catch (const invalid_argument& e) {
                    cout << e.what() << endl;
                }
                break;

                case 2:
                    printLine('-', 100);
                    temp.Display_All();
                    printLine('-', 100);
                    break;

                case 3:
                try {
                    cout << "Enter Account Number to search: ";
                    cin >> Account_Number;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        throw invalid_argument("Invalid account number. Please enter real number.");
                    }
                    temp.Search_Acc(Account_Number);
                }
                catch (const invalid_argument& e) {
                    cout << e.what() << endl;
                }
                break;

                case 4:
                    int action;
                    try {
                        // Validate account number
                        while (true) {
                            cout << "Enter Account Number: ";
                            cin >> Account_Number;

                            if (cin.fail()) {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                throw invalid_argument("Invalid input. Please enter a real number for account number.");
                            }
                            if (Account_Number <= 0) {
                                throw invalid_argument("Account number must be a positive integer.");
                            }
                            break;
                        }

                        // Validate action
                        while (true) {
                            cout << "Choose action: 1 for Deposit, 2 for Withdraw: ";
                            cin >> action;

                            if (cin.fail()) {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                throw invalid_argument("Invalid input. Please enter 1 or 2.");
                            }
                            if (action != 1 && action != 2) {
                                throw invalid_argument("Invalid choice. Please enter 1 for Deposit or 2 for Withdraw.");
                            }
                            break;
                        }

                        // Validate amount
                        while (true) {
                            cout << "Enter amount: ";
                            cin >> Account_balance;

                            if (cin.fail()) {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                throw invalid_argument("Invalid input. Please enter a real number for amount.");
                            }
                            break;
                        }

                        temp.Update_Balance(Account_Number, Account_balance, action == 1);
                    }
                    catch (const invalid_argument& e) {
                        cout << e.what() << endl;
                    }
                    break;

                    case 5:
                    try {
                        while (true) {
                            cout << "Please Enter Your Account Number: ";
                            cin >> Account_Number;

                            if (cin.fail()) {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cout << "Invalid input. Please enter a real number for account number.\n";
                            } else {
                                if (Account_Number <= 0) {
                                    throw invalid_argument("Account number must be a positive integer. Please enter a valid account number.");
                                }
                                break;
                            }
                        }

                        temp.Delete_Acc(Account_Number);
                    }
                    catch (const invalid_argument& e) {
                        cout << e.what() << endl;
                    }
                    break;

                case 6:
                    cout << "Exiting the system. Goodbye!" << endl;
                    return 0;
                }
            }
            catch (const invalid_argument& e) {
                cout << e.what() << endl;
            }
        } while (choice != 6);

    } while (true); // Loop until user enters "exit" for bank name

    return 0;
}
