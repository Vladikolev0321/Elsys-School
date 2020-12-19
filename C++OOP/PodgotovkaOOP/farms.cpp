#include <iostream>
#include <string>
#include <fstream>
#include <list>
using namespace std;
class Niva
{
	string typeStock;
	int madeStock;
	int countWorkers;
public:
	Niva(string typeStock,int madeStock, int countWorkers)
	{
		this->typeStock = typeStock;
		this->madeStock = madeStock;
		this->countWorkers = countWorkers;
	}
	string get_typeStock()
	{
		return this->typeStock;
	}
	int get_madeStock()
	{
		return this->madeStock;
	}
	int get_countWorkers()
	{
		return this->countWorkers;
	}
};
class Farm
{	
	list<Niva> nivi;
	string name;
public:
	int countWorkers;
	Farm(){};
	Farm(list <Niva> list)
	{
		this->nivi = list;
	}
	int get_production(string type)
	{
		int countWorkersLeft = this->countWorkers;
		int res = 0;
		bool isThereNiva = false;
		for (list<Niva>::iterator it = nivi.begin();it != nivi.end();it++)
		{
			Niva currNiva = *it;
			if(currNiva.get_typeStock() == type)
			{
				if(countWorkersLeft >= currNiva.get_countWorkers())
				{
					countWorkersLeft -= currNiva.get_countWorkers();
					res += currNiva.get_madeStock();
				}
				isThereNiva = true;
			}
		}

		if(nivi.size() == 0)
		{
			throw("Count of nivi is 0");
		}
		if(isThereNiva == false)
		{
			throw("No niva with this type");
		}

		return res;
	}
	void add_niva(Niva niva)
	{
		this->nivi.push_back(niva);
	}
	void remove_last_niva()
	{
		this->nivi.pop_back();
	}
	void print_nivi()
	{
		for (list<Niva>::iterator it = nivi.begin();it != nivi.end();it++)
		{
			Niva currNiva = *it;
			cout<<"typeStock: "<<currNiva.get_typeStock()<<" madeStock: "<<currNiva.get_madeStock()
			<<" countWorkers: "<<currNiva.get_countWorkers()<<endl;
		}
	}
	void save_as_txt()
	{
		ofstream ostream;
		ostream.open("farm.txt");

		for (list<Niva>::iterator it = nivi.begin();it != nivi.end();it++)
		{
			Niva currNiva = *it;
			ostream<<"typeStock: "<<currNiva.get_typeStock()<<" madeStock: "<<currNiva.get_madeStock()
			<<" countWorkers: "<<currNiva.get_countWorkers()<<endl;
		}
		ostream.close();
	}
	void read_from_txt()
	{
		ifstream istream;
		istream.open("farm.txt");

		for (list<Niva>::iterator it = nivi.begin();it != nivi.end();it++)
		{	
			string currNiva;
			getline(istream,currNiva);
			cout<<currNiva<<endl;
		}

	}


};
int main()
{
	Farm farm;
	farm.countWorkers = 15;
	cout<<"Enter stock type:"<<endl;
	string command;
	cin>>command;

	while(command != "stop")
	{
		string typeStock = command;
		int madeStock;
		cin>>madeStock;
		int countWorkers;
		cin>>countWorkers;

		farm.add_niva(Niva(typeStock,madeStock,countWorkers));	
		cout<<"Enter stock type:"<<endl;
		cin>>command;
	}	

	farm.print_nivi();

	try{
		cout<<"Which production would you want to check:"<<endl;
		string type_to_check;
		cin>>type_to_check;	
		int stockMade = farm.get_production(type_to_check);
		cout<<"StockMade: "<<stockMade<<endl;
	}
	catch(const char *ex)
	{
		cout<<ex<<endl;
	}
	
	farm.save_as_txt();
	farm.read_from_txt();

}