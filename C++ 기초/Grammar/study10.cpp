#include <iostream>
#include <string>

// 구조체 : 서로 다른 타입(형식)의 변수들을 하나로 묶어주는 사용자 정의 데이터 타입
struct Player
{
	std::string name;
	std::string position;
	float height;
	float weight;
};

int main()
{
	//Player A;
	Player A = { "Hwang", "Forward", 171, 77 }; // 구조체 초기화

	std::cout << "이름 : " << A.name << std::endl;
	std::cout << "포지션 : " << A.position<< std::endl;
	std::cout << "몸무게 : " << A.height << std::endl;
	std::cout << "키 : " << A.weight << std::endl << std::endl;

	Player B[2] = { {"Son", "Forward", 183, 77}, {"Lee", "Midfielder", 175, 70} }; // 구조체 배열 초기화

	std::cout << "이름 : " << B[0].position << std::endl;

	//A.name = "Hwang";
	//A.position = "Forward";
	//A.height = 171;
	//A.weight = 77;

	return 0;
}