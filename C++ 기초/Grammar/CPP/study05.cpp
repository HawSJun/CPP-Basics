#include <iostream>
// #define PIE 3.1415926535 -> C 스타일

int main()
{
	// 원의 넓이를 구하는 프로그램
	// 반지름 * 반지름 * 파이

	// 상수는 반드시 선언과 동시에 초기화를 해야한다.
	const float PIE = 3.1415926535;	// C++ 스타일

	int r = 3;
	float s = r * r * PIE;
	std::cout << s << std::endl;

	// 1. 바뀔 필요가 없는 수
	// 2. 바뀌어서는 안되는 수
	// 상수


	// 데이터형 변환
	/*
	1. 특정 데이터형의 변수에 다른 데이터형의 값을 대입했을 때
	2. 수식에 데이터형을 혼합하여 사용했을 때
	3. 함수에 매개변수를 전달할 때
	*/

	int a = 3.141592;
	std::cout << a << std::endl;

	// 강제적으로 데이터형 변환
	// typeName(a), (typeName)a
	char ch = 'M';
	std::cout << (int)ch << " " << int(ch) << std::endl;

	// C++
	//static_cast<typeName>
	std::cout << static_cast<int>(ch) << std::endl;

	return 0;
}