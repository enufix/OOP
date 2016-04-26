#include <iostream>
#include <cstring>
using namespace std;

class HotelReservation {
protected:
    int days;
    int persons;
    char name[100];
public:
    HotelReservation(int d = 0, int p = 0, const char *n = "no name") {
        days = d;
        persons = p;
        strcpy(name, n);
    }

    virtual int getPrice() {
        return days * persons * 25;
    }
};

class HotelReservrationPlus : public HotelReservation {
public:
    HotelReservrationPlus(int d = 0, int p = 0, const char *n = "no name")
    : HotelReservation(d, p, n) {
    }

    int getPrice(int) {
        return HotelReservation::getPrice() + days * persons * 5;
    }
};

class Hotel {
public:
    void makeReservation(HotelReservation *hr) {
        cout << "Make reservation with price: ";
        cout << hr->getPrice() << endl;
    }
};

int main() {
    HotelReservation hr(3, 5);
    cout << "Price: " << hr.getPrice() << endl;
    HotelReservrationPlus hrp(3, 5);
    cout << "Price: " << hrp.getPrice(5) << endl;
    HotelReservation *hr1 = &hrp;
    cout << "Price: " << hr1->getPrice() << endl;
    Hotel h;
    h.makeReservation(&hr);
    h.makeReservation(&hrp);
    h.makeReservation(hr1);
    return 0;
}








