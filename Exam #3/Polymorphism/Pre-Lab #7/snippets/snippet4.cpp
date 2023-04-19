#include <iostream>
#include <vector>

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

class Cat : public Animal {
    bool sleepy;
    public:
        Cat(string givenName, int currentAge) : Animal(givenName, currentAge) {
            sleepy = true; 
        }
};

class Penguin : public Animal {
    bool chilly;
    public:
        Penguin(string givenName, int currentAge) : Animal(givenName, currentAge) {
            chilly = true; 
        }
        void eat() {
            cout << "*happy penguin noises*" << endl;
        }
};

class Barn {
    vector<Animal*> barn;
    public:
        void addAnimal(Animal *animal) {
            barn.push_back(animal);
        }
        void feedAnimals() {
            for(int i = 0; i < barn.size(); i++) {
                barn[i]->eat();
            }
        }
};

int main() {
    Dog* guardDog = new Dog("Max", 5);
    Cat* blackCat = new Cat("Meowster", 3);
    Penguin* happyFeet = new Penguin("Meep", 6);

    Barn* upstateBarn = new Barn();

    upstateBarn->addAnimal(guardDog);
    upstateBarn->addAnimal(blackCat);
    upstateBarn->addAnimal(happyFeet);

    upstateBarn->feedAnimals();

    return 0;
}