/*
	객체를 더하는 함수(add)
	return을 객체로
*/

#include <iostream>

class Point {
public:
	int x, y;
	Point(int ax = 0, int ay = 0) : x(ax), y(ay) {
		std::cout << "constructor" << std::endl;
	}
	Point(const Point& other) {
	std::cout << "copy constructor" << std::endl;
		x = other.x;
		y = other.y;
	}
	Point add(const Point& other) {
		std::cout << "add()" << std::endl;
		return Point(x + other.x, y + other.y);
	}
	void showPoint() {
		std::cout << "x : " << x << ", y : " << y << std::endl;
	}
};



int main()
{
	Point p(10, 20);
	Point p2(30, 40);
	std::cout << "-------------------------" << std::endl;
	Point p3;
	p3 = p.add(p2);
	p3.showPoint();

	Point p4;
	p3 = p4;				// 대입연산자 호출
	p4.showPoint();

	return 0;
}