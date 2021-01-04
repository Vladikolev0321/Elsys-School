#include <iostream>
#include <string>
#include <list>
#include <vector>
using namespace std;

class Transaction
{
	string type;
	double money;
public:
	Transaction(string type, double money)
	{
		this->type = type;
		this->money = money;
	}

};
class Smetka
{
	string IBAN;
	double balance;
	string type;
	vector<Transaction> transactions;
	double credit_limit;
public:
	Smetka(string IBAN, double balance, string type)
	{
		this->IBAN = IBAN;
		this->balance = balance;
		this-> type = type;
	}
	Smetka(string IBAN, double balance, string type, credit_limit)
	{
		this->IBAN = IBAN;
		this->balance = balance;
		this-> type = type;
		this->credit_limit = credit_limit;
	}
	string get_IBAN()
	{
		return this->IBAN;
	}
	double get_balance()
	{
		return this->balance;
	}
	string get_type()
	{
		return this->type;
	}
	void add_transaction(Transaction transaction)
	{
		transactions.push_back(transaction);
	}
	void cash_out(double needed_money)
	{
		if(type == "paying")
		{
			if(balance >= needed_money)
			{	
				this->add_transaction(Transaction())
				balance -= needed_money;
			}
			else
			{
				throw("There is not enough money in smetka");
			}
		}
		else if(type == "credit")
		{
			if(balance >= needed_money)
			{
				balance -= needed_money;
			}
			else
			{
				balance -= needed_money ;
				if(credit_limit >= -balance)
				{
					credit_limit -= balance;
				}
				else
				{
					throw("Your credit limit is zero");
				}
			}
		}
	}
	void 

};
class User
{
	string username;
	string password;
	vector<Smetka> smetki;
public:
	User(string username)
	{
		this->username = username;
	}
	void add_smetka(Smetka smetka)
	{
		this->smetki.push_back(smetka);
	}
	void print_smetki()
	{
		cout<<"Username:"<<username<<endl;
		for (int i = 0; i < smetki.size(); i++)
		{
			cout<<"IBAN:"<<smetki[i].get_IBAN()<<" Type:"<<smetki[i].get_type()<<" Balance:"<<smetki[i].get_balance()<<endl;
		}
	}


};
int main()
{
	User user1("Vladi");
	//paying
	user1.add_smetka(Smetka("123", 10000, "credit"));
	user1.add_smetka(Smetka("223", 20000, "credit"));
	user1.add_smetka(Smetka("323", 30000, "credit"));
	user1.add_smetka(Smetka("423", 40000, "credit"));
	user1.print_smetki();


	return 0;
}


