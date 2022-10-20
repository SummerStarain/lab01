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
	void push(const T& it) {					//入栈
		listArray[top++] = it;
	}
	T pop() {								//出栈
		return listArray[--top];
	}
	T& topValue() {							//返回栈顶值
		return listArray[top - 1];
	}
	int length() const { return top; }		//返回栈中元素个数
	bool isEmpty() { return bool(top); }		//判断是否为空
};


