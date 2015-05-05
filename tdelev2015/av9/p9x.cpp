#include <iostream>
using namespace std;

class Expression {
public:
    virtual double eval() = 0;
    virtual void print() = 0;
    virtual ~Expression() {
    }
};

class Value : public Expression {
private:
    double value;
public:
    Value(double v) {
        value = v;
    }
    double eval() {
        return value;
    }
    void print() {
        cout << value;
    }
};

class BinaryExpression : public Expression {
protected:
    Expression *left;
    Expression *right;
public:
    BinaryExpression(Expression *l, Expression *r) {
        left = l;
        right = r;
    }

    virtual ~BinaryExpression() {
        delete left;
        delete right;
    }
};

class Multiplication : public BinaryExpression {
public:
    Multiplication(Expression *left, Expression *right) :
    BinaryExpression(left, right){}

    double eval() {
        return left->eval() * right->eval();
    }

    void print() {
        left->print();
        cout << " * ";
        right->print();
    }

};

class Addition : public BinaryExpression {
public:
    Addition(Expression *left, Expression *right) :
    BinaryExpression(left, right){}

    double eval() {
        return left->eval() + right->eval();
    }

    void print() {
        left->print();
        cout << " + ";
        right->print();
    }

};

class Substraction : public BinaryExpression {
public:
    Substraction(Expression *left, Expression *right) :
    BinaryExpression(left, right){}

    double eval() {
        return left->eval() - right->eval();
    }

    void print() {
        left->print();
        cout << " - ";
        right->print();
    }

};

class Division : public BinaryExpression {
public:
    Division(Expression *left, Expression *right) :
    BinaryExpression(left, right){}

    double eval() {
        double r = right->eval();
        if(r == 0) throw 1;
        return left->eval() / right->eval();
    }

    void print() {
        left->print();
        cout << " / ";
        right->print();
    }

};

int main() {
    Expression *e = new Addition(
        new Multiplication(
            new Value(2), new Value(3)
        ),
        new Value(4)
    );
    e->print();
    cout << endl;
    cout << "Result: " << e->eval() << endl;
    Expression *e2 = new Division(
        new Substraction(
            new Value(5), new Value(1)
        ),
        new Multiplication(
            new Value(8), new Addition(
                new Value(5), new Value(3)
            )
        )
    );
    e2->print();
    cout << endl;
    try{
        cout << "Result: " << e2->eval() << endl;
    } catch(int ex) {
        if(ex == 1) {
            cout << "Division by zero" << endl;
        }
    }
    delete e;
    delete e2;
    return 0;
}