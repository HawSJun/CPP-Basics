/*
	virtual function : 파생클래스에서 재정의할 것을 약속받은 멤버 함수를 말하며 Base 클래스의 멤버 함수에
	virtual 키워드를 사용하여 만든다.
	virtual table이 만들어지고, dynamic binding으로 동작한다.
*/

#include <iostream>

class Base {
public:
	virtual void func1() {
		std::cout << "B::func1()" << std::endl;		// 가상함수
	}
	virtual void func2() {
		std::cout << "B::func2()" << std::endl;		// 가상함수
	}
	void func3() {
		std::cout << "B::func3()" << std::endl;
	}
};
class Derived : public Base {
	void func1() override {
		std::cout << "D::func1()" << std::endl;			// 가상함수를 재정의하는 멤버함수를 나타냄.
	}
	void func3() {
		std::cout << "D::func3()" << std::endl;
	}
	void func4() {
		std::cout << "D::func4()" << std::endl;
	}
};
int main()
{
	Base b;
	Derived d;
	Base* bptr = new Derived();				// Upcasting

	bptr->func1();							// base 클래스의 func1()은 가상함수로 선언되어 Derived 클래스의 func1()이 호출된다.
	bptr->func2();							// base 클래스의 func1()은 가상함수로 선언되었지만 오버라이딩(재정의)되지 않았다.
	bptr->func3();							// 포인터 타입의 호출 함수가 결정된다.

	// bptr->func4();

	delete bptr;
	bptr = &b;
	bptr->func1();
	bptr->func2();
	bptr->func3();

	return 0;
}

/* 
   객체 포인터의 다형성으로 기초 클래스 타입의 포인터로 파생 클래스의 객체를 가리키면 접근은 기초 클래스 멤버로 제한된다. 
   이때 오버라이딩 된 파생 클래스의 멤버를 사용하기 위해서는 기초 클래스의 멤버 함수를 가상함수로 만들면 된다.
   이것이 컴파일 시 포인터형으로 바인딩 되지 못하고 런타임에서 포인터가 어떤 객체를 가리키고 있는지에 따라서 바인딩할 함수를 결정한다.
*/