/*
	vector container 출력
*/

#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	printf("%d\n", v[2]);

	/* 출력 1 */
	for (auto i = 0; i < v.size(); i++) {
		std::cout << v[i] << std::endl;
		std::cout << v.at(i) << std::endl;
	}
	std::cout << std::endl << std::endl;

	/* 출력 2 */
	for (std::vector<int>::size_type i = 0; i < v.size(); i++) {
		std::cout << v[i] << std::endl;
	}
	std::cout << std::endl << std::endl;

	/* 출력 3 */
	std::vector<int>::iterator iter;
	for (iter = v.begin(); iter != v.end(); iter++) {
		std::cout << *iter << std::endl;
	}
	std::cout << std::endl << std::endl;

	/* 출력 4 */
	for (auto i : v) {
		std::cout << i << std::endl;
	}

	return 0;
}