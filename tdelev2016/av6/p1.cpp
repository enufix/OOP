#include <iostream>
#include <cstring>
using namespace std;

class TenisPlayer {
protected:
    char name[100];
    bool playInLeague;
public:
    TenisPlayer(const char* n, bool pl = false) {
        cout << "constructor TenisPlayer" << endl;
        strcpy(name, n);
        playInLeague = pl;
    }

/*    TenisPlayer& operator=(const TenisPlayer &tp) {
        cout << "operator= TenisPlayer" << endl;
        if(this == &tp) return *this;
        strcpy(name, tp.name);
        playInLeague = tp.playInLeague;
        return *this;
    }*/

    friend ostream& operator<<(ostream& out, const TenisPlayer &tp) {
        cout << "<< TENIS PLAYER" << endl;
        out << tp.name;
        if(tp.playInLeague) {
            out << " PLAY IN LEAGUE";
        }
        out << endl;
        return out;
    }

    ~TenisPlayer() {
        cout << "destructor TenisPlayer" << endl;
    }
};

class RankedTenisPlayer : public TenisPlayer {
private:
    int rank;
public:
    RankedTenisPlayer(const char* n, bool pl = false, int r = 0)
        : TenisPlayer(n, pl)
    {
        cout << "constructor RankedTenisPlayer" << endl;
        rank = r;
        playInLeague = true;
    }

    ~RankedTenisPlayer() {
        cout << "destructor RankedTenisPlayer" << endl;
    }

    friend ostream& operator<<(ostream& out, const RankedTenisPlayer &tp) {
        cout << "<< RANKED TENIS PLAYER" << endl;
        out << (TenisPlayer)tp;
        out << "Rank: " << tp.rank << endl;
        return out;
    }
};

int main() {
    TenisPlayer tp("Federer");
    cout << tp;
    //TenisPlayer t;
    RankedTenisPlayer rtp("Nadal");
    cout << rtp;
    tp = rtp;
    cout << tp;
    //RankedTenisPlayer copy(tp);
    TenisPlayer copy(rtp);
    cout << copy;
    return 0;
}