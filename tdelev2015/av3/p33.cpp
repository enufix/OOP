#include <iostream>
#include <cstring>
using namespace std;

enum pozicija
{
	vraboten,
	direktor,
	shef
};
class Vraboten {
private:
	char ime[100];
	float plata;
	pozicija poz;

public:

	Vraboten(char *ime = "John Doe",
	 float plata = 10000, pozicija poz = vraboten) {
		strcpy(this->ime, ime);
		this->plata = plata;
		this->poz = poz;
	}

	float getPlata() {
		return plata;
	}
	char* getIme() {
		return ime;
	}
	char* getPozicija() {
		if(poz == vraboten) {
			return "vraboten";
		} else if(poz == direktor) {
			return "direktor";
		} else if(poz == shef) {
			return "shef";
		}
	}


};

void sort(Vraboten v[], int n) {
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n - 1 - i; ++j) {
			if(v[j].getPlata() < v[j + 1].getPlata()) {
				Vraboten temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
			}
		}
	}
}

int main() {
	Vraboten v[100];
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		char ime[100];
		float plata;
		int p;
		cin >> ime >> plata >> p;
		pozicija poz;
		if(p == 0) {
			poz = vraboten;
		} else if(p == 1) {
			poz = direktor;
		} else if(p == 2) {
			poz = shef;
		}
		v[i] = Vraboten(ime, plata, poz);
	}
	sort(v, n);
	for(int i = 0; i < n; ++i) {
		cout << v[i].getIme() << '\t' << v[i].getPozicija() << '\t';
		cout << v[i].getPlata() << endl;
	}
	return 0;
}