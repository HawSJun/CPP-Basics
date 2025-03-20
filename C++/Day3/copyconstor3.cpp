/*
	복사생성자 - 깊은복사
	- 동적할당 받은 경우 복사하는 객체도 동적 할당 받아서 별개로 복사하여 저장이 되어야 한다.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

class Person {
public:
	char* name;			// 동적할당으로 구현시 포인터로
	int age;
public:
	Person(const char* name, int age) {
		std::cout << "Constructor call!!" << std::endl;
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
		this->age = age;
	}
	Person(const Person& other) {			// 복사생성자. 매개변수로 객체를 전달할때는 참조를 받아야함!!
		std::cout << "copy constructor!!" << std::endl;
		this->age = other.age;
		this->name = new char[strlen(other.name) + 1];
		strcpy_s(this->name, strlen(other.name) + 1, other.name);
	}
	void printPerson() {
		std::cout << "name : " << this->name << ", age : " << this->age << std::endl;
	}
	~Person() {
		delete[] this->name;
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
/*
	디폴트로 자동으로 제공 받는 생성자 : 디폴트 생성자, 복사 생성자, 소멸자
*/

// 얕은 복사와 깊은 복사 공부!!!!

//-복사생성자
//- 복사생성자의 매개인자가 레퍼런스가 아닌경우 매개인자로 쓸 변수를 위해 복사생성자 호출이 또 일어나게된다. * *(무한재귀) * *
//-우리가 의도한 대로 동작시키려면 레퍼런스타입을 명시해주어야한다.
//- 이를 이해하기위해서는 함수의 매개인자와 * *임시변수(객체) * *의 생성을 이해해야한다.
//
//- 임시변수
//```CPP
//con(con _other) << --이 구문이 실행될 때 무슨 일이 일어날까 ?
//
//컴파일러는 _other 객체를 생성하기위해서 입력인자로 들어온 객체를 "복사" 하게된다.
//입력인자로 p가 들어왔다고 했을 때
//_other 는 con(p) 를 호출 그러면 p 는 또 _other을 만들기 위해 복사를 진행
//... 무한반복
//```
//
//- **얕은복사가 문제가 되는 경우 * *
//-객체의 멤버가 * *동적할당 * *을 하고있는 경우. * *(같은 메모리주소를 참조하게된다.) * *
//-그렇게되면 의도치않은 값의 변경이 일어나거나, 소멸자 호출 시 애매모호해지는 문제가 발생한다.
//
//- 그렇기 때문에 * *깊은복사 * *를 통해 문제해결
//- 새로운 힙메모리 할당 후 독립적인 멤버로 존재하게 해줌.