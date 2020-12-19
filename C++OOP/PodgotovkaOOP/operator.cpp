#include <iostream>
#include <list>
using namespace std;
class List{
	list<int> myList;
public:
	List(){};
	list<int> operator+(const int val)
	{
		myList.push_back(val);	
	}
	list<int> operator+=(const int val)
	{
		myList.push_back(val);	
	}
	list<int> operator--(int)
	{
		myList.pop_back();
	}
	int operator[](const int index)
	{
		list<int>::iterator it = myList.begin();
		advance(it, index);
		return *it;
	}
	void print()
	{
		for (list<int>::iterator it = myList.begin();it != myList.end();it++)
		{	
			cout<<*it<<endl;
		}
	}


};
int main()
{	
	List myList;
	myList +=4;
	myList +=3;
	myList +=2;
	myList +=1;
	myList --;
	int el = myList[0];
	cout<<"Accessed element:"<<el<<endl;
	myList.print();

}	