/*
	cin - 입력을 담당하는 객체
*/

#include <iostream>

using namespace std;

int main()
{
	/*int inVal;
	cout << "숫자 입력>> ";
	cin >> inVal;
	cout << "inVal : " << inVal << endl;*/

	int a;
	int b;

	cout << "두 개의 숫자 입력>> ";
	cin >> a >> b;
	cout << "덧셈결과 : " << a + b << endl;

	return 0;
}

// 함수의 다형성
// 함수 오버로딩(함수의 다중정의)
// 함수 오버라이딩(함수의 재정의) - 상속