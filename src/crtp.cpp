#include <iostream>
#include <utility>
#include <string>

// macro induced trait system c++
// todo, const qualifiers?

// Create function arguments
#define ARGS_0()            void
#define ARGS_1()            void
#define ARGS_2(t1,v1)        t1 v1
#define ARGS_4(t1,v1,t2,v2)  t1 v1, t2 v2
#define ARGS_N(_4,_3,_2,_1,_0,N,...)   ARGS##N
#define ARGS(...)   ARGS_N(_0,##__VA_ARGS__,_4,_3,_2,_1,_0)(__VA_ARGS__)

// Pass arguments to printf with a leading comma.
#define PASS_0()
#define PASS_2(t1,v1)       , v1        
#define PASS_4(t1,v1,t2,v2) , v1, v2
#define PASS_N(_4,_3,_2,_1,_0,N,...)  PASS##N
#define PASS(...)  PASS_N(_0,##__VA_ARGS__,_4,_3,_2,_1,_0)(__VA_ARGS__)

#define TRAIT(name) 											\
template<typename Child> 										\
struct name 												\

#define TRAIT_FN(rettype, name, args...)								\
rettype name(ARGS(__VA_ARGS__)) { return static_cast<Child&>(*this).name##_impl(PASS(__VA_ARGS__)); } 	\

#define TRAIT_FN_IMPL(rettype, name, args...)								\
rettype name##_impl(args...) 										\

#define TRAIT_SFN(rettype, name, args...)								\
static rettype name(args...) { return static_cast<Child&>(*this)::name##_impl(args); }			\

#define TRAIT_SFN_IMPL(rettype, name, args...)	\
static rettype name##_impl(args...) 		\

TRAIT(VeryImportantTrait)
{
	TRAIT_FN(bool, increment, int, type);
	TRAIT_FN(std::string, to_string);
	TRAIT_FN(void, sayHello, std::string name);
	TRAIT_SFN(int, GlobalConfig);
};

// impl of printable trait with cat
class Cat : public VeryImportantTrait<Cat>
{
public:
	TRAIT_FN_IMPL(std::string, to_string)
	{
		return "Meow!";
	}

	TRAIT_FN_IMPL(void, sayHello, std::string name)
	{
		std::cout << "Hello from cat, to:" << name  << std::endl;
	}
	TRAIT_FN_IMPL(bool, increment)
	{
		return true;
	}
	TRAIT_SFN_IMPL(int, GlobalConfig)
	{
		return 1u;
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
	TRAIT_FN_IMPL(bool, increment)
	{
		return false;
	}
	static int GlobalConfig()
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
	trait.sayHello();

	std::cout << "Config: " << VeryImportantTrait<type>::GlobalConfig() << std::endl;
}

int main(int argc, char** argv)
{
	Cat bloem;
	do_print(bloem);
	Dog stijn;
	do_print(stijn);
}

