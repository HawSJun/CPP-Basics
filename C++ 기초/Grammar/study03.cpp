#include <iostream>
#include <climits>

int main()
{
	// 정수형 : 소수부가 없는 수
	// 음의 정수, 0, 양의 정수
	// short, int, long, long long

	int n_int = INT_MAX;
	short n_short = SHRT_MAX;
	long n_long = LONG_MAX;
	long long n_llong = LLONG_MAX;

	std::cout << "int는 " << sizeof n_int << "바이트이다." << std::endl;
	std::cout << "이 바이트의 최대값은 " << n_int << " 이다." << std::endl << std::endl;

	std::cout << "short는 " << sizeof n_short << "바이트이다." << std::endl;
	std::cout << "이 바이트의 최대값은 " << n_short << " 이다." << std::endl << std::endl;;

	std::cout << "long는 " << sizeof n_long << "바이트이다." << std::endl;
	std::cout << "이 바이트의 최대값은 " << n_long << " 이다." << std::endl << std::endl;

	std::cout << "long long는 " << sizeof n_llong << "바이트이다." << std::endl;
	std::cout << "이 바이트의 최대값은 " << n_llong << " 이다." << std::endl << std::endl;

	// int, short, long, long long 은 음의 정수값을 저장할 수 없는 unsigned 를 가지고 있다.
	unsigned int a;
	unsigned short b;
	unsigned long c;
	unsigned long long d;

	// 실수형 : 소수부가 있는 수
	float f = 3.14;
	int i = 3.14;	// 3 출력

	std::cout << f << " " << i << std::endl;

	return 0;
}