#pragma once
#include<iostream>
#define defaultSize 100
using namespace std;

template <class T>
class MyStack {
private:
	int maxSize;
	int top;
	T* listArray;

public:
	MyStack(int size = defaultSize) {
		maxSize = size;
		top = 0;
		listArray = new T[size];
	}
	~MyStack() { delete[] listArray; }
	void clear() { top = 0; }
	void push(const T& it) {					//��ջ
		listArray[top++] = it;
	}
	T pop() {								//��ջ
		return listArray[--top];
	}
	T& topValue() {							//����ջ��ֵ
		return listArray[top - 1];
	}
	int length() const { return top; }		//����ջ��Ԫ�ظ���
	bool isEmpty() { return bool(top); }		//�ж��Ƿ�Ϊ��
};


