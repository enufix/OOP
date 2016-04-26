#include <iostream>
using namespace std;

class PaymentCard {
protected:
    long id;
    int balance;
public:
    PaymentCard(long _id, int _balance) {
        id = _id;
        balance = _balance;
    }

    void add(int amount) {
        balance += amount;
    }

    bool withdraw(int amount) {
        if(amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }
    virtual void pay(int amount) = 0;

    friend ostream& operator<<(ostream &o, const PaymentCard &p) {
        o << p.id << " : " << p.balance;
        return o;
    }

    static int discount(int amount, int percent) {
        cout << id << endl;
        return amount * percent / 100.0;
    }

};

class MaestroCard : public PaymentCard {
    static const int DISCOUNT = 5; // 5% discount
public:
    
    MaestroCard(long id, int balance) : PaymentCard(id, balance) {

    }

    void pay(int amount) {
        int discount = PaymentCard::discount(amount, DISCOUNT);
        balance -= (amount - discount);
    }
};

class MasterCard : public PaymentCard {
private:
    int limit;
public:
    static const int SMALL_DISCOUNT = 3; // 3%
    static int LARGE_DISCOUNT; // 10%
    static const int LIMIT = 6000; // the payment limit

    MasterCard(long id, int balance, int _limit) :
        PaymentCard(id, balance), limit(_limit) {
        }

    void pay(int amount) {
        int discount;
        if(limit < LIMIT) {
            discount = PaymentCard::discount(amount, SMALL_DISCOUNT);
        } else {
            discount = PaymentCard::discount(amount, LARGE_DISCOUNT);
        }
        balance -= (amount - discount);
    }

    void setLimit(int _limit) {
        limit = _limit;
    }

};
int MasterCard::LARGE_DISCOUNT = 10; // 10% 

int main() {
    MaestroCard maestro(1, 5000);
    MasterCard master(2, 10000, 8000);
    
    cout << maestro << endl;
    cout << master << endl;
    maestro.pay(2000);
    MasterCard::LARGE_DISCOUNT = 20;
    master.pay(2000);
    cout << maestro << endl;
    cout << master << endl;
    cout << "Discount: " << PaymentCard::discount(100, 15) << endl;


    return 0;
}