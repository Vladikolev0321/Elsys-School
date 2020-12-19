#include <iostream>
#include <string>
#include <list>
#include <queue>
using namespace std;

class Product{
public:
	Product(){};
	Product(string name,int quantity){
		this->name = name;
		this->quantity = quantity;
	}
	string name;
	int quantity;
};
class Order{
public:
	Order(){};
	Order(Product product){
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
	};
	Factory(list<Product> products)
	{
		this->products = products;
	};
	list<Product> products;
	int size;
	void push_Product(Product product)
	{
		this->products.push_back(product);
		this->size++;
	}
	bool can_produce(Product product)
	{
		list<Product>::iterator it;
		for(it = products.begin();it != products.end();it++)
		{	
			Product currProd = *it;
			if(currProd.name == product.name && currProd.quantity >= product.quantity){
				return true;
			}
			
		}
		return false;

	}
};
int main()
{
	list<Factory> factories;
	factories.push_back(
    Factory(
      list<Product>({
        Product("chair", 10),
        Product("table", 5),
        Product("sofa", 3)
      })
    )
  );
	factories.push_back(
    Factory(
      list<Product>({
        Product("eggs", 10),
        Product("cheese", 5),
        Product("sofa", 3)
      })
    )
  );
	

	//factory.push_Product(Product("cheese",4));
	//factory.push_Product(Product("meat",4));
	//factory.push_Product(Product("eggs",4));

	queue<Order> orders;
	list<Order> finishedOrders;
	list<Order> unfinishedOrders;
	
	string command;
	getline(cin,command);
	while(command != "stop")
	{
		string productName = command;
		int quantity;
		cin >> quantity;
		
		orders.push(Product(productName,quantity));

		cin >> command;
	}
	while(!orders.empty())
	{
		Order order = orders.front();
		
		list<Factory>::iterator it;
		for(it = factories.begin();it != factories.end();it++)
		{
			//cout<<"in"<<endl;
			Factory factory = *it;
			if(factory.can_produce(order.product))
			{
				
				order.isFinished = 1;
				break;
			}

		}
		
		if(order.isFinished == 1)
		{
			finishedOrders.push_back(order);
		}else{
			unfinishedOrders.push_back(order);
		}

		orders.pop();
	}
	cout<<"Successful orders: "<<finishedOrders.size()<<endl;
	for(list<Order>::iterator it = finishedOrders.begin();it != finishedOrders.end();it++)
	{
		Order order = *it;
		cout<< order.product.name << order.product.quantity << endl;
	}
	cout<<endl;
	cout<<"Unsuccessful orders: "<<unfinishedOrders.size()<<endl;
	for(list<Order>::iterator it = unfinishedOrders.begin();it != unfinishedOrders.end();it++)
	{
		Order order = *it;
		cout<< order.product.name << order.product.quantity << endl;
	}



	





}
