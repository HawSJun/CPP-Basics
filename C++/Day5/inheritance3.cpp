/*
	상속관계에서 이니셜라이즈 사용하기
*/
#include <iostream>

class Car {
private:
	int gasolineGauge;
public:
	Car(int ag) : gasolineGauge(ag){}				// 콜론초기화
	int getGasGauge() { return gasolineGauge; }
};
class HybridCar : public Car {
private:
	int electricGauge;
public:
	HybridCar(int ag, int ae) : Car(ag), electricGauge(ae){}
	int getElecGauge() { return electricGauge; }
};
class HybridWaterCar : public HybridCar {
	int waterGauge;
public:
	HybridWaterCar(int ag, int ae, int aw) : HybridCar(ag, ae), waterGauge(aw) {}
	void showGauge() {
		std::cout << "잔여 가솔린 : " << getGasGauge() << std::endl;
		std::cout << "잔여 전기량 : " << getElecGauge() << std::endl;
		std::cout << "잔여 워터량 : " << waterGauge << std::endl;
	}
};
int main()
{
	HybridWaterCar hwc(10, 20, 30);
	hwc.showGauge();

	return 0;
}