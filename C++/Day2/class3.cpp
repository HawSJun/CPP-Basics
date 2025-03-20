/*
	생성자 : constructor
	생성자 호출로 객체가 만들어 진다.
	객체 생성 시 두조에 맞는 생성자가 없으면 객체는 생성되지 않는다.
	생성자는 초기화 기능에 사용한다.
	생성자는 오버로딩이 가능하다.
	프로그래머가 생성자를 작성하면 더 이상 디폴트 생성자는 제공되지 않는다.
*/

#include <iostream>

using namespace std;

class MyClass {
private:
	int m_num1;
	int m_num2;
	int m_num3;
public:
	MyClass(int num3) {			// 기본 생성자
		m_num1 = 0;
		m_num2 = 0;
		m_num3 = num3;
	}

	MyClass(int num1, int num2) {	// 생성자(입력을 두개 받는)
		m_num1 = num1;
		m_num2 = num2;
		m_num3 = 0;
	}
	void printData() {
		cout << "나는 MyClass의 인스턴스 입니다. ";
		cout << "m_num1 : " << m_num1 << "     m_num2 : " << m_num2 << "     m_num3 : " << m_num3 << endl;
	}
};

int main()
{
	MyClass obj(300);
	obj.printData();

	MyClass obj2(100, 200);
	obj2.printData();

	return 0;
}