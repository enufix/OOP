#include <iostream>
#include <cstring>
using namespace std;

class NegativnaCena : public exception {
    float cena;
public:
    NegativnaCena(float c) {
        cena = c;
    }
    float getCena() {
        return cena;
    }
};
class NegativenProcent : public exception {

};

class UmetnickoDelo {
protected:
    int godina;
    char *avtor;
    float cena;
public:
    UmetnickoDelo(int g, const char *a, float c) {
        godina = g;
        avtor = new char[strlen(a) + 1];
        strcpy(avtor, a);
        if(c < 0) {
            throw NegativnaCena(c);
        }
        cena = c;
    }

    UmetnickoDelo(const UmetnickoDelo &u) {
        godina = u.godina;
        avtor = new char[strlen(u.avtor) + 1];
        strcpy(avtor, u.avtor);
        cena = u.cena;
    }

    UmetnickoDelo& operator=(const UmetnickoDelo &u) {
        if(this == &u) return *this;
        delete [] avtor;
        godina = u.godina;
        avtor = new char[strlen(u.avtor) + 1];
        strcpy(avtor, u.avtor);
        cena = u.cena;
        return *this;
    }

    virtual float getCena() = 0;
    virtual ~UmetnickoDelo() {
        delete [] avtor;
    }
};

class MuzickoDelo : public UmetnickoDelo {
private:
    char zanr[100];
    static int x;
public:
    MuzickoDelo(int godina, const char *avtor, float cena, const char *z) :
    UmetnickoDelo(godina, avtor, cena) {
        strcpy(zanr, z);
    }

    float procent(int broj, int procent) {
        if(procent < 0) {
            throw NegativenProcent();
        }
        return broj * procent / 100.0;
    }

    float getCena() {
        if(godina >= 1601 && godina <= 1700) {
            return cena + procent(cena, x);
        }
        return cena;
    }

    static void setX(int _x) {
        MuzickoDelo::x = _x;
    }

};
int MuzickoDelo::x = 20;

class SlikarskoDelo : public UmetnickoDelo {
private:
    char tehnika[30];
    int ostetenost;
public:
    SlikarskoDelo(int godina, const char *avtor, float cena,
        const char *t, int o) : UmetnickoDelo(godina, avtor, cena) {
        strcpy(tehnika, t);
        ostetenost = o;
    }

    float getCena() {
        return cena * (1 - ostetenost / 100.0);
    }
};

int main() {
    UmetnickoDelo *m = new MuzickoDelo(1650, "Avtor", 500, "zanr");
    UmetnickoDelo *s = new SlikarskoDelo(1900, "Slikar", 1000, "tehnika", 28);
    try {
        SlikarskoDelo x(2000, "Slika", -300, "teh", 15);    
        SlikarskoDelo copy(x);
        x = copy;
    } catch(NegativnaCena &c) {
        cout << "Obid za kreiranje objekt so negativna cena: ";
        cout << c.getCena() << endl;
    }
    
    MuzickoDelo::setX(-50);
    try {
        cout << m->getCena() << endl;
        cout << s->getCena() << endl;
    } catch(exception &c) {
        cout << "Negativen procent" << endl;
    }
    delete m;
    delete s;
    return 0;
}