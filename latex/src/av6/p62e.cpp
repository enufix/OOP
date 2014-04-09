#include <iostream>
#include <cstring>
using namespace std;

class BankAccount {
protected:
    char name[100];
    long number;
    double balance;
public:
    BankAccount(const char *name = "----", const long number = 0,
                const double balance = 0) {
        strcpy(this->name, name);
        this->number = number;
        this->balance = balance;
    }

    void showBalance() {
        cout << name << endl;
        cout << number << endl;
        cout << balance << endl;
    }

    void addMoney(double amount) {
        balance += amount;
    }

    void withdrawMoney(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "You are not rich enough, b... :)" << endl;
        }
    }

};

class BankAccountPlus : public BankAccount {
private:
    double limit;
    static const double INTEREST = 10; // % percent
public:
    BankAccountPlus(const char *name = "----", const long number = 0,
                    const double balance = 0, const double limit = 0) :
        BankAccount(name, number, balance) {
        this->limit = limit;
    }

    void withdrawMoney(double amount) {
        if (amount <= balance + limit) {
            balance -= amount;
        } else {
            cout << "The bank is not giving you that much money..." << endl;
            cout << "Balance: " << balance << endl;
            cout << "Limit: " << limit << endl;
        }
    }

    static void showInterest() {
        cout << INTEREST << endl;
    }


};

int main() {
    BankAccount ba("Pero", 6, 1000000);
    BankAccountPlus bap("Mite", 10, 5000, 1000);
    ba.showBalance();
    ba.addMoney(50000);
    ba.withdrawMoney(600000);
    ba.showBalance();
    bap.showBalance();
    bap.addMoney(500);
    bap.showBalance();
    bap.withdrawMoney(7000);
    bap.showBalance();
    bap.showInterest();
    BankAccountPlus::showInterest();
    return 0;
}