/*
	템플릿의 typename이  여러개인 경우
*/

#include <iostream>

template <typename T, typename T2>
void func(T a, T2 b) {
	std::cout << a << std::endl;
	std::cout << b << std::endl;
}

int main()
{
	func(10, 3.14);
	func("Template", 3.14);
	func<const char*, double>("Hello", 3.1415);

	return 0;
}