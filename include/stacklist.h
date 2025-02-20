
#pragma once

#include "list.h"
#include "stack.h"

template <typename T>
class TStackList : public AbstractStack<T> {
private:
	TList<T> data;
public:
	TStackList() {}
	TStackList(const TStackList<T>& ts) {
		TNode<T>* tmp = ts.data.GetLast();
		while (tmp != nullptr) {
			data.InsertEnd(tmp->key);
			tmp = tmp->pNext;
		}
	}
	~TStackList() {}

	bool isFull() const {

		TNode<int>* s = new TNode<int>(1);
		return (s == nullptr);
	}
	bool isEmpty() const {
		return (data.GetFirst() == nullptr);
	}
	void push(T val)
	{
		if (isFull()) throw "error";

		data.InsertFirst(val);
	}
	void pop() {
		if (isEmpty()) throw "error";

		data.DeleteFirst();


	}

	T Top() const {
		if (isEmpty()) { throw "error"; }
		return data.GetFirst()->key;
	}
};
