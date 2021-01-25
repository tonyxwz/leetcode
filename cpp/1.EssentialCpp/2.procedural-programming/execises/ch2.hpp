#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ElemType = unsigned long long int;

const vector<ElemType>*
fibon_seq(int n);

bool
size_ok(int size);

const vector<ElemType>*
fibon_seq(int size);

bool
fibon_elem(int n, ElemType& target);