#include <iostream>
using namespace std;

class Shape {
protected:
    float height;
public:
    Shape(float h = 0) {
        height = h;
    }

    virtual void print() {
        cout << "I'm a shape" << endl;
    }

    virtual float volume() = 0;

    virtual bool isBaseCircle() = 0;

    float getHeight() {
        return height;
    }

    virtual ~Shape() {
        cout << "Shape destructor" << endl;
    }
};

class Cylinder : public Shape {
private:
    float raduis;
public:
    Cylinder(float h, float r) : Shape(h) {
        raduis = r;
    }
    float volume() {
        return raduis * raduis * 3.14 * height;
    }

    bool isBaseCircle() {
        return true;
    }

    ~Cylinder() {
        cout << "Cylinder destructor" << endl;
    }

    void print() {
        cout << "I'm a cylinder with volume: " << volume() << endl;
    }
};

class Cone : public Shape {
private:
    float raduis;
public:
    Cone(float h, float r) : Shape(h) {
        raduis = r;
    }
    float volume() {
        return raduis * raduis * 3.14 * height / 3.0;
    }

    bool isBaseCircle() {
        return true;
    }

    ~Cone() {
        cout << "Cone destructor" << endl;
    }

    void print() {
        cout << "I'm a cone with volume: " << volume() << endl;
    }
};

class Cuboid : public Shape {
private:
    float width;
    float length;
public:
    Cuboid(float h, float w, float l) : Shape(h) {
        width = w;
        length = l;
    }
    float volume() {
        return height * width * length;
    }

    bool isBaseCircle() {
        return false;
    }

    ~Cuboid() {
        cout << "Cuboid destructor" << endl;
    }

    void print() {
        cout << "I'm a cuboid with volume: " << volume() << endl;
    }
};

void largestShape(Shape **s, int n) {
    Shape *max = s[0];
    for(int i = 1; i < n; ++i) {
        if(s[i]->volume() > max->volume()) {
            max = s[i];
        }
    }
    max->print();
}

int countWithBaseCircle(Shape **s, int n) {
    int count = 0;
    for(int i = 0; i < n; ++i) {
        if(s[i]->isBaseCircle()) {
            ++count;
        }
    }
    return count;
}


int main() {
    int n;
    cin >> n;
    Shape **s = new Shape*[n];
    for(int i = 0; i < n; ++i) {
        int type;
        cin >> type;
        if(type == 0) {
            float raduis, height;
            cin >> raduis >> height;
            s[i] = new Cylinder(height, raduis);
        } else if(type == 1) {
            float raduis, height;
            cin >> raduis >> height;
            s[i] = new Cone(height, raduis);
        } else if(type == 2) {
            float width, height, length;
            cin >> width >> height >> length;
            s[i] = new Cuboid(height, width, length);
        }
    }
    largestShape(s, n);
    cout << "With base circle: " << countWithBaseCircle(s, n) << endl;
    for(int i = 0; i < n; ++i) {
        delete s[i];
    }
    delete [] s;

    Shape *c = new Cylinder(6, 10);
    delete c;
    return 0;
}