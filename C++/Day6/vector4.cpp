/*
	vector container - 삽입, 삭제, 참조
*/

#include <iostream>
#include <vector>

int main()
{
	std::vector<std::string> v;

	v.push_back("tiger");
	v.push_back("lion");
	v.push_back("elephant");
	v.push_back("horse");

	std::cout << "v.front() : " << v.front() << std::endl;
	std::cout << "v.back() : " << v.back() << std::endl;
	std::cout << "v.capacity() : " << v.capacity() << std::endl << std::endl;

	std::vector<std::string>::iterator iter;
	for (iter = v.begin(); iter != v.end(); iter++) {
		std::cout << *iter << " / ";
	}
	std::cout << std::endl;

	v.pop_back();
	for (iter = v.begin(); iter != v.end(); iter++) {
		std::cout << *iter << " / ";
	}
	std::cout << std::endl;

	for (iter = v.begin(); iter != v.end(); iter++) {
		if (*iter == "elephant") {
			v.erase(iter);
			break;
		}
	}
	std::cout << std::endl;

	for (iter = v.begin(); iter != v.end(); iter++) {
		std::cout << *iter << " / ";
	}

	return 0;
}
/*
	iterator 타입 : iterator, begin(), end()
*/