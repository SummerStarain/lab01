#include"MyStack.h"
#include"MyOperator.h"
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	MyStack<MyOperator>* optr = new MyStack<MyOperator>();							//�����ջ
	MyStack<double>* opnd = new MyStack<double>();									//������ջ
	string str;
	char op[] = { '*','(',')','-','+','/' };											//����Ϸ�����������
	string num;
	MyOperator* my_operator = new MyOperator('(');

	optr->push(*my_operator);
	cout << "�������������ʽ:" << endl;
	cin >> str;
	str = str + ")";

	while(! str.empty()) {															//�ж��ַ����Ƿ�Ϊ�գ�Ϊ�����������ʽȫ�����ɨ�貢����
		char ch = str.at(0);															//��str���ַ���ȡ
		if ((48 <= int(ch) && int(ch) <= 57) || ch == '.') {							//�ж��Ƿ�Ϊ��������С����
			num += ch;
			str.erase(0, 1);
		}
		else if (find(begin(op), end(op), ch) != end(op)) {							//�ж��Ƿ�Ϊ�Ϸ�������
			if(num == ""){}
			else {
				opnd->push(stod(num));												//ת������ջ
				num = "";
			}
			my_operator->set_operator(ch);
			if (my_operator->getPriority() == 0) {									//'('���������ջ���ȼ�
				optr->push(*my_operator);
				str.erase(0, 1);
			}
			else if (my_operator->getPriority() == -1) {								//')'������ߴ������ȼ�
				while (optr->topValue().getPriority() != 0) {						//���ջ���Ƿ�Ϊ'('
					opnd->push(optr->pop().getValue(opnd->pop(), opnd->pop()));		//��'('��ջ��������Ӧ����
				}
				optr->pop();															//��'('�����ջ
				str.erase(0, 1);														//��str��ɾȥ')'
			}
			else if (optr->topValue().getPriority() < my_operator->getPriority()) {	//�ж����ȼ�
				optr->push(*my_operator);											//��ջ����������ȼ����ڵ�ǰ���������ǰ�������ջ
				str.erase(0, 1);														//��str��ɾȥ�ַ�
			}
			else {
				opnd->push(optr->pop().getValue(opnd->pop(), opnd->pop()));			//����ջ���������ջ
			}
		}
		else {
			cout << "δ������������������ָ��" << endl;
			exit(1);
		}
	}

	if (opnd->length() == 1 && optr->length() == 0) {								//�ж��Ƿ�����������
		cout << "��������" << opnd->pop() << endl;
	}						
	else {
		cout << "δ֪����" << endl;
		exit(1);
	}
	system("pause");
	return 0;
}
