/*
	전역함수 오버로딩 : operator(p1, p2)
	1. public
*/

#include <iostream>

class Point {
public:
	int x, y;
	Point(int ax, int ay) : x(ax), y(ay){ }
	Point operator+(const Point& other) {				// 객체 + 객체
		return Point(x + other.x, y + other.y);
	}
	Point operator+(int n) {							// 객체 + 정수는 멤버함수로 가능한데
		return Point(x + n, y + n);
	}
	void showPoint() {
		std::cout << "x : " << x << ", y : " << y << std::endl;
	}
};
inline Point operator+(int n, const Point& other) {			// 정수 + 객체는 멤버함수로 불가능. 따라서, 전역함수로 정의해야함!!
	return Point(n + other.x, n + other.y);
}

int main()
{
	Point a(10, 20);
	Point b(30, 40);
	Point c = a + b;
	c.showPoint();
	Point d = a + 100;
	d.showPoint();
	Point e = 200 + b;
	e.showPoint();

	return 0;
}
