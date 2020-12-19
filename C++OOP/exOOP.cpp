#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <queue>
using namespace std;
class List{
list<int> myList;
public:
	List(){};
	list<int> operator+(const int val)
	{
		myList.push_back(val);
		return myList;
	}	
	list<int> operator+=(const int val)
	{
		myList.push_back(val);
		return myList;
	}
	int operator-(const int val)
	{
		int delEl = myList.front();
		myList.pop_front();
		return delEl;
	}
	int operator-=(const int val)
	{
		int delEl = myList.front();
		myList.pop_front();
		return delEl;
	}
	int operator[](const int index)
	{
		list<int>::iterator it = myList.begin();
		advance(it,index);
		return *it;
	}
	list<int>::iterator operator*(const int nth)
	{
		list<int>::iterator it = myList.begin();
		return it;
	}
	/*void operator>>()
	{
		
	}
	*/
	void print()
	{	
		for(list<int>::iterator it = myList.begin(); it != myList.end(); it++)
		{
			int currVal = *it;
			cout<<currVal<<endl;
		}
	}
	
};
int main()
{
	List myList;
	myList+=4;
	myList+=3;
	myList+=2;
	myList+=1;
	int delEl = myList-=0;
	cout<<"Deleted element:"<<delEl<<endl;
	int el = myList[0];
	cout<<"Accessed element:"<<el<<endl;
	list<int>::iterator it = myList*0;
	cout<<"Iterator"<<*(++it)<<endl;
	myList.print();
	
	


}
