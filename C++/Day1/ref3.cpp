/*
	레퍼런스 - 선언과 동시에 초기화해야만 한다
*/

#include <iostream>

using namespace std;

int main()
{
	int num = 10, num2 = 100;
	int& ref = num;				// num의 메모리 공간에 ref라는 별명이 붙는다.
	int* pn = &num;
	int& rref = ref;
	rref = num2;

	cout << rref << ", "<< num2 << endl;
	//int& rref;					// 참조자는 선언과 동시에 초기화해야 함
	//rref = ref;

	num++;
	ref++;
	(*pn)++;

	cout << "num++ : " << num << endl;
	cout << "ref++ : " << ref << endl;
	cout << "(*pn)++ : " << (*pn) << endl;

	cout << "&num : " << &num << endl;
	cout << "&ref : " << &ref << endl;
	cout << "&n(*pn) : " << &(*pn) << endl;

	return 0;
}