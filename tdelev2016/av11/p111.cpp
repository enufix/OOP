#include <iostream>
#include <cstring>
using namespace std;

class Flower {
protected:
    char name[100];
    int basePrice;
    char type[100];
public:
    Flower(const char *n, int p, const char *t) {
        strcpy(name, n);
        basePrice = p;
        strcpy(type, t);
    }
    bool operator==(Flower &f) {
        return strcmp(type, f.type) == 0;
    }
    friend ostream& operator<<(ostream &out, const Flower &f) {
        out << f.name << " " << f.type << " " << f.price();
        return out;
    }

    virtual int price() const = 0;
    virtual ~Flower() {}
};

class PotFlower : public Flower {
private:
    int bloomed;
public:
    PotFlower(const char *n, int p, const char *t, int b) :
    Flower(n, p, t) {
        bloomed = b;
    }

    int price() const {
        return basePrice + bloomed;
    }
};

class CutFlower : public Flower {
private:
    int days;
public:
    CutFlower(const char *n, int p, const char *t, int d)
    : Flower(n, p, t) {
        days = d;
    }

    int price() const {
        if(days < 10) return basePrice + 20;
        if(days < 35) return basePrice + 10;
        return basePrice;
    }
};

void specialFlowers(Flower **f, int n, Flower &c) {
    Flower* max;
    int m;
    for(int i = 0; i < n; ++i) {
        if(*f[i] == c) {
            max = f[i];
            m = i;
            break;
        }
    }
    for(int i = m; i < n; ++i) {
        if(f[i]->price() > max->price()
          && *f[i] == c) {
            max = f[i];
        }
    }
    cout << *max << endl;
}



int main() {

    char name[10], kind[10];
    int type, age, num, price;
    int n;
    cin >> n;
    Flower **flowers;
    flowers = new Flower*[n];

    for (int i = 0; i < n; i++) {

        cin >> type >> name >> price >> kind;
        if (type == 1) {
            cin >> age;
            flowers[i] = new CutFlower(name, price, kind, age);

        }
        else {
            cin >> num;
            flowers[i] = new PotFlower(name, price, kind, num);
        }


    }

    CutFlower nov("opuntia", 90, "cactus", 10);
    specialFlowers(flowers, n, nov);

    for (int i = 0; i < n; i++) delete flowers[i];
    delete [] flowers;
    return 0;
}
