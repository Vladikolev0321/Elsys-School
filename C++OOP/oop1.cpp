#include <iostream>

using namespace std;


class Student{

	Student(char *name,int age){
	//name_ = name;
	this->name = name;
	this->age = age;

	}

	Student(){

	}
	Student(int age){
	
	}

	char *name;
	int age;

int get_age(){
	return age;
}
char *get_name(){
	return name;
}

void setName(char *name){
	this->name = name;
}
void setAge(int age){
	this->age = age;
}



};

int main(){

	Student s2 = {"Ivan",12};
	
	Student s1;
	Student* s3


}
