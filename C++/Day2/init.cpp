/*
	변수 초기화
*/
#include <iostream>

int main()
{
	int num = 10;			// 복사 초기화
	int num2(30);			// 직접 초기화
	int num3{ 300 };		// 중괄호 직접 초기화(권장)
	int num4 = { 3000 };	// 중괄호 복사 초기화

	int x = 3.14;
	int x1{ 3.14 };			// c++ 11 부터 변환 오류

	std::cout << num << std::endl;
	std::cout << num2 << std::endl;
	std::cout << num3 << std::endl;
	std::cout << num4 << std::endl;
	std::cout << x << std::endl;
	std::cout << x1 << std::endl;

	return 0;
}