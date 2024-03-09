#include <iostream>
#include <utility>

// Simplest sort of static interface?
// this could act as a  to_string trait interface right?

class Cat
{
public:
	static std::string to_string()
	{
		return "Meow!";
	}
};

class Dog
{
public:
	static std::string to_string()
	{
		return "Woof!";
	}
};

template<typename value>
void print()
{
	std::cout << value::to_string() << std::endl;
}

int main(int argc, char** argv)
{
	Cat cat;
	print<decltype(cat)>();
	Dog dog;
	print<decltype(dog)>();
}

