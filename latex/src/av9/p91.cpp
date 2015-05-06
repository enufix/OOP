#include <iostream>
#include <cstring>
using namespace std;

class PaymentCard {
protected:
    int id;
    double balance;
public:
    PaymentCard(const int id = 0, const double balance = 0) {
        this->id = id;
        this->balance = balance;
    }

    virtual void pay(double amount) = 0;

    void deposit(double amount) {
        this->balance += amount;
    }

    void show() {
        cout << "ID: " << id << endl;
        cout << "Balance: " << balance << endl;
    }

};

class DebitCard : public PaymentCard {
private:
    static const double DISCOUNT = 5;
    char pin[5];
public:
    DebitCard(const int id = 0, const double balance = 0, const char *pin = "") : PaymentCard(id, balance) {
        strcpy(this->pin, pin);
    }

    void pay(double amount) {
        double toPay = amount * (1 - 1 / DISCOUNT);
        if (toPay < balance) {
            balance -= toPay;
        } else {
            cout << "Not enough money :(" << endl;
            throw 1;
        }
    }
};

class CreditCard : public PaymentCard {
private:
    double limit;
public:
    CreditCard(const int id = 0, const double balance = 0, const double limit = 1000) : PaymentCard(id, balance) {
        this->limit = limit;        
    }

    void pay(double amount) {
        double toPay = amount * (1 - 1 / 10.);
        if (limit < 6000) {
            toPay = amount * (1 - 1 / 3.);
        }
        if (toPay > balance + limit) {
            balance -= toPay;
        } else {
            cout << "Not enough money :(" << endl;
            throw 1;
        }
    }
};

class CashRegister {
private:
    double amountCash;
    double amountCard;
    int day, month, year;
public:
    CashRegister(const int d = 1, const int m = 1, const int y = 2000) {
        amountCash = 0;
        amountCard = 0;
        day = d;
        month = m;
        year = y;
    }

    void pay(double amount) {
        amountCash += amount;
    }

    void pay(double amount, PaymentCard &card) {
        try {
            if(1) { // some other logic
                throw 1;
            }
            card.pay(amount);
            amountCard += amount;

        } catch(int e) {
            cout << "Payment did not succeed!" << endl;
            cout << "Error: " << e << endl;
        } 
        
        
    }

    void show() {
        cout << day << "." << month << "." << year << endl;
        cout << "Amount cash: " << amountCash << endl;
        cout << "Amount card: " << amountCard << endl;
    }
};

int main() {
    CashRegister daily(22, 4, 2014);
    PaymentCard *card;
    daily.show();
    cout << "Paying in cash!" << endl;
    daily.pay(5000);
    daily.show();
    card = new CreditCard(12345678, 54000.00, 10000.00);
    cout << "Paying with card!" << endl;
    daily.pay(10000, *card);
    daily.show();
    delete card;
    card = new DebitCard(123456789, 54000.00, "4321");
    cout << "Paying with card!" << endl;
    daily.pay(10000, *card);
    daily.show();
    delete card;
    return 0;
}