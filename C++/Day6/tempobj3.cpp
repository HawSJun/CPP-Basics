#include <iostream>

class MyClass {
	int num;
public:
	MyClass(int n) : num(n) { std::cout << this << ", "<< num << " constructor" << std::endl; }
	MyClass(const MyClass& other) : num(other.num) { std::cout << this << " copy constructor" << std::endl; }
	~MyClass() { std::cout << this << ", " << num << " destructor" << std::endl; }
	void setData(int n) { num = n; }
};
MyClass func(const MyClass& aobj) {					// 참조하게 되면 생성자 호출 안됨
	std::cout << "func()" << std::endl;
	return aobj;
}
int main()
{
	MyClass obj{ 10 };
	MyClass obj2{ func(obj) };
	std::cout << "bye~~~" << std::endl;

	return 0;
}

// 임시객체 생성은 call by value