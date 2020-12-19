#include <iostream>
using namespace std;

class String{	
public:	
	String(){};	
	String(int value)
	{
		this->thickness = value;
	};
	str
	int thickness;
};
class Guitar{
public:
	Guitar(){};

	String strings[6];




	void AddString(int index,String string)
	{		
		if(string.thickness < 0.2 || string.thickness > 5)
		{	
			throw "String cannot be added, it is not in the required thickness";
		}
		for(int i = index;i > 0; i--)
		{	
			if(this->strings[index-1].thickness > string.thickness)
			{
				throw "String cannot be added, the strings won't be in sorted order";
			}
		}

		this->strings[index] = string;
	}

	void PrintGuitar()
	{
		for(int i = 0; i < 6; i++)
		{
			cout<<this->strings[i].thickness<<endl;
		}
	}
};

int main()
{
	Guitar guitar;
	
	String str1(-2);
	String str2(2);
	String str3(1);
	
	
	try{
		guitar.AddString(0,str1);
		//guitar.AddString(1,str2);
	}	
	catch(const char* ex)
	{
		cout<<ex<<endl;
	}
	try{
		guitar.AddString(0,str2);
	}	
	catch(const char* ex)
	{
		cout<<ex<<endl;
	}
	try{
		guitar.AddString(1,str3);
	}	
	catch(const char* ex)
	{
		cout<<ex<<endl;
	}
	guitar.PrintGuitar();

	


}

