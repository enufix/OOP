#include <iostream>
using namespace std;

class Forma {
protected:
    float visina;
public:
    Forma(float v = 0) {
        visina = v;
    }

    virtual void pecati() {
        cout << "Forma: " << visina << endl;
    }
    friend ostream& operator<<(ostream &o, const Forma &f) {
        o << "Forma: " << f.visina << endl;
        return o;
    }
    virtual float volumen() const = 0;

    virtual bool osnovaKrug() = 0;

    virtual int type() = 0;

    virtual ~Forma() {
        cout << "Forma destructor" << endl;
    }

    bool operator==(const Forma &f) {
        return volumen() == f.volumen();
    }

};

class Cilinder : public Forma {
private:
    float radius;
public:
    Cilinder(float r = 0, float v = 0) : Forma(v) {
        radius = r;
    }
    void pecati() {
        cout << "Cilinder: " << visina << endl;
        cout << "r: " << radius << endl;
        cout << "V: " << volumen() << endl;
    }

    float volumen() const {
        return radius * radius * 3.14 * visina;
    }
    bool osnovaKrug() {
        return true;
    }

    int type() { return 0; }

    ~Cilinder() {
        cout << "Cilinder destructor" << endl;
    }
};

class Konus : public Forma {
private:
    float radius;
public:
    Konus(float r = 0, float v = 0) : Forma(v) {
        radius = r;
    }
    void pecati() {
        cout << "Konus: " << visina << endl;
        cout << "r: " << radius << endl;
        cout << "V: " << volumen() << endl;
    }

    float volumen() const {
        return radius * radius * 3.14 * visina / 3;
    }
    bool osnovaKrug() {
        return true;
    }

    int type() { return 1; }

    ~Konus() {
        cout << "Konus destructor" << endl;
    }
};

class Kvadar : public Forma {
private:
    float a, b;
public:
    Kvadar(float aa = 0, float bb = 0, float v = 0) : Forma(v) {
        a = aa;
        b = bb;
    }
    void pecati() {
        cout << "Kvadar: " << visina << endl;
        cout << "a: " << a << endl;
        cout << "b: " << b << endl;
        cout << "V: " << volumen() << endl;
    }

    float volumen() const {
        return a * b * visina;
    }
    bool osnovaKrug() {
        return false;
    }

    int type() { return 2; }

    ~Kvadar() {
        cout << "Kvadar destructor" << endl;
    }
};

void najgolemVolumen(Forma **f, int n) {
    Forma *max = f[0];
    for(int i = 1; i < n; ++i) {
        if(f[i]->volumen() > max->volumen()) {
            max = f[i];
        }
    }
    max->pecati();
    //cout << *max;
}

int vkupnoOsnovaKrug(Forma **f, int n) {
    int count = 0;
    for(int i = 0; i < n; ++i) {
        if(f[i]->osnovaKrug()) {
            ++count;
        }
    }
    return count;
}

void daliImaOsnovaKrug(Forma &f) {
    if(f.osnovaKrug()) {
        cout << "DA" << endl;
    } else {
        cout << "NE" << endl;
    }
}

int main() {
    Forma **f;
    int n;
    cin >> n;
    f = new Forma*[n];
    for(int i = 0; i < n; ++i) {
        int type;
        cin >> type;
        float visina;
        if(type == 0) {
            float radius;
            cin >> visina >> radius;
            f[i] = new Cilinder(radius, visina);
        } else if(type == 1) {
            float radius;
            cin >> visina >> radius;
            f[i] = new Konus(radius, visina);
        } else if(type == 2) {
            float a, b;
            cin >> visina >> a >> b;
            f[i] = new Kvadar(a, b, visina);
        }
    }
    
    najgolemVolumen(f, n);
    cout << vkupnoOsnovaKrug(f, n) << endl;
    daliImaOsnovaKrug(*f[0]);
    if(*f[0] == *f[1]) {
        cout << "Ednakvi se 0 i 1" << endl;
    } else {
        cout << "Ne se Ednakvi" << endl;
    }
    for(int i = 0; i < n; ++i) {
        delete f[i];
    }
    delete [] f;
    return 0;
}