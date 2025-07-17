#include <bits/stdc++.h>

using namespace std;

class Product {
public:
    string name;
    double price;

    Product(string name, double price) : name(name), price(price) {}
};

class NonWithdrawableAccount {
protected:
    double balance;
    string accountNumber;
public:
    NonWithdrawableAccount(string accNum, double initialBalance) : accountNumber(accNum), balance(initialBalance) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited $" << fixed << setprecision(2) << amount << " to " << accountNumber << ". New balance: $" << balance << endl;
        }
    }

    virtual ~NonWithdrawableAccount() {}
};

class WithdrawableAccount : public NonWithdrawableAccount {
public:
    WithdrawableAccount(string accNum, double initialBalance) : NonWithdrawableAccount(accNum, initialBalance) {}

    virtual bool withdraw(double amount) = 0;
};

class SavingsAccount : public WithdrawableAccount {
private:
    double interestRate;
public:
    SavingsAccount(string accNum, double initialBalance, double rate)
        : WithdrawableAccount(accNum, initialBalance), interestRate(rate) {}

    bool withdraw(double amount) override {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            cout << "Withdrew $" << fixed << setprecision(2) << amount << " from Savings Account " << accountNumber << ". New balance: $" << balance << endl;
            return true;
        }
        cout << "Withdrawal failed for Savings Account " << accountNumber << ". Insufficient funds or invalid amount." << endl;
        return false;
    }
};

class CurrentAccount : public WithdrawableAccount {
private:
    double overdraftLimit;
public:
    CurrentAccount(string accNum, double initialBalance, double limit)
        : WithdrawableAccount(accNum, initialBalance), overdraftLimit(limit) {}

    bool withdraw(double amount) override {
        if (amount > 0 && (balance + overdraftLimit) >= amount) {
            balance -= amount;
            cout << "Withdrew $" << fixed << setprecision(2) << amount << " from Current Account " << accountNumber << ". New balance: $" << balance << endl;
            return true;
        }
        cout << "Withdrawal failed for Current Account " << accountNumber << ". Exceeds overdraft limit or invalid amount." << endl;
        return false;
    }
};

class FDAccount : public NonWithdrawableAccount {
private:
    int termMonths;
public:
    FDAccount(string accNum, double initialBalance, int term)
        : NonWithdrawableAccount(accNum, initialBalance), termMonths(term) {}
};

int main() {

    NonWithdrawableAccount* account1 = new SavingsAccount("SA001", 1000.00, 0.01);
    NonWithdrawableAccount* account2 = new CurrentAccount("CA001", 500.00, 200.00);
    NonWithdrawableAccount* account3 = new FDAccount("FD001", 5000.00, 12);

    vector<NonWithdrawableAccount*> accounts;
    accounts.push_back(account1);
    accounts.push_back(account2);
    accounts.push_back(account3);

    for (auto acc : accounts) {
        acc->deposit(100.00);
    }

    WithdrawableAccount* savingsAcc = new SavingsAccount("SA002", 2000.00, 0.015);
    WithdrawableAccount* currentAcc = new CurrentAccount("CA002", 800.00, 300.00);

    savingsAcc->deposit(50.00);
    savingsAcc->withdraw(500.00);
    savingsAcc->withdraw(1600.00);

    currentAcc->deposit(20.00);
    currentAcc->withdraw(1000.00);
    currentAcc->withdraw(200.00);

    delete account1;
    delete account2;
    delete account3;
    delete savingsAcc;
    delete currentAcc;

    return 0;
}
