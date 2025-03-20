/*
	함수 오버로딩 - 이름은 같은데 매개변수 타입이이나 갯수가 다르면 다른 함수이다.
*/
#include <iostream>

using namespace std;

int func() {
	return 10;
}
int func(char c) {
	return c;
}
int  func(int n) {
	return 10 + n;
}
int func(int n1, int n2) {
	return n1 + n2;
}
//char func(char c) {
//	return c;
//}

int main()
{
	cout << func() << endl;
	cout << func('a') << endl;
	cout << func(10) << endl;
	cout << func(10, 20) << endl;


	return 0;
}