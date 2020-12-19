#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int const STACK_SIZE = 10;
class Stack
{
	int data[STACK_SIZE];
	int top;
public:
	Stack()
	{
		top = 0;	
	}
	bool isFull()
	{
		return top == STACK_SIZE;

	}
	void push(int value)
	{
		if(isFull())
		{
			cout<<"No more space";			
		}
		else 
		{	
			data[top++] = value;
		}		
		
	}
	int pop()
	{	
		if(top <= 0)
		{
			throw "Stack is empty";
		}
		return data[--top];	
	}
	




};
int main()
{
	
	
	Stack S;

	for(int i = 0;i < 10 ; i++){
		try{
			S.push(i);
		}
		catch(const char * ex)
		{
			cout<<ex;
		}
	}
	



}
