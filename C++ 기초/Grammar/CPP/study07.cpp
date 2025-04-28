#include <iostream>

int main()
{
	// 문자열 : 문자의 열
	// char a[5] = { 'H', 'e', 'l', 'l', 'o' }; -> Hello 출력 후 의미 없는 문자들 출력

	char a[6] = { 'H', 'e', 'l', 'l', 'o', '\0' };

	std::cout << a << std::endl;

	// char b[] = { 'H', 'e', 'l', 'l', 'o' };
	// -> 배열의 사이즈를 비워두면 컴파일러가 자동으로 사이즈를 구해줌

	// ""를 이용해서 배열 초기화 하면 명시적으로 널문자를 포함하기때문에 Hello 출력
	char b[] = "Hello";

	std::cout << b << std::endl;


	return 0;
}