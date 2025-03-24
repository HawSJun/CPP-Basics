/*
	Inheritance(상속)
	private, public, protected
	is a(무엇은 무엇이다.), has a(소유) 관계가 성립해야 한다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

class Human {								// 부모 클래스, 기초 클래스, 슈퍼 클래스, 베이스 클래스
private:
	char name[20];
	int age;
public:
	Human(const char*, int);
	void getData();
};
class Student : public Human {				// 자식 클래스, 파생 클래스, 서브 클래스, 드라이버드 클래스
private:
	int studentID;
public:
	Student(const char* name, int age, int studentID);
	void showStudent();
};
Human::Human (const char *aname, int aage) {
	strcpy(name, aname);
	age = aage;
}
void Human::getData() {
	std::cout << "이름 : " << name << ", 나이 : " << age << std::endl;
}
/* 상속 받은 멤버들은 상속한 부모 클래스의 생성자에서 초기화를 한다. */
Student::Student(const char* aname, int aage, int astudentID) : Human(aname, aage) {		// 콜론 초기화
	// strcpy(name, aname);											
	// age = aage;													
	studentID = astudentID;
}
void Student::showStudent() {
	//std::cout << "이름 : " << name << std::endl;
	std::cout << "학번 : " << studentID << std::endl;
}
int main()
{
	Human h("홍길동", 25);
	h.getData();

	Student h2{ "임꺽정", 30, 202503 };
	h2.getData();

	h2.showStudent();

	return 0;
}	


// 부모 클래스 객체가 먼저 생성되어 있어야 그 객체를 통해 물려받을 수 있다.
// // 자식 클래스 객체를 생성할 수 있다.