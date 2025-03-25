/*
	weak_ptr : 레퍼런스 카운트에 영향을 주지 않는 스마트 포인터
*/

#include <iostream>

class MyClass {
public:
	MyClass() { std::cout << "MyClass constructor!!" << std::endl; }
	~MyClass() { std::cout << "MyClass destructor!!" << std::endl; }
	void func() { std::cout << "Hi shared_ptr" << std::endl; }
};

int main()
{
	std::shared_ptr<MyClass>ptr = std::make_shared<MyClass>();		// c++14 이후부터 지원
	std::weak_ptr<MyClass>weakPtr = ptr;

	// weak_ptr은 순환참조를 방지한다.
	std::shared_ptr<MyClass>ptr2 = weakPtr.lock();					// weak_ptr에서 shared_ptr 변환
	if (ptr2) { std::cout << "weak_ptr로 변환 한 shared_ptr 사용가능" << std::endl; }

	return 0;
}