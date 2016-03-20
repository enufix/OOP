#include<iostream>
#include<string.h>
using namespace std;

class UcesnikKurs {
protected:
    char ime[30];
    int finalenIspit;
    bool dopolnitelna;
public:
    UcesnikKurs(char* ime, int finalenIspit) {
        strcpy(this->ime, ime);
        this->finalenIspit = finalenIspit;
        this->dopolnitelna = false;
    }
    virtual ~UcesnikKurs() {}
    UcesnikKurs(const UcesnikKurs & u) {
        strcpy(this->ime, u.ime);
        this->finalenIspit = u.finalenIspit;
        this->dopolnitelna = u.dopolnitelna;
    }
    bool getDopolnitelna() {return dopolnitelna;}
    char* getIme() {return ime;}

    virtual int osvoeniPoeni() {
        return finalenIspit;
    }
    friend ostream& operator<<(ostream& o, UcesnikKurs &u) {
        o << u.ime << " - " << u.osvoeniPoeni() << endl;
        return o;
    }

};
class IndexOutOfBoundException {
public:
    void print() {
        cout << "Can not add more extra activities" << endl;
    }

};
class UcesnikKursDopolnitelen: public UcesnikKurs {
private:
    int broj;
    int *poeni;

public:
    const static int M = 5;
    ~UcesnikKursDopolnitelen()
    {
        delete []poeni;
    }
    UcesnikKursDopolnitelen(char* ime, int finalenIspit): UcesnikKurs(ime, finalenIspit) {
        this->dopolnitelna = true;
        broj = 0;
        poeni = new int[M];
    }
    UcesnikKursDopolnitelen(const UcesnikKursDopolnitelen& u): UcesnikKurs(u) {
        broj = u.broj;
        poeni = new int[M];
        for (int i = 0; i < broj; i++) poeni[i] = u.poeni[i];
    }

    int osvoeniPoeni() {
        int sum = 0;
        for (int i = 0; i < broj; i++) sum += poeni[i];
        return (finalenIspit * 80) / 100 + sum;
    }
    friend void operator +=(UcesnikKursDopolnitelen &u, int novi) {
        if (u.broj == u.M) throw IndexOutOfBoundException();
        u.poeni[u.broj++] = novi;
    }
};
class Kurs {
private:
    char naziv[30];
    UcesnikKurs *ucesnici[10];
    int broj;
    int static P;
public:
    Kurs(char *naziv, UcesnikKurs** ucesnici, int broj ) {
        strcpy(this->naziv, naziv);
        for (int i = 0; i < broj; i++) {
            //ako ucesnikot ima dopolnitelni aktivnosti
            if (ucesnici[i]->getDopolnitelna()) {
                this->ucesnici[i] = new UcesnikKursDopolnitelen(*dynamic_cast<UcesnikKursDopolnitelen*>(ucesnici[i]));
            }
            else this->ucesnici[i] = new UcesnikKurs(*ucesnici[i]);
        }
        this->broj = broj;
    }
    ~Kurs() {
        for (int i = 0; i < broj; i++) delete ucesnici[i];
    }

    //da se dopolni
    static void setP(int novoP) {
        P = novoP;
    }
    void pecatiUcesnici() {
        cout << "The course " << naziv << " is passed from:" << endl;
        for (int i = 0; i < broj; i++)
            if (ucesnici[i]->osvoeniPoeni() >= P) cout << (*ucesnici[i]);
    }
    void dodadiPoeniDopolnitelnaAktivnost(char *ime, int poeniA) {
        for (int i = 0; i < broj; i++)
            if (strcmp(ucesnici[i]->getIme(), ime) == 0)
            {
                UcesnikKursDopolnitelen* nov = dynamic_cast<UcesnikKursDopolnitelen*>(ucesnici[i]);
                if (nov != 0) {
                    (*nov) += poeniA;
                }

            }
    }
};
int Kurs::P = 50;
int main() {

    UcesnikKurs **niza;
    int n, m, poeni;
    char ime[10];
    bool daliDopolnitelnaAktivnost;
    cin >> n;
    niza = new UcesnikKurs*[n];
    for (int i = 0; i < n; i++) {
        cin >> ime;
        cin >> poeni;
        cin >> daliDopolnitelnaAktivnost;
        if (!daliDopolnitelnaAktivnost)
            niza[i] = new UcesnikKurs(ime, poeni);
        else
            niza[i] = new UcesnikKursDopolnitelen(ime, poeni);
    }

    Kurs programiranje("Programiranje", niza, n);
    for (int i = 0; i < n; i++) delete niza[i];
    delete [] niza;

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> ime >> poeni;
        try {
            programiranje.dodadiPoeniDopolnitelnaAktivnost(ime, poeni);
        }
        catch (IndexOutOfBoundException i) {
            i.print();
        }
    }

    Kurs::setP(60);

    programiranje.pecatiUcesnici();

}
