/*
	복사생성자
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Person {
public:
	char name[20];
	int age;
public:
	Person(const char* name, int age) {
		std::cout << "Constructor call!!" << std::endl;
		strcpy(this->name, name);
		this->age = age;
	}
	Person(const Person& other) {			// 복사생성자. 매개변수로 객체를 전달할때는 참조를 받아야함!!
		std::cout << "copy constructor!!" << std::endl;
		this->age = other.age;
		strncpy(this->name, other.name, strlen(other.name) + 1);
	}
	void printPerson() {
		std::cout << "name : " << this->name << ", age : " << this->age << std::endl;
	}
};

int main()
{
	Person p("홍길동", 30);
	p.printPerson();

	Person p2(p);
	p2.printPerson();

	Person p3 = p;
	p3.printPerson();

	return 0;
}