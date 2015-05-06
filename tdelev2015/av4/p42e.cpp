#include <iostream>
#include <cstring>
using namespace std;

class Team {
private:
	char name[100];
	int year;
	char city[100];
public:
	Team(char *n = "", int y = 0, char *c = "") {
		strcpy(name, n);
		year = y;
		strcpy(city, c);
	}

	bool equal(Team t) {
		return strcmp(name, t.name) == 0;
	}

	char* getName() {
		return name;
	}

};
class Game {
private:
	Team home;
	Team guest;
	int goalsHome;
	int goalsGuest;
public:
	Game(Team h, Team g, int gh, int gg) {
		home = h;
		guest = g;
		goalsHome = gh;
		goalsGuest = gg;
	}
	Team getHome() {
		return home;
	}
	Team getGuest() {
		return guest;
	}
	void result(Game g) {
		int g1 = goalsHome + g.goalsGuest;
		int g2 = goalsGuest + g.goalsHome;
		cout << g1 << " : " << g2 << endl;
		if (g1 > g2) {
			cout << "Winner: " << home.getName() << endl;
		} else if (g2 > g1) {
			cout << "Winner: " << guest.getName() << endl;
		} else {
			cout << "Draw" << endl;
		}
	}
};
bool isReturnMatch(Game g1, Game g2) {
	Team g1home = g1.getHome();
	Team g1guest = g1.getGuest();
	Team g2guest = g2.getGuest();
	Team g2home = g2.getHome();
	return g1home.equal(g2guest) && g2home.equal(g1guest);
}
int main() {
	Team t1("Manchester United", 1900, "Manchester");
	Team t2("Arsenal", 1901, "London");
	Game g1(t1, t2, 1, 2);
	Game g2(t2, t1, 4, 1);
	if (isReturnMatch(g1, g2)) {
		g1.result(g2);
	} else {
		cout << "Not a return match" << endl;
	}
	return 0;
}