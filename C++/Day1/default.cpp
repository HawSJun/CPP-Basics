/*
	default 매개변수 : 기본적으로 설정되어 있는 값
*/

#include <iostream>

int func(int num = 10) {
	return num * num;
}
int main()
{
	int res;
	res = func(10);
	std::cout << res << std::endl;

	res = func(0);
	std::cout << res << std::endl;

	res = func();					// 입력이 없으면 디폴트 매개변수가 적용된다
	std::cout << res << std::endl;

	return 0;
}