#include <iostream>
#include <string>
#include <string.h>
#include <list>
#include <queue>
using namespace std;

class Product{
public:
	Product(){};
	Product(string str,int quantity)
	{
		this->name = str;
		this->quantity = quantity;
	}
	string name;
	int quantity;
};

class Order{
public:
	Order(){};
	Order(Product product)
	{	
		this->product = product;
		this->isFinished = 0;
	}	
	Product product;
	int isFinished;
};
class Factory{
public:
	Factory()
	{
		this->size = 0;
	}
	list<Product> products;
	int size;
	void pushProduct(Product product)
	{
		this->products.push_back(product);
		this->size++;
	}

};

int main()
{
	Factory factory;
	factory.pushProduct(Product("cheese",2));
	factory.pushProduct(Product("meat",2));



	queue <Order> orders;
	list <Order> finishedOrders;
	list <Order> unfinishedOrders;
	

	string command;
	getline(cin,command);

	////Inputting orders
	//while(strcmp(command,"stop") == 0)
	while(command != "stop")
	{	cout<<"in"<<endl;
		string name = command;
		int quantity;
		cin>>quantity;

		Product product(name,quantity);
		Order order(product);
		
		orders.push(order);
		
		//getline(cin,command);
		cin>>command;
	}

	////Processing orders
	while(!orders.empty())
	{	
		Order order = orders.front();

		std::list<Product>::iterator it;
		for (it = factory.products.begin(); it != factory.products.end(); ++it){
    		if(it->name == order.product.name)
			{
				order.isFinished = 1;
			}
		}

		if(order.isFinished == 1)
		{
			finishedOrders.push_back(order);
		}
		else
		{
			unfinishedOrders.push_back(order);
		}

		orders.pop();

	}


	std::list<Order>::iterator it;
		for (it = finishedOrders.begin(); it != finishedOrders.end(); ++it){
    		cout<<(*it).product.name<<endl;
		}	




}

