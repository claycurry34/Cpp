#include <iostream>
using namespace std;


class Parent
{
protected:
	char identity = 'p';
public:
	Parent() { cout << "new parent at " <<this << endl; };
	~Parent() { cout << "killed parent at " << this << endl; }
	void print() { cout << "Printed " << identity << " inside parent" << endl; };
	virtual void virtualPrint() { cout << "Virtual Printed " << identity << " inside parent" << endl; };
	void printP() { cout << "Printed " << identity << " inside parent" << endl; };
};
class Child : public Parent
{
protected:
	char identity = 'c';
public:
	Child() : Parent() { cout << "new child at " << this << endl; };
	~Child() { cout << "killed child at " << this << endl; };
	void print() { cout << "Printed " << identity << " inside child" << endl; };
	virtual void virtualPrint() { cout << "Virtual Printed " << identity << " inside child" << endl; };
	void printC() { cout << "Printed " << identity << " inside child" << endl; };
};

int main()
{
	cout << "Child* child = new Child();" << endl;
	Child* child = new Child();
	cout << "child->print(); " ; child->print();
	cout << "child->virtualPrint(); "; child->virtualPrint();
	cout << "child->printC(); "; child->printC();
	cout << endl;

	cout << "Parent* parent = child;" << endl;
	Parent* parent = child;
	cout << "parent->print(); "; parent->print();
	cout << "parent->virtualPrint(); "; parent->virtualPrint();
	cout << "parent->printP(); "; parent->printP();
	cout << endl;

	cout << "Parent* par = new Parent();" << endl;
	Parent* par = new Parent();
	cout << "par->print(); "; par->print();
	cout << "par->virtualPrint(); "; par->virtualPrint();
	cout << "par->printP(); "; par->printP();
	cout << endl << endl;

	cout << "Parent p = Child();" << endl;
	Parent pa = Child();

}