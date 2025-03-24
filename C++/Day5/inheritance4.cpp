/*
	상속 관계에서 객체 생성 및 소멸
*/

#include <iostream>

class SuperClass {
private:
	int num;
public:
	SuperClass(int an) {
		num = an;
		std::cout << num << " SuperClass constructor" << std::endl;
	}
	~SuperClass() {
		std::cout << num << " SuperClass Destructor" << std::endl;
	}
};
class SubClass : public SuperClass {
private:
	int subNum;
public:
	SubClass(int an, int an2) : SuperClass(an) {
		subNum = an2;
		std::cout << subNum << " SubClass construcor" << std::endl;
	}
	~SubClass() {
		std::cout << subNum << " SubClass Destructor" << std::endl;
	}
};
int main()
{
	SuperClass s{ 1 };
	SubClass sub{ 2, 22 };

	return 0;
}

/* 객체를 생성할 때 호출되는 생성자와 생성자의 실행은 다르다. 
	즉 생성자의 호출과 생성자의 실행은 다르다.
*/