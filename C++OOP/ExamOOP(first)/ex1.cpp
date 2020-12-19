////Vladislav Kolev
///11b No7


#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <queue>
using namespace std;
class Niva{
	string typeStock;
	int madeStock;
	int countWorkers;
public:
	Niva(string typeStock,int madeStock,int countWorkers)
	{	
		this->typeStock = typeStock;
		this->madeStock = madeStock;
		this->countWorkers = countWorkers;
	}
	string getTypeStock()
	{
		return this->typeStock;
	}
	int getMadeStock()
	{
		return this->madeStock;
	}
	int getCountWorkers()
	{
		return this->countWorkers;
	}
	
};
class Farm{
	list<Niva> nivi;
public:
	Farm(){};
	Farm(list<Niva> nivi)
	{
		this->nivi = nivi;
	}
	int countWorkers;
	string name;
	int get_production(string type)
	{
		////Exceptions
		bool isThereNivaWithThisType = false;
		for(list<Niva>::iterator it = nivi.begin(); it != nivi.end(); it++)
		{
			Niva currNiva = *it;
			if(currNiva.getTypeStock() == type)
			{
				isThereNivaWithThisType = true;
				break;
			}
		}


		if(nivi.size() == 0 )
		{
			throw "There is no nivi's in this farm";
		}
		if(!isThereNivaWithThisType)
		{
			throw "There is no niva in this farm with that type";
		}

		/////
		int countMadeProd = 0;
		for(list<Niva>::iterator it = nivi.begin(); it != nivi.end(); it++)
		{
			Niva currNiva = *it;
			if(currNiva.getTypeStock() == type)
			{
				countMadeProd += currNiva.getMadeStock();
			}
		}
		return countMadeProd;
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
		for(list<Niva>::iterator it = nivi.begin(); it != nivi.end(); it++)
		{
			Niva currNiva = *it;
			cout<<"type: "<< currNiva.getTypeStock() << " Quantity: " <<currNiva.getMadeStock() << " Count workers: " << currNiva.getCountWorkers() << endl;
		}
	}
	void save_as_txt()
	{
		ofstream ostream;
		ostream.open("farm.txt");
		
		for(list<Niva>::iterator it = nivi.begin(); it != nivi.end(); it++)
		{
			Niva currNiva = *it;
			ostream<<"type: "<< currNiva.getTypeStock() << " Quantity: " <<currNiva.getMadeStock() << " Count workers: " << currNiva.getCountWorkers() << endl;
		}

		ostream.close();
	}
	void read_from_txt()
	{
		

	}



};
int main()
{
	Farm farm;

	cout<<"Enter stock type:"<<endl;
	string command;
	getline(cin,command);

	while(command != "stop")
	{
		
		string typeStock = command;
		int madeStock;
		cout<<"Enter stock qunatity"<<endl;
		cin>>madeStock;
		int countWorkers;
		cout<<"Enter workers count"<<endl;
		cin>>countWorkers;
		
		Niva niva(typeStock,madeStock,countWorkers);
		
		farm.add_niva(niva);
		
		cout<<"Enter stock type:"<<endl;
		cin>>command;
		
	}
	cout<<"All nivi::"<<endl;
	farm.print_nivi();
	
	
	try{
		string type_to_check;
		cout<<"Which production would you try to check?"<<endl;
		cin>>type_to_check;

		int returnedQuantity = farm.get_production(type_to_check);
		cout<<"There is "<<returnedQuantity<< " quantity of this production"<<endl;
	}
	catch(const char* ex){
		cout<<ex<<endl;
	}
	
	farm.save_as_txt();

}
