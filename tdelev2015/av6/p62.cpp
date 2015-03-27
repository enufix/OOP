#include <iostream>
#include <cstring>
using namespace std;

class Statija {
private:
  char naslov[100];
  char avtor[50];
  char *sodrzhina;
  bool objavena;
  void copy(const Statija &s) {
    strcpy(naslov, s.naslov);
    strcpy(avtor, s.avtor);
    sodrzhina = new char[strlen(s.sodrzhina) + 1];
    strcpy(sodrzhina, s.sodrzhina);
    objavena = s.objavena;
  }
public:
  Statija(char *n = "", char *a = "", char *s = "", bool o = false) {
    strcpy(naslov, n);
    strcpy(avtor, a);
    sodrzhina = new char[strlen(s) + 1];
    strcpy(sodrzhina, s);
    objavena = o;
  }

  Statija(const Statija &s) {
    copy(s);
  }

  Statija& operator=(const Statija &s) {
    if (this == &s) return *this;
    delete [] sodrzhina;
    copy(s);
    return *this;
  }

  ~Statija() {
    delete [] sodrzhina;
  }

  void pecati() {
    cout << naslov << endl;
    cout << avtor << endl;
    cout << sodrzhina << endl;
  }

  int dolzina() {
    return strlen(sodrzhina);
  }

  bool eAvtor(char *a) {
    return strcmp(avtor, a) == 0;
  }
};

class Vesnik {
private:
  char ime[100];
  Statija *s;
  int n;
  Statija prva;
  void copy(const Vesnik &v) {
    strcpy(ime, v.ime);
    n = v.n;
    s = new Statija[n];
    for (int i = 0; i < n; ++i) {
      s[i] = v.s[i];
    }
    prva = v.prva;
  }
public:
  Vesnik(char *i = "") {
    strcpy(ime, i);
    s = NULL;
    n = 0;
  }

  Vesnik(const Vesnik &v) {
    copy(v);
  }

  Vesnik& operator=(const Vesnik &v) {
    if (this == &v) return *this;
    delete [] s;
    copy(v);
    return *this;
  }

  ~Vesnik() {
    delete [] s;
  }

  void dodadiStatija(Statija x) {
    if (n == 0) {
      prva = x;
    }
    Statija* temp = s;
    s = new Statija[n + 1];
    for (int i = 0; i < n; ++i) {
      s[i] = temp[i];
    }
    delete [] temp;
    s[n] = x;
    n++;
  }

  void pecatiNajdolga() {
    int max = 0;
    int maxi = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i].dolzina() > max) {
        max = s[i].dolzina();
        maxi = i;
      }
    }
    s[maxi].pecati();
  }

  void pecatiPrva() {
    prva.pecati();
  }

  int vkupnoOdAvtor(char *avtor) {
    int vkupno = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i].eAvtor(avtor)) {
        ++vkupno;
      }
    }
    return vkupno;
  }
};

int main() {
  char naslov[100], avtor[50], sodrzina[100];
  int n;
  cin >> n;
  char ime[100];
  cin.getline(ime, 100);
  cin.getline(ime, 100);
  Statija prva("VAZNO", "OOP", "Vezba:OOP", true);
  Vesnik v(ime);
  v.dodadiStatija(prva);
  //Statija *s = new Statija[n];
  for (int i = 0; i < n; ++i) {
    cin.getline(naslov, 100);
    cin.getline(avtor, 50);
    cin.getline(sodrzina, 100);
    v.dodadiStatija(Statija(naslov, avtor, sodrzina, true)); //se koristi copy konstruktor
  }
  v.pecatiPrva();
  v.pecatiNajdolga();
  cout << v.vkupnoOdAvtor(avtor) << endl;
  //delete [] s;
  return 0;
}