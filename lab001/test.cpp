#include"MyStack.h"
#include"MyOperator.h"
#include<iostream>
#include<string>
using namespace std;

//int main() {
//	MyStack<MyOperator> *optr = new MyStack<MyOperator>;
//	MyStack<double> *opnd = new MyStack<double>;
//	opnd->push(1);
//	opnd->push(2);
//	MyOperator* myOperator = new MyOperator('(');
//	optr->push(*myOperator);
//	myOperator->set_operator('+');
//	optr->push(*myOperator);
//	opnd->push(optr->pop().getValue(opnd->pop(), opnd->pop()));
//	optr->pop();
//	cout << opnd->length() << endl;
//	cout << optr->length() << endl;
//	system("pause");
//	return 0;
//}