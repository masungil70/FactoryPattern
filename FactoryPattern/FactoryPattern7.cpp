#include <stdexcept>
#include <iostream>
#include <memory>
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
    virtual ~Animal() {
        cout << "Animal() 소멸자 호출\n";
    }
    virtual void speak() = 0;

    static shared_ptr<Animal> of(AnimalType type);
    //    static Animal* factoryAnimal(AnimalType type);
};

void hey(Animal& animal) {
    animal.speak();
}

class Cat : public Animal {
private:
    struct _aCat {};
public:
    Cat(_aCat obj) {
    }
    ~Cat() {
        cout << "Cat() 소멸자 호출\n";
    }
    static shared_ptr<Animal> createAnimal() {
        return make_shared<Cat>(_aCat{});
    }
    virtual void speak() override {
        cout << "야옹~~~" << endl;
    }
};

class Dog : public Animal {
private:
    Dog() {}
public:
    ~Dog() {
        cout << "Dog() 소멸자 호출\n";
    }

    static shared_ptr<Animal> createAnimal() {
        return make_shared<Dog>();
    }
    virtual void speak() override {
        cout << "멍멍멍~~~" << endl;
    }
};

class Sheep : public Animal {
private:
    Sheep() {}
public:
    ~Sheep() {
        cout << "Sheep() 소멸자 호출\n";
    }
    static shared_ptr<Animal> createAnimal() {
        return make_shared<Sheep>();
    }
    virtual void speak() override {
        cout << "매~~ 매~~" << endl;
    }
};

//추가된 부분 --> Open Close 문제 없음 
class Cow : public Animal {
private:
    Cow() {}
public:
    ~Cow() {
        cout << "Cow() 소멸자 호출\n";
    }
    static shared_ptr<Animal> createAnimal() {
        return make_shared<Cow>();
    }
    virtual void speak() override {
        cout << "음매 음매~~" << endl;
    }
};


shared_ptr<Animal> FactoryAnimal(AnimalType type) {

    switch (type) {
    case AnimalType::CatType:
        return Cat::createAnimal();
    case AnimalType::DogType:
        return Dog::createAnimal();
    case AnimalType::SheepType:
        return Sheep::createAnimal();
    case AnimalType::CowType:
        return Cow::createAnimal();
    }
    throw exception("객체를 생성할 수 없습니다");
}

shared_ptr<Animal> Animal::of(AnimalType type) {
    //Animal* Animal::factoryAnimal(AnimalType type) {
    switch (type) {
    case AnimalType::CatType:
        return Cat::createAnimal();
    case AnimalType::DogType:
        return Dog::createAnimal();
    case AnimalType::SheepType:
        return Sheep::createAnimal();
    case AnimalType::CowType:
        //추가된 부분 --> Open Close 문제 있음 -> 단 객체지향 프로그램에서 이것은 예외로 한다
        return Cow::createAnimal();
    }
    throw exception("객체를 생성할 수 없습니다");
}

class FactoryAnimal {
public:
    static shared_ptr<Animal> factoryAnimal(AnimalType type) {
        switch (type) {
        case AnimalType::CatType:
            return Cat::createAnimal();
        case AnimalType::DogType:
            return Dog::createAnimal();
        case AnimalType::SheepType:
            return Sheep::createAnimal();
        case AnimalType::CowType:
            //추가된 부분 --> Open Close 문제 있음 -> 단 객체지향 프로그램에서 이것은 예외로 한다
            return Cow::createAnimal();
        }
        throw exception("객체를 생성할 수 없습니다");
    }
};

void someA() {
    //    Animal* pAnimal = Animal::factoryAnimal(AnimalType::CatType);
        //Animal* pAnimal = Animal::of(AnimalType::CatType);

        //if (pAnimal) {
        //    hey(*pAnimal);
        //    delete pAnimal;
        //}
    shared_ptr<Animal> pAnimal(Animal::of(AnimalType::CatType));
    if (pAnimal) {
        hey(*pAnimal);
    }
}

void someB() {
    //    Animal* pAnimal = FactoryAnimal(AnimalType::CowType);
    shared_ptr<Animal> pAnimal = Animal::of(AnimalType::CowType);

    if (pAnimal) {
        hey(*pAnimal);
    }
}

int main() {
    shared_ptr<Animal> pCat = Cat::createAnimal();

    shared_ptr<Animal> p = Animal::of(AnimalType::CowType);
    p->speak();

    //    someA();
    //    someB();

    return 0;
}

