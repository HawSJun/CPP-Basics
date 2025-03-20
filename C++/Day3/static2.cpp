
#include <iostream>

class AAA {
private:
	static int static_a;					// static 멤버변수
	int n;
public:
	AAA(int n);
	static void setStatic_a(int a);			// static 멤버함수
	void print();
};

int AAA::static_a = 100;

AAA::AAA(int n) {
	this->n = n;
}
void AAA::print() {
	std::cout << "static_a : " << static_a << ", n : " << n << std::endl;
}
void AAA::setStatic_a(int a) {
	static_a = a;
	//n = 0;					// 일반 멤버의 접근은 허용되지 않는다. static 멤버의 사용만 가능.
}
int main()
{
	AAA obj1(10), obj2(20);
	obj1.print();
	obj2.print();

	obj1.setStatic_a(50);
	obj1.print();

	return 0;
}