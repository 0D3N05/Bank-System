#include "includes\Bank.h"
using namespace std;

// Defining method here

// This maybe will be ask in interview so better prepare lah
Bank::Bank(string name) : Bank_name(name), head(nullptr), total_cust(0) {}

bool Bank::AccountExists(int accNum)
{
    Node *temp = head;
    while (temp)
    {
        if (temp->Account_Number == accNum)
            return true;
        temp = temp->next;
    }
    return false;
}

void Bank::New_Acc(string Customer_Name, int Account_Number, double Account_balance)
{
    if (AccountExists(Account_Number))
    {
        cout << "Account number already exists. Cannot create duplicate.\n";
        return;
    }

    Node *newAcc = new Node{Customer_Name, Account_Number, Account_balance, nullptr};
    if (!head)
    {
        head = newAcc;
    }
    else
    {
        Node *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newAcc;
    }
    total_cust++;
    cout << "Account created successfully.\n";
}

void Bank::Display_All()
{
    if (!head)
    {
        cout << "No accounts to display.\n";
        return;
    }
    Node *temp = head;
    while (temp)
    {
        cout << "Name: " << temp->Customer_Name
             << ", Account : " << temp->Account_Number
             << ", Balance: RM" << temp->Account_Balance << endl;
        temp = temp->next;
    }
}

void Bank::Search_Acc(int accNum)
{
    Node *temp = head;
        if (temp->Account_Number == accNum)
        {
            cout << "Account found:\n"
                 << "Name: " << temp->Customer_Name
                 << ", Balance: RM" << temp->Account_Balance << endl;
            return;
        }
        temp = temp->next;

}

void Bank::Update_Balance(int accNum, double amount, bool Depo)
{
    Node *temp = head;
    while (temp)
    {
        if (temp->Account_Number == accNum)
        {
            if (Depo)
            {
                temp->Account_Balance += amount;
                cout << "Deposited RM" << amount << ". New balance: RM" << temp->Account_Balance << endl;
            }
            else
            {
                if (temp->Account_Balance >= amount)
                {
                    temp->Account_Balance -= amount;
                    cout << "Withdrew RM" << amount << ". New balance: RM" << temp->Account_Balance << endl;
                }
                else
                {
                    cout << "Insufficient balance.\n";
                }
            }
            return;
        }
        temp = temp->next;
    }
    cout << "Account not found.\n";
}

void Bank::Delete_Acc(int accNum)
{
    Node *temp = head;
    Node *prev = nullptr;

    while (temp)
    {
        if (temp->Account_Number == accNum)
        {
            if (prev)
                prev->next = temp->next;
            else
                head = temp->next;

            delete temp;
            total_cust--;
            cout << "Account deleted successfully.\n";
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "Account not found.\n";
}