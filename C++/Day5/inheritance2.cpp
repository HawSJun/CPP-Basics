#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

class Human {
protected:
	char name[20];
	int age;
public:
	Human(const char* _name, int _age) {
		strcpy(name, _name);
		age = _age;
	}
	void getData() {
		std::cout << "이름 : " << name << ", 나이 : " << age << std::endl;
	}
};
class Student : public Human {
private:
	int studentID;
public:
	Student(const char* aname, int aage, int astudentID) : Human(aname, aage) {		// 콜론 초기화
		// strcpy(name, aname);											
		// age = aage;													
		studentID = astudentID;
	}
	void showStudent() {
		std::cout << "이름 : " << name << ", 나이 : " << age << std::endl;
		std::cout << "학번 : " << studentID << std::endl;
	}
};
int main()
{
	Human h("홍길동", 25);
	h.getData();

	Student h2{ "임꺽정", 30, 202503 };
	h2.getData();

	h2.showStudent();

	return 0;
}