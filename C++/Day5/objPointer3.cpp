

#include <iostream>

class MyClass {
public:
	int value;
	// MyClass(){}
	MyClass(int v = 0) : value(v) {}
	void showMyClass() {
		std::cout << "value : " << value << std::endl;
	}
};
int main()
{
	MyClass* ptr = new MyClass{ 10 };
	ptr->showMyClass();
	std::cout << "value : " << ptr->value << std::endl;

	delete ptr;

	MyClass obj{};		// 디폴트 매개변수에 값을 주거나, 생성자를 생성 하면 가능
	ptr = &obj;

	ptr->showMyClass();
	(*ptr).showMyClass();		// ptr->showMyClass();와 같음
	std::cout << "value : " << ptr->value << std::endl;

	return 0;
}