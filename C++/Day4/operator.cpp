#include <iostream>

class MyClass {
private:
	int m_a, m_b;
	//const char* m_name;
public:
	MyClass(int a = 0, int b = 0, const char* name = nullptr) : m_a(a), m_b(b) {
		// 디폴트 생성자를 생성했기 때문이 입력을 가지지 않는 기본 매개변수 만들 수 있음

	}
	void showMyClass() {
		std::cout << m_a << ", " << m_b << ", " << std::endl;
	}
};

int main()
{
	/*MyClass obj{ 1, 2, "홍길동" };
	obj.showMyClass();*/

	//MyClass obj2;
	//obj2 = obj;				// 디폴트 대입연산자
	//obj2.showMyClass();
	MyClass obj{ 10, 20 };
	MyClass obj2{ 30, 40 };
	MyClass obj3 = obj + obj2;

	return 0;
}