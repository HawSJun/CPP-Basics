/*
	함수 오버로딩 중에서 default 매개변수와 입력이 없는 순수한 함수 정의가 있을 때
	입력 없는 함수 호출 시 문제가 발생한다.
*/
#include <iostream>

using namespace std;

int func(int n = 0) {
	// 기본 매개변수가 0 값을 가지고 있어서 func(0)이 되어 호출 가능함
	// 그럼 func()를 호출할 때 두 개의 후보 함수가 존재해서 컴파일 오류 발생!\
	// int func(int n)으로 변경 시 동작 함. 
	// why?) 기본값이 설정되어있지않아서
	return n * n;
}
int func() {
	return 10;
}

int main()
{
	cout << func(10) << endl;
	cout << func() << endl;

	return 0;
}