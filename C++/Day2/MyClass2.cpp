#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

class MyClass {
private:
	int id;
	char* name;
	int age;

public:
	// 생성자
	MyClass(int a, const char* b, int c) {
		id = a;
		name = new char[strlen(b) + 1];  // 동적 메모리 할당
		// name = _name;				// 배열을 선언한 후에 대입 연산자를 사용하여 값을 직접 할당할 수 없다.
		strcpy(name, b);
		//strncpy(name, b, strlen(b));    // 문자열 복사
		//name[strlen(b)] = '\0';         // 널 종료 문자 추가
		age = c;
	}

	// 소멸자 (할당된 메모리 해제)
	// 동적할당 경우 말고는 별도로 작성할 필요가 없다.
	~MyClass() {
		delete[] name;
	}

	// 데이터 출력
	void getData() {
		std::cout << "id : " << id << "  name : " << name << "  age : " << age << std::endl;
	}
};

int main() {
	MyClass obj(1, "김철수", 20);
	obj.getData();  // 출력 확인

	return 0;
}

// "김철수"만 메모리 동적할당 받아서
