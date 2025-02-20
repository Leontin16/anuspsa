#pragma once
#include "stacklist.h"
#include "stack.h"
#include <iostream>
#include <map>
#include <vector>

using namespace std;

string getPostform(const string& simpleForm);
vector<char> getOperand(const string& simpleForm);

int Calculate(const string& postForm, map<char, int>& values);
