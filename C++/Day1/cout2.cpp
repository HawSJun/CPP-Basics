/*
	cout - 출력을 담당하는 객체
*/

#include <iostream>

int main()
{
	int num = 100;			// C 스타일 변수 선언
	int num2(200);			// C++ 스타일 변수 선언

	std::cout << num << std::endl;
	std::cout << num2 << std::endl;

	return 0;
}