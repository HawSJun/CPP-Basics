/*
	순환참조 : 두 객체가 서로를 참조하고, 둘 다 shared_ptr을 사용하여 참조를 유지하는 경우에 발생
*/
#include <iostream>

struct B;
struct A {
	std::shared_ptr<B> b_ptr;
};
struct B {
	//std::shared_ptr<A> a_ptr;
	std::weak_ptr<A> a_ptr;
};
int main()
{
	std::shared_ptr<A> a(new A());
	std::shared_ptr<B> b(new B());

	a->b_ptr = b;
	b->a_ptr = a;

	return 0;
}

// STL(Standard Template Library)
// container : 객체를 저장하고 관리하는 자료구조
// 컨테이너 종류
// 1. 시퀀스 컨테이너 - 선형적으로 데이터 저장(순서), vector, list, queue
// 2. 연관 컨테이너 - 일정한 규칙으로 저장, set, multiset, map, multimap
// 3. 컨테이너 어탭터 - 변형