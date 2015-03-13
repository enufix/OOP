#include <iostream>
#include <cstring>
using namespace std;

class Datum {
private:
	int den, mesec, godina;
public:
	Datum(int d = 0, int m = 0, int g = 0) {
		den = d;
		mesec = m;
		godina = g;
	}

	bool pred(Datum d) {
		if(godina < d.godina) return true;
		else if(godina > d.godina) return false;
		else if(mesec < d.mesec) return true;
		else if(mesec > d.mesec) return false;
		else return den < d.den;
	}

	void pechati() {
		cout << den << "." << mesec << "." << godina << endl;
	}
};
class Vraboten {
private:
	char ime[100];
	float plata;
	Datum roden;
public:
	Vraboten(char *i = "", float p = 0, Datum d = Datum()) {
		strcpy(ime, i);
		plata = p;
		roden = d;
	}

	float getPlata() {
		return plata;
	}

	Datum getRoden() {
		return roden;
	}

	void pechati() {
		cout << ime << " : " << plata << endl;
		cout << "Roden: ";
		roden.pechati();
	}
};

Vraboten najplaten(Vraboten v[], int n) {
	Vraboten max = v[0];
	for(int i = 0; i < n; ++i) {
		if(v[i].getPlata() > max.getPlata()) {
			max = v[i];
		}
	}
	return max;
}

Vraboten najmlad(Vraboten v[], int n) {
	Vraboten min = v[0];
	for(int i = 0; i < n; ++i) {
		if(min.getRoden().pred(v[i].getRoden())) {
			min = v[i];
		}
	}
	return min;
}

int main() {
	Vraboten v[20];
	char ime[100];
	float plata;
	int den, mesec, godina;
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> ime >> plata >> den >> mesec >> godina;
		Datum d(den, mesec, godina);
		v[i] = Vraboten(ime, plata, d);
	}
	Vraboten np = najplaten(v, n);
	Vraboten nm = najmlad(v, n);
	np.pechati();
	nm.pechati();
	return 0;

}