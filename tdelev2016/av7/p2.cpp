#include <iostream>
using namespace std;
enum Color {
    RED,
    GREEN,
    BLUE
};

class Shape {
protected:
    Color color;
public:
    Shape(Color c) {
        color = c;
    }
    virtual void draw() = 0;
    virtual ~Shape() {
    }
};

class Circle : public Shape {
private:
    int x, y;
    float radius;
public:
    Circle(int xx, int yy, float r, Color color) 
    : Shape(color) {
        x = xx;
        y = yy;
        radius = r;
    }

    void draw() {
        cout << "Drawing circle with position: " << x << ", " << y;
        cout << " and color: " << color;
        cout << endl;
    }

};

class Rectangle : public Shape {
private:
    int x, y;
    float a, b;
public:
    Rectangle(int xx, int yy, float aa, float bb, Color color) 
    : Shape(color) {
        x = xx;
        y = yy;
        a = aa;
        b = bb;
    }

    void draw() {
        cout << "Drawing rectangle with position: " << x << ", " << y;
        cout << " side a: " << a << " side b: " << b;
        cout << " and color: " << color;
        cout << endl;
    }
};

void drawShapes(Shape *shapes[], int n) {
    for(int i = 0; i < n; ++i) {
        shapes[i]->draw();
    }
}

void drawShape(Shape &s) {
    s.draw();
}

int main() {
    Shape **shapes = new Shape*[2];
    shapes[0] = new Circle(5, 7, 15, GREEN);
    shapes[1] = new Rectangle(1, 6, 20, 35, RED);
    /*Circle circle(4, 2, 10, RED);
    shapes[0] = &circle;
    Rectangle rectangle(3, 3, 15, 20, BLUE);
    shapes[1] = &rectangle;*/
    drawShape(*shapes[0]);
    drawShape(*shapes[1]);

    drawShapes(shapes, 2);
    delete shapes[0];
    delete shapes[1];
    delete [] shapes;
    return 0;

}