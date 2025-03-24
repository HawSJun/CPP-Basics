/*
	객체 동적 생성
*/
#include <iostream>

class AClass {
public:
	void showAClass() {
		std::cout << "Dynamically created object" << std::endl;
	}
};

int main()
{
	AClass* ptr = new AClass{ };				// 객체 동적 할당
	ptr->showAClass();

	delete ptr;									// 동적 메모리 해제

	return 0;
}