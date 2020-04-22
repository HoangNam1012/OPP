#include <iostream> 
using namespace std;
class Pet {
	public:
		virtual void say() = 0;
};
class Cat: public Pet {
	public:
	virtual void say()
	{ 
		cout << "miao\n"; 
	}
};
class Dog: public Pet {
	public:
	virtual void say()
	{ 
		cout << "gruh\n"; 
	}
};

int main()
{
	Pet* p[3] = {
	new Dog(), new Cat(), new Cat() };
	for (int i=0; i<3; i++)
	p[i]->say();
	// ...
	// Th? này không du?c:
	// Pet p2[2] = { Dog(), Cat() };
	// ...
}
