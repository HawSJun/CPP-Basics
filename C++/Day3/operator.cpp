/*
	연산자 오버로딩(다중정의)
*/
#include <iostream>

class Point {
public:
	int x, y;
	Point(int ax = 0, int ay = 0) :x{ ax }, y(ay) {
		std::cout << "constructor call!!!" << std::endl;
	}
	Point add(const Point& other) {
		std::cout << "add call!!!" << std::endl;
		int newX = x + other.x;
		int newY = y + other.y;
		Point result(newX, newY);
		return result;
		//return Point(x + other.x, y + other.y);
	}
	void showPoint() {
		std::cout << "x : " << x << ", y : " << y << std::endl;
	}
};

int main()
{
	Point obj(10, 20);
	obj.showPoint();
	Point obj2(30, 40);
	obj2.showPoint();
	//Point obj3;
	Point obj3 = obj.add(obj2);
	obj3.showPoint();
	return 0;
}