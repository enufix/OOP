#include <iostream>
#include <cstring>
using namespace std;

class Ekipa {
    private:
        char ime[100];
        int godina;
        char grad[50];
    public:
        Ekipa(){

        }
        Ekipa(const char *ime, int godina, const char *grad) {
            strcpy(this->ime, ime);
            this->godina = godina;
            strcpy(this->grad, grad);
        }

        bool ednakov(Ekipa &e) {
            return strcmp(this->ime, e.ime) == 0
            && this->godina == e.godina
            && strcmp(this->grad, e.grad) == 0;
        }

        char* getIme() {
            return ime;
        }
};

class Natprevar {
private:
    Ekipa domakin;
    Ekipa gostin;
    int poeniDomakin;
    int poeniGostin;
public:
    Natprevar(Ekipa domakin, Ekipa gostin) {
        this->domakin = domakin;
        this->gostin = gostin;
        this->poeniDomakin = 0;
        this->poeniGostin = 0;
    }

    bool revans(Natprevar &n) {
        return this->domakin.ednakov(n.gostin) &&
            this->gostin.ednakov(n.domakin);
    }

    void domakinPoen() {
        ++poeniDomakin;
    }

    void gostinPoen() {
        ++poeniGostin;
    }

    Ekipa duel(Natprevar &n) {
        if(this->revans(n)) {
            int vkupnoDomakin = this->poeniDomakin;
            int vkupnoGostin = this->poeniGostin;
            vkupnoDomakin += n.poeniGostin;
            vkupnoGostin += n.poeniDomakin;
            if(vkupnoDomakin > vkupnoGostin) {
                return this->domakin;
            } else {
                return this->gostin;
            }
        }
    }

};

int main() {
    Ekipa domakin("FC Barcelona", 1890, "Barcelona");
    Ekipa gostin("Real Madrid", 1899, "Madrid");
    Ekipa ekipa("Valencia", 1899, "Valencia");
    Natprevar clasico1(domakin, gostin);
    Natprevar clasico2(gostin, domakin);
    if(clasico1.revans(clasico2)) {
        cout << "Natprevarot clasico1 e revans na natprevarot clasico 2"
        << endl;
    }

    clasico1.gostinPoen();
    clasico1.domakinPoen();
    clasico1.domakinPoen();
    clasico2.gostinPoen();
    clasico2.gostinPoen();
    clasico2.gostinPoen();
    clasico2.gostinPoen();
    Ekipa pobednik = clasico1.duel(clasico2);
    cout << "Pobednik: " << pobednik.getIme() << endl;
    return 0;
}