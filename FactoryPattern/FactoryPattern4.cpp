#include <stdexcept>
#include <iostream>
#include <string>

using namespace std;

enum class AnimalType {
    CatType,
    DogType,
    SheepType,
    CowType,
};

class Animal {
public:
    virtual void speak() = 0;

    static Animal* of(AnimalType type);
//    static Animal* factoryAnimal(AnimalType type);
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

//추가된 부분 --> Open Close 문제 없음 
class Cow : public Animal {
public:
    virtual void speak() override {
        cout << "음매 음매~~" << endl;
    }
};


Animal* FactoryAnimal(AnimalType type) {
    
    switch(type) {
    case AnimalType::CatType:
        return new Cat();
    case AnimalType::DogType:
        return new Dog();
    case AnimalType::SheepType:
        return new Sheep();
    case AnimalType::CowType:
        //추가된 부분 --> Open Close 문제 있음 -> 단 객체지향 프로그램에서 이것은 예외로 한다
        return new Cow();
    }
    throw exception("객체를 생성할 수 없습니다");
}

Animal* Animal::of(AnimalType type) {
//Animal* Animal::factoryAnimal(AnimalType type) {
        switch (type) {
    case AnimalType::CatType:
        return new Cat();
    case AnimalType::DogType:
        return new Dog();
    case AnimalType::SheepType:
        return new Sheep();
    case AnimalType::CowType:
        //추가된 부분 --> Open Close 문제 있음 -> 단 객체지향 프로그램에서 이것은 예외로 한다
        return new Cow();
    }
    throw exception("객체를 생성할 수 없습니다");
}

class FactoryAnimal {
public:
    static Animal* factoryAnimal(AnimalType type) {
        switch (type) {
        case AnimalType::CatType:
            return new Cat();
        case AnimalType::DogType:
            return new Dog();
        case AnimalType::SheepType:
            return new Sheep();
        case AnimalType::CowType:
            //추가된 부분 --> Open Close 문제 있음 -> 단 객체지향 프로그램에서 이것은 예외로 한다
            return new Cow();
        }
        throw exception("객체를 생성할 수 없습니다");
    }
};

void someA() {
//    Animal* pAnimal = Animal::factoryAnimal(AnimalType::CatType);
    Animal* pAnimal = Animal::of(AnimalType::CatType);

    if (pAnimal) {
        hey(*pAnimal);
        delete pAnimal;
    }
}

void someB() {
//    Animal* pAnimal = FactoryAnimal(AnimalType::CowType);
    Animal* pAnimal = Animal::of(AnimalType::CowType);

    if (pAnimal) {
        hey(*pAnimal);
        delete pAnimal;
    }
}

void main() {
    someA();
    someB();
}

