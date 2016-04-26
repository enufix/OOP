#include <iostream>
#include <cstring>
using namespace std;

class Smetka {
protected:
    char ime[35];
    long broj;
    double saldo;
public:
    Smetka(const char *i = "", long b = 0, double s = 0) {
        strcpy(ime, i);
        broj = b;
        saldo = s;
    }
};

class SmetkaPlus : public Smetka {
private:
    double zaem;
    double kamata;
    double dolzi;
public:
    SmetkaPlus(const char *i = "", long b = 0, double s = 0,
        double k = 0) :
    Smetka(i, b, s), zaem(0), kamata(k), dolzi(0) {
    }
};

int main() {
    Smetka s("Petko", 1000, 50000);
    SmetkaPlus sp("Mitko", 1001, 20000, 7.2);
    return 0;
}