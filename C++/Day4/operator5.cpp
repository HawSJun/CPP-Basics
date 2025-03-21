
#include <iostream>

class MyClass {
public:
	int x, y;
public:
	MyClass(int _x, int _y) : x(_x), y(_y){ }
	MyClass add(const MyClass& other) {
		std::cout << "add" << std::endl;
		return MyClass(x + other.x, y + other.y);
	}
	MyClass operator+(const MyClass& other)
	{
		std::cout << "operator" << std::endl;
		return MyClass(x + other.x, y + other.y);
	}
	MyClass operator+(int val) {
		std::cout << "객체 + int" << std::endl;
		return MyClass(x + val, y + val);
	}
	void showMyClass() {
		std::cout << "x : " << x << ", y : " << y << std::endl;

	}
};

int main()
{
	MyClass obj(10, 20);
	obj.showMyClass();

	MyClass obj2(20, 30);
	obj2.showMyClass();

	MyClass obj3 = obj.add(obj2);
	obj3.showMyClass();

	MyClass obj4 = obj.operator+(obj3);
	obj4.showMyClass();

	MyClass obj5 = obj4 + 100;  // obj4.operator+(100)
	obj5.showMyClass();

	return 0;
}

// 오버로딩 할 수 없는 연산자
// ::, ., *, sizeof