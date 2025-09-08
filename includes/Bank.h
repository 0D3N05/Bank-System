// Bank class header file

#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <string>
using namespace std;

struct Node
{
    // Node for linked list
    string Customer_Name;
    int Account_Number;
    double Account_Balance;
    Node *next;
};

class Bank
{
private:
    // Attributes duh..
    string Bank_name;
    Node *head;
    int total_cust;

public:
    // Declaring method here
    Bank(string name = "Maybank");
    bool AccountExists(int accNum);                                                     // Check if account number already exists
    void New_Acc(string Customer_Name, int Account_Number, double Account_balance = 0); // Create new account
    void Display_All();                                                                 // Display all accounts
    void Search_Acc(int accNum);                                                        // Search account by account number
    void Update_Balance(int accNum, double amount, bool Depo);                          // Deposit or withdraw money
    void Delete_Acc(int accNum);                                                        // Delete an account
};

#endif