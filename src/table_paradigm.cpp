#include <iostream>
#include <utility>

// Simplest sort of static interface?
// this could act as a  to_string trait interface right?

struct CatStore
{
	std::string name;
	int age;
};

struct DogStore
{
	std::string name;
	int age;
};

static std::string to_string()
{
	return "Meow!";
}

template<typename value>
void print()
{
	std::cout << value::to_string() << std::endl;
}

int main(int argc, char** argv)
{
	// Cat bloem;
	// print<decltype(bloem)>();
	// Dog stijn;
	// print<decltype(stijn)>();
}

