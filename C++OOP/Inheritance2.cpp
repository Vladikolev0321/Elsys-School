#include <iostream>
#include <string>
using namespace std;

class Model
{
	string name;
	int capacity;
public:
	Model(string name, int capacity)
	{
		this->name = name;
		this->capacity = capacity;
	}
};
class Container : public Model
{
	string type;
	int serialNumber;
	 


}