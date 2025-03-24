/*
	다운캐스팅 : 자식 포인터로 부모 객체를 가리킬 수 없다.
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
	void show() {
		std::cout << "Derived Class!!" << std::endl;
	}
};
int main()
{
	Base bobj();
	Derived* dptr = nullptr;
	// dptr = &bobj;
	//dptr = (Base*)&bobj;
	//dptr->show();

	dptr = (Derived*)&bobj;
	dptr->show();

	return 0;
}