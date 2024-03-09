#include <iostream>
#include <utility>
#include <string>
#include "Traitor"

trait(VeryImportantTrait)
{
	trait_fn(bool, increment);
	trait_fn(std::string, to_string);
	trait_fn(void, sayHello, std::string, name);
	trait_sfn(int, GlobalConfig);
};

// impl of printable trait with cat
class Cat : public VeryImportantTrait<Cat>
{
public:
	trait_fn_impl(std::string, to_string)
	{
		return "Meow!";
	}

	trait_fn_impl(void, sayHello, std::string name)
	{
		std::cout << "Hello from cat, to: " << name  << std::endl;
	}
	trait_fn_impl(bool, increment)
	{
		return true;
	}
	trait_sfn_impl(int, GlobalConfig)
	{
		return 1u;
	}
};

class Dog : public VeryImportantTrait<Dog>
{
public:
	trait_fn_impl(std::string, to_string)
	{
		return "Woof!";
	}

	trait_fn_impl(void, sayHello, std::string name)
	{
		std::cout << "Hello from dog, to: " << name  << std::endl;
	}
	trait_fn_impl(bool, increment)
	{
		return true;
	}
	trait_sfn_impl(int, GlobalConfig)
	{
		return 2u;
	}
};

template<typename type>
void do_print(VeryImportantTrait<type>& trait)
{
	std::cout << trait.to_string() << std::endl;
	if (trait.increment())
	{
		std::cout << "Incremented!" << std::endl;
	}
	trait.sayHello("Caller");

	std::cout << "Config: " << VeryImportantTrait<type>::GlobalConfig() << std::endl;
}

int main(int argc, char** argv)
{
	Cat bloem;
	do_print(bloem);
	Dog stijn;
	do_print(stijn);
}

