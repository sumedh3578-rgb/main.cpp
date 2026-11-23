
#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    int accountNumber;
    string accountHolder;
    double balance;

public:
    // Constructor
    BankAccount(int accNo, string name, double bal)
    {
        accountNumber = accNo;
        accountHolder = name;
        balance = bal;
    }

    // Deposit function
    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance = balance + amount;
            cout << "Amount deposited: " << amount << endl;
        }
        else
        {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    // Withdraw function
    void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance = balance - amount;
            cout << "Amount withdrawn: " << amount << endl;
        }
        else
        {
            cout << "Insufficient balance or invalid amount!" << endl;
        }
    }

    // Display function
    void display()
    {
        cout << "\nAccount Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main()
{
    // Creating two objects
    BankAccount acc1(101, "Rahul", 5000);
    BankAccount acc2(102, "Priya", 8000);

    cout << "----- Account 1 -----" << endl;
    acc1.display();

    acc1.deposit(2000);
    acc1.withdraw(1000);
    acc1.display();

    cout << "\n----- Account 2 -----" << endl;
    acc2.display();

    acc2.deposit(1500);
    acc2.withdraw(2000);
    acc2.display();

    return 0;
}
