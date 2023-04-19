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

int main() {
    Animal* unidentifiedAnimal = new Animal("Subject X", 1000);
    Penguin* happyFeet = new Penguin("Pengu", 5);
    
    unidentifiedAnimal->eat();
    happyFeet->eat();
    
    return 0;
}