#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

// 공용체 (union)
// "여러 데이터 멤버를 하나의 메모리 공간을 공유해서 사용하는" 특수한 사용자 정의 타입
// 모든 멤버가 "같은 메모리 공간을 공유"하므로, 메모리 사용이 효율적
// 공용체에서는 마지막으로 저장한 값만 의미를 가짐!
// 여러 멤버를 독립적으로 사용할 수 없다
union Data {
    int i;
    float f;
    char str[20];
};

// 열거체 (enum)
// "관련 있는 여러 상수들을 하나의 타입으로 묶어서 정의"
// 열거자들의 산술 연산은 허용되지 않는다
// but, int형 변수에 대입하면, 열거자들의 값은 int형 정수로 계산되어 대입된다
enum Color { red, orange, yellow, green, blue, violet};

int main()
{
	// 공용체 (union)
    Data data;  // 공용체 변수 선언

    data.i = 10;
    std::cout << "data.i: " << data.i << std::endl;

    data.f = 220.5;
    std::cout << "data.f: " << data.f << std::endl;

    strcpy(data.str, "Hello");
    std::cout << "data.str: " << data.str << std::endl;

	// 열거체 (enum)
	//Color a = red;  // 열거체 변수 선언
    
	//Color a = (Color)(red + yellow);    // 명시적 형변환(캐스팅)을 해야 int 타입으로 변환됨

    Color a = static_cast<Color>(red + yellow); // C++ 스타일 형 변환
    std::cout << a << std::endl;

    //enum 항목은 내부적으로 int처럼 연산은 되지만, 결과를 다시 enum 타입으로 넣을 때는 명시적 변환이 필요하다.

    int b = blue;
    b = blue + 3;
    std::cout << b << std::endl;

    return 0;
}