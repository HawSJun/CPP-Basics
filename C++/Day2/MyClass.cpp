#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class MyClass {
private:
	int id;
	char name[20];
	int age;
public:
	//MyClass() {}		// 디폴트 생성자
	void setData(int a, const char* b, int c) {
		id = a;
		strcpy(name, b);	// 버퍼 오버플로우 위험이 있음!
							//strncpy(name, b, sizeof(name));
		age = c;
	}
	void getData() {
		std::cout << "id : " << id << "  name : " << name << "  age : " << age << std::endl;
	}
};
int main()
{
	MyClass obj;
	obj.setData(1, "김철수", 20);
	obj.getData();
	return 0;
}


// char *strncpy(char *dest, const char *source, size_t count)
// dest : 배열을 가리키는 포인터로 문자열이 복사될 곳
// source : 복사 될 문자열
//count : source 에서 복사 할 문자의 개수 이다.