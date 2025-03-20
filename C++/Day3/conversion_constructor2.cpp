#include <iostream>

class Time {
public:
	int hour;
	int min;
	int sec;
public:
	Time() { }					// 디폴트 생성자
	Time(int abssec) {			// 변환 생성자
		hour = abssec / 3600;
		min = (abssec / 60) % 60;
		sec = abssec % 60;
	}
	void printTime() {
		std::cout << "현재 시간은 " << hour << "시 " << min << "분 " << sec << "초 입니다." << std::endl;
	}
};
int main()
{
	Time now = 9999;
	// Time now(6611);
	now.printTime();

	return 0;
}