#include <iostream>
#include <cstring>

using namespace std;



class Isklucok {
protected:
    char msg[100];
public:
    Isklucok(char *m) {
        strcpy(msg, m);
    }

    void print() {
        cout << msg << endl;
    }
};


class DonaciskiBroj {
private:
    char broj[15];
    static double balance;
    static int num_donations;
public:
    DonaciskiBroj(char *b = "") {
        strcpy(broj, b);
    }

    void PrimiDonacija(double suma) {
        if(suma < 0) throw Isklucok("Nevalidna suma za donacija!");
        balance += suma;
        num_donations++;
        cout << "Donirani " << suma << " denari!" << endl;
    }

    void setTelBroj(char *b) {
        strcpy(broj, b);
    }

    static void Sostojba() {
        cout << "Balans: " << balance << ", ";
        cout << "broj na donacii: "<< num_donations << endl;
    }
};
double DonaciskiBroj::balance = 0;
int DonaciskiBroj::num_donations = 0;

class Korisnik{
private:
    char broj[15];
    double balance;
public:
    Korisnik(char *b = "", double bb = 0) {
        strcpy(broj, b);
        balance = bb;
    }
    void Doniraj(DonaciskiBroj b, double suma) {
        if(suma > balance) {
            cout << "Nemate dovolno sredstva za da izvrsite donacija!" << endl;
            return;
        }
        try{
            b.PrimiDonacija(suma);
            balance -= suma;
        } catch(Isklucok i) {
            cout << "Isklucok: ";
            i.print();
        }
        
    }

    void setBalans(double b) {
        balance = b;
    }

    void setTelBroj(char *b) {
        strcpy(broj, b);
    }
};


/*

Vasiot Kod Tuka!!!

*/


int main(){
    int d, k, t;
    char tb[15];

    float s, b;

    DonaciskiBroj broevi[3];
    Korisnik korisnici[10];

    //cout<<"Vnesi go brojot na donaciski broevi"<<endl;
    cin>>d;

    for (int i=0; i<d; i++){
        //cout<<"Vnesi go tel. broj na "<< i << "-tiot donaciski broj: ";
        cin>>tb;
        //cout<<endl;
        broevi[i].setTelBroj(tb);
    }

    //cout<<"Vnesi go brojot na korisnici"<<endl;
    cin>>d;

    for (int i=0; i<d; i++){
        //cout<<"Vnesi go tel. broj na "<< i << "-tiot korisnik: ";
        cin>>tb;
        //cout<<"Vnesi go balansot na "<< i << "-tiot korisnik: ";
        cin>>b;
        korisnici[i].setTelBroj(tb);
        korisnici[i].setBalans(b);
    }

    while (true){
        //cout<<"Vnesi na koj Tel. Broj ke kje se donira (-1 za kraj): ";
        cin>>t;
        if (t==-1){
            break;
        }

        //cout<<"Vnesi koj korisnik kje donira: ";
        cin>>k;
        //cout<<"Vnesi ja sumata koja kje se donira: ";
        cin>>s;

        korisnici[k].Doniraj(broevi[k], s);

        DonaciskiBroj::Sostojba();
    }

    return 0;
}