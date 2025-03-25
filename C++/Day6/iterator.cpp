#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v = { 10, 20, 30, 40, 50 };

	std::vector<int>::iterator it;
	for (it = v.begin(); it != v.end(); it++) {
		std::cout << *it << std::endl;
	}
	std::cout << std::endl;

	for (auto it = v.begin(); it < v.end(); it++) {
		std::cout << *it << std::endl;
	}
	std::cout << std::endl;

	return 0;
}

/* 
	vector<int>::iterator iter는 순방향 반복자 선언 
	근데 위에 구문을 생력하고 auto로 선언해도 된다. 
*/
