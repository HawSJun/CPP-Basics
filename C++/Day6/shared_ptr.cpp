/*
	shared_ptr
	make_shared : 객체와 참조 카운트를 하나의 메모리 블록에 같이 할당 시킨다. shared_ptr을 생성하는 함수
	shared_ptrs는 참조 카운트를 통해 객체의 소유권을 공유한다. 여러개의 shared_ptr이 객체를 참조할 수 있으며
	레퍼런스 카운트가 0이되면 메모리가 자동 해제된다.
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
	std::shared_ptr<MyClass>ptr = std::make_shared<MyClass>();
	std::shared_ptr<MyClass>ptr2 = ptr;

	std::cout << "ptr과 ptr2는 동일한 객체를 가리킨다. 공유한다" << std::endl;

	ptr2->func();

	return 0;
}