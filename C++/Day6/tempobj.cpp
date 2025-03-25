#include <iostream>

class MyClass {
private:
	int num;
public:
	MyClass(int n) : num(n) {
		std::cout << num << " constructor" << std::endl;
	}
	~MyClass() { std::cout << num << " destructor" << std::endl; }
};

int main()
{
	MyClass obj{ 10 };
	MyClass obj2 = MyClass{ 20 };			// 이름 없는 임시 객체를 복사해서 생성됨
	MyClass{ 30 };							// 임시객체는 다음 행으로 넘어가면 사라짐

	std::cout << "bye~~~" << std::endl;

	return 0;
}