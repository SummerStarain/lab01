#include<string>
#include<vector>
#include<iostream>
#include"MyStack.h"
#include"MyOperator.h"
using namespace std;


static void final_lab(string str) {

	vector<string> _num;
	MyStack<MyOperator>* optr = new MyStack<MyOperator>;
	MyStack<double>* opnd = new MyStack<double>;
	string num;
	char op[] = { '+','-','*','/','(',')' };
	MyOperator* my_operator = new MyOperator('(');
	optr->push(*my_operator);
	str += ')';

	while (!str.empty()) {
		char ch = str.at(0);
		if ((48 <= int(ch) && int(ch) <= 57) || ch == '.' || ch == '#') {
			if (ch == '#')ch = '-';
			num += ch;
			str.erase(0, 1);
		}
		else if (find(begin(op), end(op), ch) != end(op)) {
			if (num == "") {}
			else {
				_num.push_back(num);
				num = "";
			}
			my_operator->set_operator(ch);
			if (my_operator->getPriority() == 0) {										//'('享有最高入栈优先级
				optr->push(*my_operator);
				str.erase(0, 1);
			}
			else if (my_operator->getPriority() == -1) {									//')'享有最高处理优先级
				while (optr->topValue().getPriority() != 0) {							//检查栈顶是否为'('
					_num.push_back(optr->pop().get_operator());							//非'('出栈
				}
				optr->pop();																//是'('则其出栈
				str.erase(0, 1);															//在str中删去')'
			}
			else if (optr->topValue().getPriority() < my_operator->getPriority()) {		//判断优先级
				optr->push(*my_operator);												//若栈顶运算符优先级低于当前运算符，则当前运算符进栈
				str.erase(0, 1);															//在str中删去字符
			}
			else {
				_num.push_back(optr->pop().get_operator());								//否则栈顶运算符退栈
			}
		}
		else {
			cout << "未定义操作符或错误运算指令" << endl;
			exit(1);
		}
	}

	for (int i = 0; i < _num.size(); i++) {
		cout << _num[i] << " ";
	}
	cout << endl;

	while (!_num.empty()) {
		if ((_num.front().length() == 1) && (find(begin(op), end(op), _num.front().at(0)) != end(op))) {
			my_operator->set_operator(_num.front().at(0));
			opnd->push(my_operator->getValue(opnd->pop(), opnd->pop()));
			_num.erase(_num.begin());
		}
		else {
			opnd->push(stod(_num.front()));
			_num.erase(_num.begin());
		}
	}
	if (opnd->length() == 1) {
		cout << "计算结果为" << opnd->pop() << endl;
	}
	else {
		cout << "未知异常" << endl;
	}
} 
