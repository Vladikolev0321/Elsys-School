#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{

	//////Inputing ostream in file

	/*string name;
	cout<<"Enter your name:"<<endl;
	getline(cin,name);

	int age;
	cout<< "Enter your age:"<<endl;
	cin >> age;
	
	ofstream ostream;
	ostream.open("test.txt");

	ostream << name << endl;
	ostream << age << endl;
	
	ostream.close();

	*/

	////Outputtng ifstream from file

	/*ifstream istream;
	istream.open("test.txt");
	

	string name2;
	getline(istream,name2);	
	
	int age2;
	istream >> age2;
	

	istream.close();
	
	cout<<"Read name: "<< name2 << endl;
	cout<<"Read age: " << age2 << endl;
	*/

	ofstream ostream;
	ostream.open("test.txt");
	
	ostream << boolalpha << true << endl;
	
	ostream << scientific << 12.4332 << endl;

	ostream << setw(5) << setfill('#') << 25 << endl;

	ostream.close();


}
