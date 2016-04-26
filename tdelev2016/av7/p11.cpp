#include <iostream>
#include <cstring>
using namespace std;

class HotelReservation {
protected:
    int persons;
    int nights;
    char name[100];
public:
    HotelReservation(const char *n = "john doe",
        int nn = 1, int pp = 1) {
        strcpy(name, n);
        nights = nn;
        persons = pp;
    }
    virtual float price() const  = 0;
    friend ostream& operator<<(ostream &out, 
        const HotelReservation &hr) {
        out << "HotelReservation" << endl;
        out << "Name: " << hr.name << endl;
        out << "Persons: " << hr.persons << endl;
        out << "Nights: " << hr.nights << endl;
        out << "Price: " << hr.price() << endl;
        return out;
    }
};

class HotelReservationPlus : public HotelReservation {
public:
    HotelReservationPlus(const char *n = "john doe",
        int nn = 1, int pp = 1) : HotelReservation(n, nn, pp) {
    }

    float price() const {
        return 25 * persons * nights 
        + 10 * persons * nights;
    }
};

class ReservationProcessor {
public:
    ReservationProcessor() {
    }
    void printInvoice(HotelReservation *hr) {
        cout << "Invoice for: " << endl;
        cout << *hr << endl;
        cout << "Total Price: " << hr->price() << endl;
    }
};

int main() {
    /*HotelReservation hr("MIchael Jackson", 20, 5);
    cout << hr;*/
    HotelReservationPlus hrp("Madona", 10, 15);
    cout << hrp;
    ReservationProcessor rp;
    //rp.printInvoice(&hr);
    rp.printInvoice(&hrp);
    return 0;
}