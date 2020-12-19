#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

class Book{
public:
	Book(){}
	Book(string heading,string author,int count_pages,int rating)
	{
		this->heading = heading;
		this->author = author;
		this->count_pages = count_pages;
		this->rating = rating;
	}
	string heading;
	string author;
	int count_pages;
	int rating;
};
class Library{
	list<Book> books;
public:
	Library(){}
	void add_book(Book book){
		this->books.push_back(book);
	}
	void save_as_csv(){
		ofstream ostream;
		ostream.open("library.csv");
		
		//list<Order>::iterator it;
		list<Book>::iterator it;
		
		for(it = books.begin();it != books.end();++it)
		{
			ostream << it->heading << ',' << it->author << ',' << it->count_pages << ',' << it->rating << endl;
		}

		ostream.close();
	}
	void print_books()
	{
		list<Book>::iterator it;
		
		for(it = books.begin();it != books.end();++it)
		{
			cout << it->heading << it->author << it->count_pages << it->rating << endl;
		}


	}




};
int main()
{
	Library library;
	
	string command;
	getline(cin,command);

	while(command != "stop")
	{	
	
		string heading;
		string author;
		int count_pages;
		int rating;

	
	    heading = command;
		cin >> author;
		cin >> count_pages;
		cin >>  rating;

		Book book_to_add(heading,author,count_pages,rating);

		library.add_book(book_to_add);		
		
		cin>>command;
	}

	library.print_books();
	library.save_as_csv();
	
	

 

}
