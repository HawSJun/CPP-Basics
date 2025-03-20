/*
	이동생성자(T&&)
	r-value reference 를 파라미터로 갖는 이동 생성자
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Human {
private:
	char name[10];
	int age;
public:
	// 입력 2개 받는 생성자
	Human(const char* name, int age) {
		std::cout << "입력 2개 생성자 호출!!" << std::endl;
		strcpy(this->name, name);
		//strcpy_s(this->name, sizeof(this->name), name);		//  strcpy_s(dest, sizeof(dest), src);
		this->age = age;
	}
	// 복사 생성자
	Human(const Human& other){
		std::cout << "복사 생성자 호출!!" << std::endl;
		strcpy(this->name, other.name);
		//strcpy_s(this->name, sizeof(other.name), other.name);
		this->age = other.age;
	}
	// 이동 생성자
	Human(Human&& other) noexcept{
		std::cout << "이동 생성자 호출!!" << std::endl;
		strcpy(this->name, other.name);
		//strcpy_s(this->name, sizeof(other.name), other.name);
		this->age = other.age;

		// other.name = nullptr;
		other.age = 0;
	}
	void printHuman() {
		std::cout << "name : " << this->name << ", age : " << this->age << std::endl;
	}
};
int main()
{
	Human h("홍길동", 30);
	h.printHuman();

	Human h2(h);
	h2.printHuman();

	Human h3(std::move(h));
	h3.printHuman();

	h.printHuman();

	return 0;
}

// noexcept 붙히는 이유
// 복사생성자 실행시 컴파일러가 최적화를 위해
// 복사할 데이터크기가 작으면 이동생성자여도 복사연산을 수행할 수도 있기 때문에, 
// 그냥 무슨일이있어도 이동시켜라라는 기능