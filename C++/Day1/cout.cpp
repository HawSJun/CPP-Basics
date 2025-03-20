#include <iostream>

using namespace std;		// std 네임스페이스를 생략하여 사용할 수 있도록 설정

int main()
{
	int num = 100;
	char str[100] = "홍길동";
	double d = 3.14;
	float f = 3.1f;

	std::cout << "abcdefg" << std::endl;		// std::endl : 줄바꿈을 의미, 출력 후 개행
	std::cout << num << std::endl;
	std::cout << str << std::endl;
	std::cout << d << std::endl;
	cout << f << endl;

	return 0;
}