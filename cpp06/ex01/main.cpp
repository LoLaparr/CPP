#include "Serializer.hpp"

int main()
{
	Data data = {"Hello", 42, "World"};
	uintptr_t raw = Serializer::serialize(&data);
	Data *ptr = Serializer::deserialize(raw);

	std::cout << "raw = " << raw << std::endl;
	std::cout << "ptr->s1 = " << ptr->s1 << std::endl;

	return (0);
}
