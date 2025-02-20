#include "postfix_form.h"
#include <map>


//#define USE_ARRAY

#ifndef USE_ARRAY

string getPostform(const string& simpleForm) {

	TStackList<char> a1;
	TStackList<char> a2;
	char stakItem;
	for (int i = 0; i < strlen(simpleForm.c_str()); i++) {
		if (simpleForm[i] == '+' || simpleForm[i] == '-') {
			try {
				if (a2.Top() == '/' || a2.Top() == '*') {
					while (a2.Top() == '/' || a2.Top() == '*') {
						a1.push(a2.Top());
						a2.pop();
					}
					a2.push(simpleForm[i]);
				}

				else {
					a2.push(simpleForm[i]);
				}
			}
			catch (const char* error) {
				a2.push(simpleForm[i]);

			}
		}
		else if (simpleForm[i] == '*' || simpleForm[i] == '/') {
			a2.push(simpleForm[i]);

		}
		else if (simpleForm[i] == '(') a2.push(simpleForm[i]);
		else if (simpleForm[i] == ')') {
			stakItem = a2.Top();
			a2.pop();
			while (a2.Top() != '(') {
				a1.push(stakItem);

				stakItem = a2.Top();
				a2.pop();
			}
			a1.push(stakItem);
			a2.pop();
		}
		else {
			a1.push(simpleForm[i]);
		}
	}
	while (!a2.isEmpty()) {
		a1.push(a2.Top());
		a2.pop();
	}
	string newForm = "";
	while (!a1.isEmpty()) {
		newForm = a1.Top() + newForm;
		a1.pop();
	}
	return newForm;

}
vector<char> getOperand(const string& simpleForm) {
	vector<char> v;
	for (int i = 0; i < strlen(simpleForm.c_str()); i++) {
		if (simpleForm[i] != '+' && simpleForm[i] != '*' && simpleForm[i] != '/' && simpleForm[i] != '-') {
			int j = 0;
			bool f = false;
			for (int j = 0; j < v.size(); j++) {
				if (v[j] == simpleForm[i]) {
					f = true;
					break;
				}
			}
			if (f == false) {
				v.push_back(simpleForm[i]);
			}
		}

	}
	return v;

}
int Calculate(const string& postForm, map<char, int>& values) {

	TStackList<char> a1;

	for (int i = 0; i < strlen(postForm.c_str()); i++) {
		if (postForm[i] == '+') {
			char num2 = a1.Top();
			a1.pop();
			char num1 = a1.Top();
			a1.pop();
			int k = (values[num1] + values[num2]);
			a1.push(k);
			values.insert({ k, k });
		}
		else if (postForm[i] == '*') {
			char num2 = a1.Top();
			a1.pop();
			char num1 = a1.Top();
			a1.pop();
			int k = (values[num1] * values[num2]);
			a1.push(k);
			values.insert({ k, k });
		}
		else if (postForm[i] == '/') {
			char num2 = a1.Top();
			a1.pop();
			char num1 = a1.Top();
			a1.pop();
			int k = (values[num1] / values[num2]);
			a1.push(k);
			values.insert({ k, k });
		}
		else if (postForm[i] == '-') {
			char num2 = a1.Top();
			a1.pop();
			char num1 = a1.Top();
			a1.pop();
			int k = (values[num1] - values[num2]);
			a1.push(k);
			values.insert({ k, k });
		}
		else {
			a1.push(postForm[i]);
		}
	}
	return (int)a1.Top();
}

#else
string getPostform(const string& simpleForm, int n) {

	TStackArray<char> a1(n);
	TStackArray<char> a2(n);
	char stakItem;
	for (int i = 0; i < strlen(simpleForm.c_str()); i++) {
		if (simpleForm[i] == '+' || simpleForm[i] == '-') {
			try {
				if (a2.Top() == '/' || a2.Top() == '*') {
					while (a2.Top() == '/' || a2.Top() == '*') {
						a1.push(a2.Top());
						a2.pop();
					}
					a2.push(simpleForm[i]);
				}

				else {
					a2.push(simpleForm[i]);
				}
			}
			catch (const char* error) {
				a2.push(simpleForm[i]);

			}
		}
		else if (simpleForm[i] == '*' || simpleForm[i] == '/') {
			a2.push(simpleForm[i]);

		}
		else if (simpleForm[i] == '(') a2.push(simpleForm[i]);
		else if (simpleForm[i] == ')') {
			stakItem = a2.Top();
			a2.pop();
			while (a2.Top() != '(') {
				a1.push(stakItem);

				stakItem = a2.Top();
				a2.pop();
			}
			a1.push(stakItem);
			a2.pop();
		}
		else {
			a1.push(simpleForm[i]);
		}
	}
	while (!a2.isEmpty()) {
		a1.push(s2.Top());
		a2.pop();
	}
	string newForm = "";
	while (!a1.isEmpty()) {
		newForm = a1.Top() + newForm;
		a1.pop();
	}
	return newForm;

}
vector<char> getOperand(const string& simpleForm) {
	vector<char> v;
	for (int i = 0; i < strlen(simpleForm.c_str()); i++) {
		if (simpleForm[i] != '+' && simpleForm[i] != '*' && simpleForm[i] != '/' && simpleForm[i] != '-') {
			int j = 0;
			bool f = false;
			for (int j = 0; j < v.size(); j++) {
				if (v[j] == simpleForm[i]) {
					f = true;
					break;
				}
			}
			if (f == false) {
				v.push_back(simpleForm[i]);
			}
		}

	}
	return v;

}
int Calculate(const string& postForm, int n, map<char, int>& values) {

	TStackArray<char> a1(n);

	for (int i = 0; i < n; i++) {
		if (postForm[i] == '+') {
			char num2 = a1.Top();
			a1.pop();
			char num1 = a1.Top();
			a1.pop();
			int k = (values[num1] + values[num2]);
			a1.push(k);
			values.insert({ k, k });
		}
		else if (postForm[i] == '*') {
			char num2 = a1.Top();
			a1.pop();
			char num1 = s1.Top();
			a1.pop();
			int k = (values[num1] * values[num2]);
			a1.push(k);
			values.insert({ k, k });
		}
		else if (postForm[i] == '/') {
			char num2 = a1.Top();
			a1.pop();
			char num1 = a1.Top();
			a1.pop();
			int k = (values[num1] / values[num2]);
			a1.push(k);
			values.insert({ k, k });
		}
		else if (postForm[i] == '-') {
			char num2 = a1.Top();
			a1.pop();
			char num1 = a1.Top();
			a1.pop();
			int k = (values[num1] - values[num2]);
			a1.push(k);
			values.insert({ k, k });
		}
		else {
			a1.push(postForm[i]);
		}
	}
	return (int)a1.Top();
}




#endif // !USE_LIST