/*
	vector
*/

#include <iostream>
#include <vector>		// vector 헤더파일 포함

int main()
{

	std::vector<int> v;
	std::vector<int> v1{ 10 };
	std::vector<int> v2(5);
	std::vector<int> v3 = { 1, 2, 3, 4, 5, 6 };

	std::cout << "v size : " << v.size() << std::endl;
	std::cout << "v1 size : " << v1.size() << std::endl;
	std::cout << "v2 size : " << v2.size() << std::endl;
	std::cout << "v3 size : " << v3.size() << std::endl;
	
	for (int i = 0; i < 5; i++) {
		printf("v2[%d] : %d\n", i, v2[i]);
	}
	for (auto i : v3) {			// 범위기반 for문 - 인덱스 사용이 불가
		//std::cout << v3[i] << std::endl;
		std::cout << i << std::endl;
	}

	/* begin()과 end()는 iterator(반복자) 타입을 반환한다. */
	std::cout << "v3의 첫번째 요소값 : " << *v3.begin() << std::endl;
	std::cout << "v3의 마지막 요소값 : " << *(v3.end() -1) << std::endl;
	return 0;
}

/*
	vector.size() : 원소 크기(갯수)를 반환
	vector.begin() : 벡터의 첫 번째 요소를 가리키는 반복자를 반환
	vector.end() : 벡터의 마지막 요소의 다음 위치를 가리키는 반복자를 반환
*/