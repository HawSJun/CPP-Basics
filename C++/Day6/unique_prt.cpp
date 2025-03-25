/*
	스마트 포인터 : unique_ptr
	객체의 생명 주기를 객체에 맡김으로 프로그래머의 메모리 관리 부담을 줄여준다.

	unique_ptr : 소유권을 독점적으로 관리하는 스마트 포인터(auto_ptr 을 대체)
*/

#include <iostream>

class MyClass {
public:
	MyClass() { std::cout << "MyClass() 호출" << std::endl; }
	~MyClass() { std::cout << "~MyClass() 호출" << std::endl; }
};

int main()
{
	std::unique_ptr<MyClass> ptr(new MyClass{});
	std::unique_ptr<MyClass> ptr2 = move(ptr);
	return 0;
}