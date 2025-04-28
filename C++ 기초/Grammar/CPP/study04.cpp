#include <iostream>

int main()
{
	// char : 작은 문자형
	int a = 77;
	char c = a;	// 아스키코드 'M' 출력
	std::cout << c << std::endl;

	char b = 'a';
	std::cout << b << std::endl;


	//char ch[] = { 'a', 'b', 'c' };	// 널문자가 없어서 계속 출력됨(이상한 값이 계속 출력)
	char ch[] = { 'a', 'b', 'c', '\0' };	// 널문자가 있어 abc 출력
	std::cout << ch << std::endl;

	// null 문자 '\0' -> 문자열을 출력하다가 널문자가 만나면 출력 끝!
	// "" >> 명시적으로 null 문자가 포함되어 있음 --> string


	// bool : 0 혹은 1 (false or true) -> 0 이외의 모든 숫자는 1
	bool b1 = 0;
	bool b2 = 1;
	bool b3 = 10;
	std::cout << b1 << " " << b2 << " " << b3 << std::endl;

	return 0;
}