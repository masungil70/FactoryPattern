#include <stdexcept>
#include <iostream>
#include <string>

using namespace std;

class Animal {
public:
    virtual void speak() = 0;
};

void hey(Animal& animal) {
    animal.speak();
}

class Cat : public Animal {
public:
    virtual void speak() override {
        cout << "야옹~~~" << endl;
    }
};

class Dog : public Animal {
public:
    virtual void speak() override {
        cout << "멍멍멍~~~" << endl;
    }
};

class Sheep : public Animal {
public:
    virtual void speak() override {
        cout << "매~~ 매~~" << endl;
    }
};

Animal* FactoryAnimal(int type) {
    
    switch(type) {
    case 0:
        return new Cat();
    case 1:
        return new Dog();
    case 2:
        return new Sheep();
    }
    throw exception("객체를 생성할 수 없습니다");
}

void someA() {
    int type = 0;
    Animal* pAnimal = FactoryAnimal(type);

    if (pAnimal) {
        hey(*pAnimal);
        delete pAnimal;
    }
}

void someB() {
    int type = 1;
    Animal* pAnimal = FactoryAnimal(type);

    if (pAnimal) {
        hey(*pAnimal);
        delete pAnimal;
    }
}

void main() {
    someA();
    someB();
}

