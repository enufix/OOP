#include<iostream>
#include<cstring>
using namespace std;

class HotelReservation {
protected:
    int days;
    int persons;
    char name[50];
public:
    HotelReservation(const char *name, int days, int persons) {
        strcpy(this->name, name);
        this->days = days;
        this->persons = persons;
    }

    int getPrice() {
        cout << "HotelReservation::getPrice()" << endl;
        return days * persons * 25;
    }

    virtual int getPrice(int advance) = 0;
    virtual int getDiscount() = 0;
};

class BreakfastHotelReservation: public HotelReservation {
public:
    BreakfastHotelReservation(const char *name, int days, int persons)
    : HotelReservation(name, days, persons) {
    }

    //overriding getPrice(int advance)
    int getPrice(int advance) {
        cout << "BreakfastHotelReservation::getPrice(int)" << endl;
        int price = HotelReservation::getPrice() + persons * 5; // accessing protected data persons
        if (advance >= price)
            return advance - price;
        else {
            cout << "For your reservation you should pay " << price << endl;
            return -1;
        }
    }
};

class DinnerHotelReservation: public HotelReservation {
public:
    DinnerHotelReservation(const char *name, int days, int persons): HotelReservation(name, days, persons) {
    }

    //overriding getPrice(int advance)
    int getPrice(int advance) {
        cout << "DinnerHotelReservation::getPrice(int)" << endl;
        int price = HotelReservation::getPrice() + persons * 5; // accessing protected data persons
        if (advance >= price + 50)
            return advance - price;
        else {
            cout << "For your reservation you should pay " << price << endl;
            return -1;
        }
    }

    int getDiscount() {
        return 0;
    }
};

class Hotel {
private:
    char name[50];
    int balance;
public:
    Hotel(char *name) {
        strcpy(this->name, name);
        balance = 0;
    }
    // reference to the base class that can reference to objects of derived classes
    int reserve(HotelReservation hr, int advance) {
        int change = hr.getPrice(advance); //polymorphism
        hr.getDiscount();
        // which definition of getPrice will be called?
        // important! getPrice is VIRTUAL function
        if (change != -1)
            balance += advance - change;
        return change;
    }

};

int main() {
    Hotel h("Bristol");
    HotelReservation hr1("Petko Petkovski", 5, 5);
    int price = h.reserve(hr1, 1000);
    if (price != -1)
        cout << "Change : " << price << endl;

    HotelReservation *hr2 = new DinnerHotelReservation("Risto Ristovski", 5, 5);
    price = h.reserve(*hr2, 1000);
    delete hr2;
    if (price != -1)
        cout << "Change : " << price << endl;
    // pointer from the base class points to object of derived
    HotelReservation hr3("Ana Anovska", 4, 2);
    price = h.reserve(hr3, 100);
        if (price != -1)
        cout << "Change : " << price << endl;

    BreakfastHotelReservation hr4("Tome Tomovski", 5, 3);
    price = h.reserve(hr4, 1000);
    if (price != -1)
        cout << "Change : " << price << endl;

   

    return 0;
}

