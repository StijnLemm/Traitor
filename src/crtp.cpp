#include <iostream>
#include <utility>
#include <string>

// Simplest sort of static interface?
// this could act as a  to_string trait interface right?

template<typename child>
struct VeryImportantTrait
{
	bool increment()
	{
		return as_underlying().increment();
	}
	std::string to_string() 
	{
		return as_underlying().to_string();
	}
	void sayHello() 
	{
		return as_underlying().sayHello();
	}
	private:

	inline child & as_underlying()
	{
		return static_cast<child&>(*this);
	}
};

// impl of printable trait with cat
class Cat : public VeryImportantTrait<Cat>
{
public:
	std::string to_string()
	{
		return "Meow!";
	}
	void sayHello()
	{
		std::cout << "Hello from cat!" << std::endl;
	}
	bool increment()
	{
		return true;
	}
};

class Dog : public VeryImportantTrait<Dog>
{
public:
	std::string to_string() const
	{
		return "Woof!";
	}
	void sayHello()
	{
		std::cout << "Hello from dog!" << std::endl;
	}
	bool increment()
	{
		return false;
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
	trait.sayHello();
}

int main(int argc, char** argv)
{
	Cat bloem;
	do_print(bloem);
	Dog stijn;
	do_print(stijn);
}

