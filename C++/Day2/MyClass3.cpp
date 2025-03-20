/*
	MyClass를 class 밖으로 빼서 작성할 시 클래스 이름을 생성자 앞에 작성 후 범위지정연산자(::) 입력
	ex) MyClass::
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

class MyClass {
private:
	int id;
	char* name;
	int age;

public:
	MyClass(int a, const char* b, int c);
		
	~MyClass() {
		delete[] name;
	}
	void getData() const;
};

MyClass::MyClass(int a, const char* b, int c) {
	id = a;
	name = new char[strlen(b) + 1];
	// name = _name;				
	strcpy(name, b);
	//strncpy(name, b, strlen(b));    // 문자열 복사
	//name[strlen(b)] = '\0';         // 널 종료 문자 추가
	age = c;
}

void MyClass::getData() const {			// 상수 멤버 함수(모든 멤버들을 상수화 시킨다.)
	std::cout << "번호 : " << id << "  이름 : " << name << "  나이 : " << age << std::endl;
}

int main() {
	MyClass obj(1, "김철수", 20);
	obj.getData();  // 출력 확인

	return 0;
}

// mutable : 상수화 시키지 않는 키워드