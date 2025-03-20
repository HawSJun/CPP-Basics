/*
	변환 생성자 : 다른 타입의 객체로 변환될 때 호출되는 생성자.
	입력을 한 개만 가지는 생성자
*/

#include <iostream>

class MyClass {
private:
	int value;
public:
	MyClass(int value) {
		std::cout << "변환 생성자 호출!!" << std::endl;
		this->value = value;
	}
	void printMyClass() {
		std::cout << "value : " << value << std::endl;
	}
};
int main()
{
	MyClass obj = 10;			// 정수타입의 객체를 MyClass 타입의 객체로 변환해서 10을 대입해라
	obj.printMyClass();

	MyClass obj2(10);
	obj2.printMyClass();
	return 0;
}