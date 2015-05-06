#include <iostream>
using namespace std;

class PaymentCard {
protected:
    int id;
    double balance;
public:
    PaymentCard(int _id = 0, double _balance = 0) {
        id = _id;
        balance = _balance;
    }

    virtual bool pay(double amount) = 0;

    void deposit(double amount) {
        balance += amount;
    }

    virtual void print() {
        cout << "ID: " << id << endl;
        cout << "Balance: " << balance << endl;
    }
};

class DebitCard : public PaymentCard {
private:
    static const double DISCOUNT = 5;
public:
    DebitCard(int id = 0, double balance = 0) :
        PaymentCard(id, balance) {
    }

    bool pay(double amount) {
        double toPay = amount * (1 - DISCOUNT / 100);
        if (toPay <= balance) {
            balance -= toPay;
            return true;
        }
        return false;
    }

};

class CreditCard : public PaymentCard {
private:
    double limit;
    static const double DISCOUNT_SMALL = 3;
    static double DISCOUNT_LARGE;
public:
    CreditCard(int id = 0, double balance = 0, double _limit = 0) :
        PaymentCard(id, balance) {
        limit = _limit;
    }


    static void changeDiscount(double amount) {
        DISCOUNT_LARGE = amount;
    }

    bool pay(double amount) {
        if (limit < 6000) {
            amount = amount * (1 - DISCOUNT_SMALL / 100);
        } else {
            amount = amount * (1 - DISCOUNT_LARGE / 100);
        }
        if (amount < balance + limit) {
            balance -= amount;
            return true;
        }
        return false;
    }


};
double CreditCard::DISCOUNT_LARGE = 10;

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
        card.pay(amount);
        amountCard += amount;
    }
    void show () {
        cout << day << "." << month << "." << year << endl;
        cout << " Amount cash : " << amountCash << endl;
        cout << " Amount card : " << amountCard << endl;
    }
};
int main() {

    DebitCard dc(1000, 60000);
    dc.pay(10000);
    //DebitCard::DISCOUNT = 20;
    dc.print();

    CreditCard cc(2000, 10000, 15000);
    cc.pay(20000);
    cc.print();
    CreditCard::changeDiscount(20);
    cc.pay(5000);
    cc.print();
    CashRegister cr(5, 5, 2015);
    cr.pay(500, dc);
    cr.pay(1000, cc);
    cr.show();
    return 0;
}