#pragma once
#include<iostream>
using namespace std;
class MyOperator
{
private:
	int priority;
	char _operator;
public:
	MyOperator() {};
	MyOperator(char _operator) {																				//��ʼ��
		this->_operator = _operator;
		if (_operator == '(') priority = 0;
		else if (_operator == '+' || _operator == '-') priority = 1;
		else if (_operator == '*' || _operator == '/') priority = 2;
		else if (_operator == ')') priority = -1;
	}

	double getValue(double num1, double num2) {																//�������
		if (this->_operator == '+') { return num2 + num1; }
		else if (this->_operator == '-') { return num1 - num2; }
		else if (this->_operator == '*') { return num1 * num2; }
		else if (this->_operator == '/') { if (num2 == 0) cout << "�������:0����������" << endl; return num1 / num2; }
	}

	int getPriority() {																						//�������ȼ�
		return this->priority;
	}

	string get_operator() {																					//���ط���
		string _op(1, this->_operator);
		return _op;
	}

	void set_operator(char _operator) {																		//���÷���
		this->_operator = _operator;
		if (_operator == '(') priority = 0;
		else if (_operator == '+' || _operator == '-') priority = 1;
		else if (_operator == '*' || _operator == '/') priority = 2;
		else if (_operator == ')') priority = -1;
	}
};