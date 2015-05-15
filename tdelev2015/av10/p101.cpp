#include <iostream>
#include <cstring>
using namespace std;

class Muzicar {
protected:
    char ime[100];
    double zarabotka;
    int nastapi;
    char pol;
public:
    Muzicar(char *i = "", double z = 0, 
        int n = 0, char p = 'F') {
        strcpy(ime, i);
        zarabotka = z;
        nastapi = n;
        pol = p;
    }

    friend ostream& operator<<(ostream &out, const Muzicar &m) {
        out << m.ime << endl;
        out << m.zarabotka << endl;
        out << m.nastapi << endl;
        out << m.pol << endl;
        return out;
    }

    bool operator>(double zarabotka) {
        return this->zarabotka > zarabotka;
    }

    virtual double cenaNastap() = 0;
    virtual double danok() = 0;
};

class Gitarist : public Muzicar {
private:
    double cenaGitara;
public:
    Gitarist(char *i = "", double z = 0, 
        int n = 0, char p = 'F', double cg = 0) :
    Muzicar(i, z, n, p) {
        cenaGitara = cg;
    }

    double cenaNastap() {
        return cenaGitara / 10;
    }

    double danok() {
        if(nastapi > 30) {
            return zarabotka * 0.08;
        }else {
            return zarabotka * 0.1;
        }
    }

};

class Tapanar : public Muzicar {
private:
    int vozrast;
public:
    Tapanar(char *i = "", double z = 0, 
        int n = 0, char p = 'F', int v = 0) :
        Muzicar(i, z, n, p) {
            vozrast = v;
        }

    double cenaNastap() {
        return vozrast * 50;
    }

    double danok() {
        if(pol == 'M') {
            return zarabotka * 0.12;
        } else {
            return zarabotka * 0.1;
        }
    }

};

void najskapMuzicar(Muzicar **m, int n) {
    Muzicar *najskap = m[0];
    for(int i = 1; i < n; ++i) {
        if(m[i]->cenaNastap() > najskap->cenaNastap()) {
            najskap = m[i];
        }
    }
    cout << *najskap;
}

int main() {
    int n, x;
    cin >> n >> x;
    Muzicar **m = new Muzicar*[n];
    for(int i = 0; i < n; ++i) {
        char ime[100];
        float zarabotka;
        int nastapi;
        char pol;
        cin >> ime >> zarabotka >> nastapi >> pol;
        if(i < x) {
            float cena_gitara;
            cin >> cena_gitara;
            m[i] = new Gitarist(ime, zarabotka, nastapi, pol, cena_gitara);
        } else {
            int vozrast;
            cin >> vozrast;
            m[i] = new Tapanar(ime, zarabotka, nastapi, pol, vozrast);
        }
    }
    cout << "=== DANOK ===" << endl;
    for(int i = 0; i < n; ++i) {
        cout << *m[i];
        cout << m[i]->danok() << endl;
    }
    cout << "=== NAJSKAP MUZICAR ===" << endl;
    najskapMuzicar(m, n);
    
    for(int i = 0; i < n; ++i) {
        delete m[i];
    }
    delete [] m;
    return 0;
}
