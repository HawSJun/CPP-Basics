/*
	step3.
	char 포인터의 name, int 타입의 age, 출력을 담당하는 showHuman()을 가지는 Human 클래스가 있다.
	name을 동적할당하고 나이 30, 이름 홍병보 man 객체를 생성하시오.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Human {
private:
	char* name;
	int age;
public:
	Human(const char* _name, int _age) {
		std::cout << "--------- 생성자 ---------" << std::endl;
		name = new char[strlen(_name) + 1];
		strcpy(name, _name);
		age = _age;
	}
	Human(const Human& other) {
		std::cout << "------- 복사생성자 -------" << std::endl;
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
		age = other.age;
	}
	~Human() {
		std::cout << "--------- 소멸자 ---------" << std::endl << std::endl;;
		delete[] name;
	}
	void showHuman() {
		std::cout << "이름 : " << name << ", 나이 : " << age << std::endl << std::endl;
	}
};

int main()
{
	Human man("홍명보", 30);
	man.showHuman();
	
	Human copyman(man);
	copyman.showHuman();

	// Human xman;
	// xman = copyman;
	// xman.showHuman();

	return 0;
}