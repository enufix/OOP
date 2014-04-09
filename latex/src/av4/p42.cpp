#include <iostream>
#include <cstring>
using namespace std;

class Team {
private:
    char name[100];
    int yearFormed;
    char city[100];
public:
    Team(const char *name = "", const int yearFormed = 0,
         const char *city = "") {
        strcpy(this->name, name);
        this->yearFormed = yearFormed;
        strcpy(this->city, city);
    }

    char *getName() {
        return name;
    }

    void print() {
        cout << name << " " << yearFormed << endl;
    }

};

class Game {
private:
    Team homeTeam;
    Team awayTeam;
    int homeGoals;
    int awayGoals;
public:
    Game(const Team homeTeam = Team(), const Team awayTeam = Team(),
         const int homeGoals = 0, const int awayGoals = 0) {
        this->homeTeam = homeTeam;
        this->awayTeam = awayTeam;
        this->homeGoals = homeGoals;
        this->awayGoals = awayGoals;
    }

    Team getHome() const {
        return homeTeam;
    }
    Team getAway() const {
        return awayTeam;
    }

    int getHomeGoals() const {
        return homeGoals;
    }

    int getAwayGoals() const {
        return awayGoals;
    }

};

Team winner(const Game game1, const Game game2) {
    if (strcmp(game1.getHome().getName(), game2.getAway().getName()) == 0 &&
            strcmp(game2.getHome().getName(), game1.getAway().getName()) == 0) {
        int goalsHome = game1.getHomeGoals() + game2.getAwayGoals();
        int goalsAway = game1.getAwayGoals() + game2.getHomeGoals();
        if (goalsHome >= goalsAway) {
            return game1.getHome();
            // return game2.getAway();
        } else {
            return game1.getAway();
        }
    }
    return Team();
}

int main() {
    Team t1("Barcelona", 1900, "Barcelona");
    Team t2("Real Madrid", 1890, "Madrid");
    Team t3("Elche", 1950, "Elche");
    Game g1(t1, t2, 5, 0);
    Game g2(t2, t1, 2, 2);
    Game g3(t1, t3, 6, 2);
    Team w = winner(g1, g3);
    w.print();
    return 0;
}