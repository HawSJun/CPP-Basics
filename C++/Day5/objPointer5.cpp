/*
	상속에서 객체 포인터
	부모 타입의 포인터로 자식 타입의 객체를 가리키면 객체가 부모타입으로 업캐스팅된다.
*/

#include <iostream>

class Base {
public:
	void show() {
		std::cout << "Base Class!!" << std::endl;
	}
};
class Derived : public Base {				// 오버라이딩(재정의)
public:
	void show()
	{
		std::cout << "Derived Class!!" << std::endl;
	}
};
int main()
{
	Base* bptr = nullptr;
	Derived* dptr = nullptr;

	Derived obj;					// 파생클래스 객체
	dptr = &obj;
	dptr->show();

	bptr = &obj;					// 부모타입의 포인터로 자식 객체를 가리킨다.(Upcasting)
	bptr->show();

	return 0;
}