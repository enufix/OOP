#include <iostream>
using namespace std;

class Expression {
public:
    virtual double eval() = 0;

    virtual void print() = 0;

    virtual ~Expression() {
    }
};

class BinaryExpression : public Expression {
protected:
    Expression *left;
    Expression *right;
public:
    BinaryExpression(Expression *left, Expression *right) {
        this->left = left;
        this->right = right;
    }

    ~BinaryExpression() {
        delete left;
        delete right;
    }
};

class ValueNode : public Expression {
private:
    double value;
public:
    ValueNode(double value) {
        this->value = value;
    }

    double eval() {
        return value;
    }

    void print() {
        cout << value;
    }
};

class AddExpression : public BinaryExpression {
public:
    AddExpression(Expression *left, Expression *right) 
    : BinaryExpression(left, right) {
    }

    double eval() {
        return left->eval() + right->eval();
    }

    void print() {
        left->print();
        cout << " + ";
        right->print();
    }
};

class MultiplyExpression : public BinaryExpression {
public:
    MultiplyExpression(Expression *left, Expression *right) : BinaryExpression(left, right) {
    }

    double eval() {
        return left->eval() * right->eval();
    }

    void print() {
        left->print();
        cout << " * ";
        right->print();
    }
};

class SubtractExpresion : public BinaryExpression {
public:
    SubtractExpresion(Expression *left, Expression *right)
    : BinaryExpression(left, right) {
    }

    double eval() {
        return left->eval() - right->eval();
    }

    void print() {
        left->print();
        cout << " - ";
        right->print();
    }
};

class DivideExpression : public BinaryExpression {
public:
    DivideExpression(Expression *left, Expression *right)
    : BinaryExpression(left, right) {
    }

    double eval() {
        return left->eval() / right->eval();
    }

    void print() {
        left->print();
        cout << " / ";
        right->print();
    }
};

int main() {
    Expression *e = new SubtractExpresion(
        new AddExpression(
            new MultiplyExpression(
                new ValueNode(2),
                new ValueNode(4)
            ),
            new MultiplyExpression(
                new ValueNode(17),
                new ValueNode(6)
            )
        ),
        new ValueNode(15)
    );
    e->print();
    cout << " = " << e->eval() << endl;
    delete e;
    return 0;
}