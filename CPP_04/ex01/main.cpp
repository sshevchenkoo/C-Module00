#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void check_leaks()
{
	system("leaks animal");
}

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;

	const Animal *animals[4] = {new Dog(), new Dog(), new Cat(), new Cat()};
    int d = 0;
	while(d < 4)
    {
		delete animals[d];
        d++;
    }

	atexit(check_leaks);
	
	return 0;
}
