# Traitor
trying stuff with traits and templats lol. This is what i came up with for now!
``` c++
#include "Traitor"

trait(StringAble)
{
	trait_fn(std::string, toString)
};

trait(Updatable)
{
	trait_fn(void, update)
};

struct NameContainer
{
	std::string name;
	size_t updateCounter = 0u;
};

impl(NameContainer, StringAble)
{
	trait_fn_impl(std::string, toString)
	{
	    return this->name;
	}
};

impl(NameContainer, Updatable)
{
	trait_fn_impl(void, update)
	{
	    this->updateCounter++;
	}
};

template<typename type>
void print(StringAble<type>& tr)
{
	std::cout << tr.toString() << std::endl;
}

template<typename type>
void update(Updatable<type>& up)
{
	up.update();
}

int main()
{
	NameContainer container;
	container.name = "I have my own traits!";
	print(impl_of(NameContainer, StringAble, container));
	update(impl_of(NameContainer, Updatable, container));
	update(impl_of(NameContainer, Updatable, container));
	update(impl_of(NameContainer, Updatable, container));
	
	std::cout << "I updated " << container.updateCounter << " times." << std::endl; 
}
```
