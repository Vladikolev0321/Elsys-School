#include <iostream>
#include <string>
using namespace std;
class Model
{
protected:
	string name;
	int capacity;
public:
	Model(){};
	Model(string name, int capacity)
	{
		this->name = name;
		this->capacity = capacity;
	}
static void produce(string name, int capacity, string type, string serialNumber)
{
	return Container(string name, int capacity, string type, string serialNumber);
}
};
class Container:public Model
{
	string type;
	string serialNumber;
public:
	Container(){};
	Container(string name, int capacity, string type, string serialNumber):Model(name,capacity)
	{
		this->type = type;
		this->serialNumber = serialNumber;
	}
	string get_serialNumber()
	{
		return serialNumber;
	}
};
class Set
{
	Container saltContainer;
	Container piperContainer;
	string serialNumberOfComplect;
public:
	Set(Container saltContainer, Container piperContainer)
	{
		this->saltContainer = saltContainer;
		this->piperContainer = piperContainer;
		this->serialNumberOfComplect = saltContainer.get_serialNumber() + ":" + piperContainer.get_serialNumber();
	}
};

/*Set Container::operator+(Container container)
{
	return Set(this, container);
}
*/
int main()
{


	return 0;
}