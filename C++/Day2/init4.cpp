/*
	멤버 초기화
	1. 상수
	2. 레퍼런스
	3. 객체를 멤버로 가지는 경우
*/

#include <iostream>

class ConstClass {
private:
	int m_value;
	const int m_value2;		// 상수 멤버 변수는 객체 생성되기 전에 선언과 동시에 초기화 해야 함!!! --> 콜론 초기화
public:
	ConstClass(int value, int value2) : m_value2(value2) { m_value = value; }
	void showValue() {
		std::cout << "m_value : " << m_value << "  m_value2 : " << m_value2 << std::endl;
	}
};

class RefClass {
private:
	int& ref;			// 레퍼런스 역시 객체가 생성되기 전에 반드시 초기화가 이루어져야 한다.
public:
	RefClass(int& _ref) : ref(_ref) {}
	void showValue() {
		std::cout << "ref : " << ref << std::endl;
	}
};

class Position {
private:
	int m_x;
	int m_y;
public:
	Position(int x, int y) {
		// ObjClass의 pos(x, y)는 초기화 리스트를 통해 Position(int x, int y) 생성자를 호출
		// Position 생성자가 완료되면, ObjClass 생성자 내부 코드 실행
		std::cout << "Position 생성자!!" << std::endl;
		m_x = x, m_y = y;
	}
	void getData() {
		std::cout << "m_x : " << m_x << ", m_y : " << m_y << std::endl;
	}
};

class ObjClass {
private:
	Position pos;				// 객체 멤버변수
public:
	ObjClass(int x, int y) : pos(x, y) { std::cout << "ObjClass constructor!!" << std::endl; }
	// ObjClass의 생성자가 실행될 때, 멤버 변수인 Position pos;의 생성자가 먼저 실행
	// ObjClass의 멤버 변수 Position pos; 가 초기화 리스트에서(3, 6) 값을 받음
	void showValue() {
		pos.getData();
	}
};

int main()
{
	ConstClass obj(10, 20);
	obj.showValue();

	int r = 50;
	RefClass obj2(r);
	obj2.showValue();

	std::cout << "=====================================" << std::endl;

	ObjClass o(3, 6);
	o.showValue();	// 실행 시 ObjClass의 showValue를 호출한 다음, Position 클래스의 getData() 호출.
	return 0;
}