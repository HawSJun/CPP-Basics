/*
	step4.
	char 포인터의 name, int 타입의 age, 출력을 담당하는 showHuman()을 가지는 Human 클래스가 있다.
	name을 동적할당하고 나이 30, 이름 홍병보 man 객체를 생성하시오.
	xman = copyman을 출력하시오.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Human {
private:
	char* name;
	int age;
public:
	// Human(){}
	Human(const char* _name = " ", int _age = 0) {						// 초기값을 주면 기본생성자 추가 안해도됨
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
	//Human& operator=(const Human& other) {
	//	std::cout << "------ 대입 연산자 ------" << std::endl;
	//	name = new char[strlen(other.name) + 1];
	//	strcpy(name, other.name);
	//	age = other.age;
	//	return *this;
	//}
	~Human() {
		std::cout << "--------- 소멸자 ---------" << std::endl << std::endl;;
		delete[] name;
	}
	void showHuman() {
		std::cout << "이름 : " << name << ", 나이 : " << age << std::endl << std::endl;
	}
	const Human& operator=(const Human& other);
};

const Human& Human::operator=(const Human& other) {
	if (this != &other) {											// xman = copyman; 같지 않으면 복사
		delete[]name;
		std::cout << "------- 대입연산자 -------" << std::endl;
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
		age = other.age;
	}
	return *this;
}

int main()
{
	Human man("홍명보", 30);
	man.showHuman();

	Human copyman(man);
	copyman.showHuman();

	Human xman;
	xman = copyman;
	xman.showHuman();

	return 0;
}