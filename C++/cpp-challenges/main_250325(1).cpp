#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Car {
private:
	static const int ID_LEN = 20;
	static const int MAX_SPD = 200;
	static const int FUEL_STEP = 2;
	static const int ACC_STEP = 10;
	static const int BRK_STEP = 10;

	char gamerID[ID_LEN];			// 소유자ID
	int fuelGauge;					// 연료량
	int curSpeed;					// 현재속도
public:
	Car(const char* _ID, int fuel, int cur) {
		strcpy(gamerID, _ID);
		fuelGauge = fuel;
		curSpeed = cur;
	}
	void ShowCarState();
	void Accel();
	void Break();
};

void Car::ShowCarState() {
	std::cout << "소유자ID: " << gamerID << std::endl;
	std::cout << "연료량: " << fuelGauge << "%" << std::endl;
	std::cout << "현재속도: " << curSpeed << "km/s" << std::endl << std::endl;
}
void Car::Accel(){
	if (fuelGauge <= 0)
		return;
	else
		fuelGauge -= FUEL_STEP;

	if (curSpeed + ACC_STEP >= MAX_SPD)
	{
		curSpeed = MAX_SPD;
		return;
	}
	curSpeed += ACC_STEP;
}
void Car::Break() {
	if (curSpeed < BRK_STEP)
	{
		curSpeed = 0;
		return;
	}
	curSpeed -= BRK_STEP;
}
int main()
{
	Car run99("run99", 100, 0);
	run99.Accel();
	run99.ShowCarState();
	run99.Break();
	run99.ShowCarState();

	Car sped77("sped77", 100, 0);
	sped77.Accel();
	sped77.Break();
	sped77.ShowCarState();

	return 0;
}