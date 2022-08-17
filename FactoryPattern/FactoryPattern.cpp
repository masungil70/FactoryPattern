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

class Cow : public Animal {
public:
    virtual void speak() override {
        cout << "움매~~ 움매~~" << endl;
    }
};

void someA() {
    Animal* pAnimal = nullptr;
    int type = 0;
    if (0 == type) {
        pAnimal = new Cat();
    }
    else if (2 == type) {
        pAnimal = new Sheep();
    }

    if (pAnimal) {
        hey(*pAnimal);
        delete pAnimal;
    }
}

void someB() {
    Animal* pAnimal = nullptr;
    int type = 1;
    if (0 == type) {
        pAnimal = new Cat();
    }
    else if (1 == type) {
        pAnimal = new Dog();
    }

    if (pAnimal) {
        hey(*pAnimal);
        delete pAnimal;
    }
}

//고객의 요청으로 Cow 클래스를 추가해 달라고함 
//이것을 해결하는 방법

void main() {
    someA();
    someB();
}

