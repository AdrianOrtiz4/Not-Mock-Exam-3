#include <iostream>

using namespace std;

class Animal {
    string name;
    int age;
    public:
        Animal(string givenName, int currentAge) {
            name = givenName;
            age = currentAge;
        }
        virtual void eat() {
            cout << "Yum!" << endl;
        }
};

class Dog : public Animal {
    bool good;
    public:
        Dog(string givenName, int currentAge) : Animal(givenName, currentAge) {
            good = true; 
        }
        void bark() {
            cout << "Bark Bark!" << endl;
        }
};

class Corgi : public Dog {
    bool dapperBoy;
    public:
        Corgi(string givenName, int currentAge, bool isDapper) : 
        Dog(givenName, currentAge) {
            dapperBoy = isDapper;
        }
};

int main() {
    Animal* unidentifiedAnimal = new Animal("Subject X", 1000);
    Dog* cuteStray = new Dog("Rufus", 3);
    Corgi* dapperDoggo = new Corgi("Robert", 2, true);
    
    unidentifiedAnimal -> eat();
    cuteStray -> eat();
    cuteStray -> bark();
    dapperDoggo -> eat();
    dapperDoggo -> bark();
    
    return 0;
}