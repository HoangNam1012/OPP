#include <iostream>
using namespace std;
 
class Pet {
protected:
    string Name;
public:
    Pet(string n) { Name = n; }
    virtual string getSound() { return "";};
    void makeSound(void) { cout << Name << "says: " << getSound() << endl; }
};
 
class Cat : public Pet {
public:
    Cat(string n) : Pet(n) { }
    string getSound() { return "Meow! Meow!";};
};
 
class Dog : public Pet {
public:
    Dog(string n) : Pet(n) { }
    string getSound() { return "Woof! Woof!";};
};
 
int main(void) {
    Pet *a_pet = new Cat("Kitty");;
    a_pet->makeSound();
 
    a_pet = new Dog("Doggie");
    a_pet->makeSound();
    
    
 
    return 0;
}
