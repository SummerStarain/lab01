//#include"MyStack.h"
//#include"MyOperator.h"
//#include<iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//
//int main() {
//	MyStack<MyOperator>* optr = new MyStack<MyOperator>();							//运算符栈
//	MyStack<double>* opnd = new MyStack<double>();									//操作数栈
//	string str;
//	char op[] = { '*','(',')','-','+','/' };											//定义合法操作符数组
//	string num;
//	MyOperator* my_operator = new MyOperator('(');
//
//	optr->push(*my_operator);
//	cout << "请输入算数表达式:" << endl;
//	cin >> str;
//	str = str + ")";
//
//	while(! str.empty()) {															//判断字符串是否为空，为空则算术表达式全部完成扫描并处理
//		char ch = str.at(0);															//将str首字符读取
//		if ((48 <= int(ch) && int(ch) <= 57) || ch == '.') {							//判断是否为操作数或小数点
//			num += ch;
//			str.erase(0, 1);
//		}
//		else if (find(begin(op), end(op), ch) != end(op)) {							//判断是否为合法操作符
//			if(num == ""){}
//			else {
//				opnd->push(stod(num));												//转换并入栈
//				num = "";
//			}
//			my_operator->set_operator(ch);
//			if (my_operator->getPriority() == 0) {									//'('享有最高入栈优先级
//				optr->push(*my_operator);
//				str.erase(0, 1);
//			}
//			else if (my_operator->getPriority() == -1) {								//')'享有最高处理优先级
//				while (optr->topValue().getPriority() != 0) {						//检查栈顶是否为'('
//					opnd->push(optr->pop().getValue(opnd->pop(), opnd->pop()));		//非'('出栈并进行相应操作
//				}
//				optr->pop();															//是'('则其出栈
//				str.erase(0, 1);														//在str中删去')'
//			}
//			else if (optr->topValue().getPriority() < my_operator->getPriority()) {	//判断优先级
//				optr->push(*my_operator);											//若栈顶运算符优先级低于当前运算符，则当前运算符进栈
//				str.erase(0, 1);														//在str中删去字符
//			}
//			else {
//				opnd->push(optr->pop().getValue(opnd->pop(), opnd->pop()));			//否则栈顶运算符退栈
//			}
//		}
//		else {
//			cout << "未定义操作符或错误运算指令" << endl;
//			exit(1);
//		}
//	}
//
//	if (opnd->length() == 1 && optr->length() == 0) {								//判断是否达成最终条件
//		cout << "运算结果是" << opnd->pop() << endl;
//	}						
//	else {
//		cout << "未知错误" << endl;
//		exit(1);
//	}
//	system("pause");
//	return 0;
//}
