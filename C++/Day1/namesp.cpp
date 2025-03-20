/*
	namespace는 이름 충돌을 방지하기 위해 사용
	즉, 서로 다른 코드에서 같은 이름의 함수, 변수, 클래스 등을 정의하더라도, 네임스페이스를 이용하면 구별할 수 있다.
*/

#include <stdio.h>

namespace aName {
	void func() {
		printf("aName::func()\n");
	}
}
namespace bName {
	void func() {
		printf("bName::func()\n");
	}
}
namespace cName {
	void func() {
		printf("cName::func()\n");
	}
}
using namespace cName;

int main()
{
	aName::func();
	bName::func();
	func();
	return 0;
}