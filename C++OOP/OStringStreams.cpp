#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{

	string data = "Hello  ";
	data += "world";
	

	
	ostringstream ostream;
	ostream << "Hello ";
	ostream << "world " << "KYS" << endl;
	cout << "first str: " << data << endl;

	string str2 = ostream.str();
	cout<< "Second string: " << str2;

	
	
	 	
						
							
				
		
}
