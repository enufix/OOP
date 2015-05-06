#include <iostream>
#include <cstring>
using namespace std;

class BankAccount {
protected:
    char name[100];
    char number[10];
    double balance;
public:
    BankAccount(const char *n = "", const char *nu = "", const double b = 0) {
        strcpy(name, n);
        strcpy(number, nu);
        balance = b;
    }

    friend ostream& operator<<(ostream &o, const BankAccount &ba) {
        o << ba.name << endl;
        o << ba.number << endl;
        o << ba.balance << endl;
        return o;
    }

    void addMoney(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        cout << "withdraw bank account" << endl;
        if(amount <= balance) {
            balance -= amount;
        }
    }

};

class ExtendedBankAccount : public BankAccount {
private:
    double limit;
    static const double INTEREST = 10;
public:
    ExtendedBankAccount(const char *n = "", const char *nu = "", 
        const double b = 0, const double l = 0) : BankAccount(n, nu, b) {
        limit = l;
    }

    void withdraw(double amount) {
        cout << "withdraw ExtendedBankAccount" << endl;
        if(amount < balance + limit) {
            balance -= amount;
        } else {
            cout << "Not enough money" << endl;
        }
    }
};

int main() {
    BankAccount b("John", "5555", 50000);
    ExtendedBankAccount eb("Marry", "3333", 100000);
    cout << b;
    cout << eb;
    b.withdraw(300);
    eb.withdraw(500);
    cout << b;
    return 0;

}