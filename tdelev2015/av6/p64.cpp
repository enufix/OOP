#include <iostream>
#include <cstring>
using namespace std;

class TenisPlayer {
protected:
    char name[100];
    bool playsProfessional;
public:
    TenisPlayer(const char *n = "", bool pp = false) {
        cout << "base constructor" << endl;
        strcpy(name, n);
        playsProfessional = pp;
    }

    void setProfessional() {
        playsProfessional = true;
    }

    friend ostream& operator<<(ostream &o, const TenisPlayer &tp) {
        o << tp.name << endl;
        o << (tp.playsProfessional ? "Professional" : "Amateur") << endl;
        return o;
    }

};

class RankedTenisPlayer : public TenisPlayer {
private:
    int rank;
public:
    RankedTenisPlayer(const char *n = "", bool pp = false, int r = 0)
    : TenisPlayer(n, pp)  {
        cout << "derived constructor" << endl;
        //strcpy(name, n);
        //playsProfessional = pp;
        rank = r;
    }

};

int main() {
    TenisPlayer player("Player one", false);
    RankedTenisPlayer trp;
    trp.setProfessional();
    cout << player << endl;
    cout << trp;
    return 0;
}

