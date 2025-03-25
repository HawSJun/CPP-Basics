#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v;
	std::cout << "[ v[i], v.size(), v.capcity() ]" << std::endl;

	for (int i = 0; i <= 32; i++) {
		v.push_back(i + 1);
		std::cout << "[ " << v[i] << ", " << v.size() << ", " << v.capacity() << " ]" << std::endl;
	}

	std::vector<int> v2;
	v2.push_back(10);
	v2.push_back(11);
	v2.push_back(12);
	v2.push_back(13);

	v2.insert(v2.begin(), 1);
	v2.insert(find(v2.begin(), v2.end(), 13), 20);

	for (auto i : v2) {
		std::cout << i << std::endl;
	}

	v2.pop_back();			// 마지막 원소 제거
	for (auto i : v2) {
		std::cout << i << std::endl;
	}

	return 0;
}

/*
	v.push_back(10) : 마지막 원소 뒤에 10을 추가한다.
	v.insert(idx, val) : idx번째 위치에 val을 넣는다.
	v.capacity() : 벡터에 할당된 메모리 크기를 리턴한다. - v.size()
*/