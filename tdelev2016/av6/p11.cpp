#include <iostream>
#include <cstring>
using namespace std;

class TenisPlayer {
protected:
    char name[100];
    bool playsInLeague;
public:
    TenisPlayer(const char *n, bool pl = false) {
        cout << "TenisPlayer constructor" << endl;
        strcpy(name, n);
        playsInLeague = pl;
    }
    friend ostream& operator<<(ostream &out, const TenisPlayer &tp) {
        cout << "operator<< in TenisPlayer" << endl;
        out << tp.name << " : " << tp.playsInLeague << endl;
        return out;
    }
};

class RankedTenisPlayer : public TenisPlayer {
private:
    int rank;
public:
    RankedTenisPlayer() : TenisPlayer("noname") {
        cout << "RankedTenisPlayer default constructor" << endl;
        rank = 0;
    }
    RankedTenisPlayer(const TenisPlayer &tp, int r)
    : TenisPlayer(tp) {
        rank = r;
    }
    RankedTenisPlayer(const char *n, bool pl, int r) 
        : TenisPlayer(n, pl)
    {
        cout << "RankedTenisPlayer constructor" << endl;
        rank = r;
    }

    friend ostream& operator<<(ostream &out, const RankedTenisPlayer &rtp) {
        cout << "operator<< in RankedTenisPlayer" << endl;
        out << (TenisPlayer)rtp;
        out << " Rank: " << rtp.rank << endl;
        return out;
    }
};

int main() {
    TenisPlayer tp("Nadal");
    cout << tp;
    RankedTenisPlayer rtp("Federer", true, 2);
    cout << rtp;
    RankedTenisPlayer x(tp, 10);
    cout << x;
    return 0;
}