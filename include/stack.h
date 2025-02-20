#pragma once
#include <iostream>
#include <string>
#include "list.h"
using namespace std;

template<typename T>
class AbstractStack {
public:
    virtual void push(T value) = 0;
    virtual void pop() = 0;
    virtual T Top() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
	virtual ~AbstractStack() {}
};

template<typename T>
class ArrayStack : public AbstractStack<T> {
private:
    T* data;
    int capacity;
    int topIndex;

public:
	ArrayStack(int maxSize = 10) {
		if (capacity <= 0) throw "Negative size";
		this->capacity = capacity;
		this->data = new T[capacity];
		for (int i = 0; i < this->capacity; i++) {
			this->data[i] = 0;
		}
		this->topIndex = -1;
	}
	ArrayStack(const ArrayStack& ts) {
		this->capacity = ts.capacity;
		this->topIndex = ts.topIndex;
		this->data = new T[this->capacity];
		for (int i = 0; i < this->capacity; i++) {
			this->data[i] = ts.data[i];
		}
	}
	~ArrayStack() {
		delete[] data;
	}

	bool isFull() const {
		return (this->topIndex == this->capacity - 1);
	}
	bool isEmpty() const {
		return (this->topIndex == -1);
	}
	void push(T val)
	{
		if (isFull()) throw "error";
		topIndex++;
		this->data[topIndex] = val;
	}
	void pop() {
		if (isEmpty()) throw "error";

		this->topIndex--;
	}

	T Top() const {
		if (isEmpty()) return 0;
		return data[topIndex];
	}
};