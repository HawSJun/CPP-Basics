

#include <iostream>
#include "scope.h"

A::A(int aa) {			// :: 범위지정 연산자, std::cout <<
	a = aa;
}
void A::AInfo() {
	std::cout << "a : " << a << std::endl;
}
int main()
{
	A a(10);
	a.AInfo();

	return 0;
}