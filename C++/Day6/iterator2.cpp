#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v = { 10, 20, 30, 40, 50 };

	std::vector<int>::reverse_iterator rit;
	for (rit = v.rbegin(); rit != v.rend(); rit++) {
		std::cout << *rit << std::endl;
	}
	std::cout << std::endl;

	for (auto rit = v.rbegin(); rit != v.rend(); rit++) {
		std::cout << *rit << std::endl;
	}
	return 0;
}

/*
	vector<int>:reverse_iterator rit - 역방향 반복자 선언
	위 구문을 생력하고 auto로 선언해도 된다.
	rbegin()은 마지막 주소, rend()은 처음 원소의 이전 주소
*/