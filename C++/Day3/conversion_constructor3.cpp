/*
	변환 생성자 : 다른 타입의 객체로 변환될 때 호출되는 생성자.
	입력을 한 개만 가지는 생성자
	암묵적인 변환을 허용하지 않는다.
*/
#include <iostream>

class MyClass {
private:
	int value;
public:
	explicit MyClass(int value) {							
		// explicit: 암시적(implicit) 변환을 방지
		// 명시적(explicit)으로만 객체를 생성할 수 있도록 제한
		std::cout << "변환 생성자 호출!!" << std::endl;
		this->value = value;
	}
	void printMyClass() {
		std::cout << "value : " << value << std::endl;
	}
};
int main()
{
	// MyClass obj = 10;			// 변환생성자 호출-객체의 변환이 일어남
	// obj.printMyClass();

	MyClass obj2{ 10 };
	obj2.printMyClass();
	return 0;
}