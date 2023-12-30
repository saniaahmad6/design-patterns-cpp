#include <bits/stdc++.h>

using namespace std;
enum class Operation {
    ADD,SUB,MULT
};
class ArithmeticExpression{
    public: 
        virtual int evaluate () = 0;
        virtual ~ArithmeticExpression(){};
};

class Number : public ArithmeticExpression {
    int value;
    public: 
        ~Number(){};
        Number(int value) : value(value) {}
        int evaluate() {
            return value;
        }
};

class Expression : public ArithmeticExpression {
    ArithmeticExpression * left;
    ArithmeticExpression * right;
    Operation op;
    public:
    Expression (ArithmeticExpression *left,ArithmeticExpression *right,Operation op) {
        this->left=left;
        this->right=right;
        this->op=op;
    }

    int evaluate(){
        if (this->op==Operation::MULT){
            return left->evaluate() * right->evaluate();
        } 
        if (this->op==Operation::ADD){
            return left->evaluate() + right->evaluate();
        } 
        if (this->op==Operation::SUB){
            return left->evaluate() - right->evaluate();
        }
        return 0;
    }
    ~Expression(){};

};

int main(){
    ArithmeticExpression * x=new Number(2);
    ArithmeticExpression * y=new Number(5);
    ArithmeticExpression * z=new Number(7);
    ArithmeticExpression * expr = new Expression(x,y,Operation::MULT);
    expr= new Expression(expr,z,Operation::ADD);
    cout<<expr->evaluate();
    return 0;
}