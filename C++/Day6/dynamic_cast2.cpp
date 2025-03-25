/*
	dynamic_cast를 이용하여 downcasting 할 경우는 가상함수가 있어야 한다.
*/
#include <iostream>

class Super {
public:
	virtual void func() { std::cout << "Super::func()" << std::endl; }
	void func1() { std::cout << "Super::func1()" << std::endl; }
	void fx() { std::cout << "Super::fx()" << std::endl; }
};
class Sub : public Super {
public:
	void func() { std::cout << "Sub::func()" << std::endl; }
	void func2() { std::cout << "Sub::func2()" << std::endl; }
	void fx() { std::cout << "Super::fx()" << std::endl; }
};

int main()
{
	Super* sp = new Super{};
	sp->func();
	sp->func1();
	sp->fx();

	std::cout << "----------Upcasting----------" << std::endl;
	Super* sp2 = new Sub{};
	sp2->func();
	sp2->func1();
	sp2->fx();
	//sp2->func2();

	std::cout << "----------Downcasting----------" << std::endl;
	Sub* sp3 = dynamic_cast<Sub*>(sp2);
	sp3->func();
	sp3->func1();
	sp3->func2();
	sp3->fx();

	delete sp;
	delete sp2;

	return 0;
}