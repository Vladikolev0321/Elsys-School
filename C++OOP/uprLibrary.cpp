#include <iostream>
#include <string>
#include <list>
#include <fstream>
using namespace std;
class Book{
public:
	Book(){};
	Book(string heading,string author, int pages, int rating)
	{
		this->heading = heading;
		this->author = author;
		this->pages = pages;
		this->rating = rating;

	}
	string heading;
	string author;
	int pages;
	int rating;
};
class Library{
	list<Book> books;
public:
	Library()
	{
		this->size = 0;
	};
	void add_book(Book book)
	{
		this->books.push_back(book);
		this->size++;
		
	}
	int size;
	void save_as_csv()
	{
		ofstream ostream;
		ostream.open("uprLib.csv");
		
		for(list<Book>::iterator it = books.begin();it != books.end();it++)
		{
			Book book = *it;
			ostream << book.heading << ',' << book.author << ',' << book.pages << ',' << book.rating << endl;
			
		}
			ostream.close();

	}
	void read_from_csv()
	{
		ifstream istream;
		istream.open("uprLib.csv");

		for(int i=0;i<this->size;i++)
		{
			string currBook;
			getline(istream,currBook);
			
			cout<<currBook<<endl;
		}
		
		istream.close();

	}
};





int main()
{
	Library lib;
	
	string command;
	getline(cin,command);

	while(command != "stop")
	{
		string heading = command;
		string author;
		cin>>author;
		//getline(cin,author);
		int pages;
		float rating;
		cin>>pages>>rating;

		Book book_to_add(heading,author,pages,rating);
		lib.add_book(book_to_add);

		cin>>command;	
	}

	lib.save_as_csv();
	lib.read_from_csv();


	


	


}
