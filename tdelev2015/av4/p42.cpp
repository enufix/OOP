#include <iostream>
#include <cstring>
using namespace std;

class Ekipa {
private:
	char ime[50];
	int godina;
	char grad[50];
public:
	Ekipa(char *i = "", int g = 0, char *gr = "") {
		strcpy(ime, i);
		godina = g;
		strcpy(grad, gr);
	}

	bool ednakva(Ekipa &e) {
		return strcmp(ime, e.ime) == 0 && godina == e.godina;
	}

	void pechati() {
		cout << ime << endl;
	}
};

class Natprevar {
private:
	Ekipa domakin;
	Ekipa gostin;
	int goloviDomakin;
	int goloviGostin;
public:
	Natprevar(Ekipa d, Ekipa g, int gd, int gg) {
		domakin = d;
		gostin = g;
		goloviGostin = gg;
		goloviDomakin = gd;
	}
	Ekipa getDomakin() {
		return domakin;
	}
	Ekipa getGostin() {
		return gostin;
	}

	void duel(Natprevar &n) {
		int g1 = goloviDomakin + n.goloviGostin;
		int g2 = goloviGostin + n.goloviDomakin;
		cout << g1 << " : " << g2 << endl;
		if(g1 > g2) {
			domakin.pechati();
		} else {
			gostin.pechati();
		}
	}

};

bool revansh(Natprevar n1, Natprevar n2) {
	Ekipa e1 = n1.getGostin();
	Ekipa e2 = n2.getGostin();
	return n1.getDomakin().ednakva(e2) 
	&& n2.getDomakin().ednakva(e1);
}


int main() {
	Ekipa e1("Barcelona", 1850, "Barcelona");
	Ekipa e2("Real Madrid", 1830, "Madrid");
	Natprevar n1(e1, e2, 5, 0);
	Natprevar n2(e2, e1, 8, 2);
	cout << e1.ednakva(e2) << endl;
	if(revansh(n1, n2)) {
		n1.duel(n2);
	}
	return 0;
}