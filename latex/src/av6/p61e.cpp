#include <iostream>
#include <cstring>
using namespace std;

class TennisPlayer {
protected:
    char name[100];
    bool playsInLeague;
public:
    TennisPlayer(const char *name = "",
                 const bool playsInLeague = false) {
        strcpy(this->name, name);
        this->playsInLeague = playsInLeague;
        cout << "constructor TennisPlayer" << endl;
    }

    friend ostream &operator<<(ostream &out, const TennisPlayer &tp) {
        out << tp.name << endl;
        out << (tp.playsInLeague ? "Plays in League" : "Does not play in league") << endl;
        return out;
    }
};

class RankedTennisPlayer : public TennisPlayer {
private:
    int rank;
public:
    RankedTennisPlayer(const char *name = "unknown",
                       const bool playsInLeague = false, const int rank = 0) :
        TennisPlayer(name, playsInLeague) {
        cout << "constructor RankedTennisPlayer" << endl;
        this->rank = rank;
    }


    friend ostream &operator<<(ostream &out, const RankedTennisPlayer &rtp) {
        out << rtp.name << endl;
        out << (rtp.playsInLeague ? "Plays in League" : "Does not play in league") << endl;
        out << rtp.rank << endl;
        return out;
    }
};


int main() {
    TennisPlayer tp("Novak Djokovikj");
    RankedTennisPlayer rtp;
    cout << tp;
    cout << rtp;
    return 0;
}