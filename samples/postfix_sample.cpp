#include <iostream>
#include "postfix_form.h"

int main() {
	setlocale(LC_ALL, "Ru");
	char* st = "B*(A-C)";
	cout << "Обычная форма: " << st << endl;
	int n = strlen(st);
	string a;
	a = getPostform(st);
	cout << "Постфиксная форма: " << a << endl;
	cout << "\n" << endl;
	map<char, int> s;
	vector<char> v = getOperand(a);
	for (int i = 0; i < v.size(); i++) {
		int d;
		cout << "Введите значение для элемента " << v[i] << ":" << endl;
		cin >> d;
		s[v[i]] = d;
	}
	cout << "Ответ: " << Calculate(a, s) << endl;



}