#include <iostream>
#include <exception>
#include <string>

// Custom Exception for invalid input amounts (e.g., negative or zero deposit/withdrawal)
class InvalidAmountException : public std::exception {
private:
    std::string message;
public:
    explicit InvalidAmountException(const std::string& msg) : message(msg) {}
    
    const char* what() const noexcept override {
        return message.c_str();
    }
};

// Custom Exception for overdraft / insufficient funds
class InsufficientFundsException : public std::exception {
private:
    std::string message;
public:
    explicit InsufficientFundsException(const std::string& msg) : message(msg) {}
    
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class BankAccount {
private:
    int accountNumber;
    std::string accountHolder;
    double balance;

public:
    BankAccount(int accNo, std::string name, double initialBalance)
        : accountNumber(accNo), accountHolder(name), balance(initialBalance) {
        if (initialBalance < 0) {
            throw InvalidAmountException("Initial balance cannot be negative.");
        }
    }

    void deposit(double amount) {
        if (amount <= 0) {
            throw InvalidAmountException("Deposit amount must be greater than zero.");
        }
        balance += amount;
        std::cout << "Successfully deposited $" << amount << ". New Balance: $" << balance << "\n";
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            throw InvalidAmountException("Withdrawal amount must be greater than zero.");
        }
        if (amount > balance) {
            throw InsufficientFundsException("Transaction failed: Insufficient funds. Available balance: $" + std::to_string(balance));
        }
        balance -= amount;
        std::cout << "Successfully withdrew $" << amount << ". Remaining Balance: $" << balance << "\n";
    }

    void displayDetails() const {
        std::cout << "Account: #" << accountNumber 
                  << " | Holder: " << accountHolder 
                  << " | Balance: $" << balance << "\n";
    }
};

int main() {
    try {
        BankAccount acc(1001, "Alice", 500.00);
        acc.displayDetails();
        std::cout << "\n-----------------------------------\n";

        // Successful Deposit
        std::cout << "Testing Valid Deposit...\n";
        acc.deposit(200.00);

        // Successful Withdrawal
        std::cout << "\nTesting Valid Withdrawal...\n";
        acc.withdraw(150.00);

        // Failed Withdrawal (Insufficient Funds)
        std::cout << "\nTesting Insufficient Funds Exception...\n";
        try {
            acc.withdraw(1000.00);
        } catch (const InsufficientFundsException& e) {
            std::cerr << "Error: " << e.what() << "\n";
        }

        // Failed Deposit (Invalid Amount)
        std::cout << "\nTesting Invalid Amount Exception...\n";
        try {
            acc.deposit(-50.00);
        } catch (const InvalidAmountException& e) {
            std::cerr << "Error: " << e.what() << "\n";
        }

        // Final State Check
        std::cout << "\n-----------------------------------\n";
        std::cout << "Final Account Status:\n";
        acc.displayDetails();

    } catch (const std::exception& e) {
        std::cerr << "General Error: " << e.what() << "\n";
    }

    return 0;
}
