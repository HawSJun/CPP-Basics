/*
	템플릿은 선언과 함수정의가 분리될 수 없다.
*/
#include <iostream>

template <typename T>						// 템플릿 선언(일반화)
T func(T a, T b) {							// 템플릿 함수
	std::cout << "type : T" << std::endl;
	return a + b;
}

template <>
int func<int>(int a, int b) {				// 템플릿 특수화 : 템플릿 일반화 중 특별한 타입을 처리할 경우
	std::cout << "type : <int>" << std::endl;
	return  a + b;
}

int main()
{
	std::cout << func(10, 20) << std::endl;
	std::cout << func(10.5, 20.5) << std::endl;

	std::cout << func<double>(10.1, 20.2) << std::endl;
	std::cout << func<int>(10, 10) << std::endl;

	return 0;
}