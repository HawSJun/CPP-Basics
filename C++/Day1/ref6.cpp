/*
	출력인 경우 : 레퍼런스(일반변수, 참조 다 가능)
*/
#include <iostream>

int& func(int& ref) {
	ref++;
	return ref;			// lvalue
	//return ref++		// rvalue - rvalue 참조는 && 두개 사용
}
int main()
{
	int n = 10;
	int ref = func(n);
	// int& ref = func(n);			// 출력하는 타입과 동일하면 상관없음!

	std::cout << "ref : " << ref << std::endl;

	return 0;
}