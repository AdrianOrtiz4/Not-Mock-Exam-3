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
        void eat() {
            cout << "Yum!" << endl;
        }
};

class Dog : public Animal {
    bool good;
    public:
        Dog(string givenName, int currentAge) : Animal(givenName, currentAge) {
            good = true; 
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
};

int main() {
    Dog* guardDog = new Dog("Rufus", 2);
    Cat* blackCat = new Cat("Mittens", 1);
    Penguin* happyFeet = new Penguin("Pengu", 5);
    
    guardDog->eat();
    blackCat->eat();
    happyFeet->eat();
    
    return 0;
}