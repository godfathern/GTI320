#include <iostream>
class A {
private:
    int a;

public:
    //Constructor:
    A(int value) {
        a = value;
    }

    void setA(int value) {
        a = a * value;
    }

    int getA() {
        return a;
    }

};

int main() {

    A a(5);
    a.setA(10);
    std::cout<<"value of a " << a.getA() << std::endl;


    return 0;
}