/*
	step1. 이름과 전화번호는 동적할당.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Human {
private:
	char* pname;
	int age;
	char* ptel;
public:
	Human(const char* _pname, int _age, const char* _ptel) {
		pname = new char[strlen(_pname) + 1];
		strcpy(pname, _pname);
		age = _age;
		ptel = new char[strlen(_ptel) + 1];
		strcpy(ptel, _ptel);
	}
	~Human() {
		delete[] pname;
		delete[] ptel;
	}
	void getData() {
		// std::cout << "이름 : " << pname << "\n나이 : " << age << "\n전화번호 : " << ptel << std::endl;
		std::cout << "이름 : " << pname << std::endl;
		std::cout << "나이 : " << age << std::endl;
		std::cout << "전화번호 : " << ptel << std::endl;
	}
};

int main()
{
	Human h("홍길동", 30, "010-1234-1234");
	h.getData();
}