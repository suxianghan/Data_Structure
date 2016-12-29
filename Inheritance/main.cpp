#include <iostream>
using namespace std;

class Person{
private:
	static int counter;
	int id;
	double salary;
public:
	Person():id(counter),salary(0){counter++;};
	Person(double salaryIn):id(counter),salary(salaryIn){counter++;};
	virtual int getId(){return id;}
	double getSalary(){return salary;}
	int tester(){return id;}
};

class Teacher: public Person{
private:
	string school;
public:
	Teacher():Person(),school("NDF"){}
	Teacher(double salaryIn,string schoolIn):Person(salaryIn),school(schoolIn){}
	string getSchool(){return school;}
	int getId(){return this->tester();}
};

int Person::counter = 1;

int main(){
	Person *defa = new Person();
	Person *exma = new Person(18);
	Person *exmb = new Teacher(69.30,"SMS");
	cout<<defa->getId()<<endl;
	cout<<((*exma).getId())<<endl;
	cout<<exmb->getId()<<endl;
	cout<<exmb->getSalary()<<endl;
	return 0;
}