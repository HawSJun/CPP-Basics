#include <iostream>
#include <string>   // <cstring> 대신 <string> 사용

int main()
{
    // 배열을 다른 배열에 통째로 대입할 수 없는데 string은 가능!!
    std::string str1;
    std::string str2 = "icecream";
    str1 = str2;
    std::cout << str1 << std::endl;
    std::cout << str1[0] << std::endl;

    std::string name1;
    std::string name2 = "C++programing";

    std::cout << "안녕하세요! 저는 " << name2;
    std::cout << "입니다! 성함이 어떻게 되시나요?\n";
    std::getline(std::cin, name1);   // std::string 버전 getline 사용

    std::cout << "음, " << name1 << "씨, 당신의 이름은 ";
    std::cout << name1.length() << " 자입니다만\n";  // strlen 대신 length()

    std::cout << "문자열 객체에 저장되었습니다.\n";   // 배열 크기 의미가 다름

    if (!name1.empty()) {
        std::cout << "이름이 " << name1[0] << "자로 시작하는군요\n";
    }

    name2 = name2.substr(0, 3);   // 처음 세 문자만 남기기 (substring 사용)

    std::cout << "제 이름의 처음 세 문자는 다음과 같습니다 : ";
    std::cout << name2 << std::endl;

    return 0;
}

// strlen 대신 length() 사용하는 이유
// 1. C++의 문자열 클래스이며, length()는 이 클래스의 멤버 함수
// 2. 동적 메모리를 사용하여 문자열을 저장하므로, 길이를 계산하는 데 더 효율적
// 3.다양한 문자열 조작 기능을 제공하므로, C 스타일 문자열보다 더 안전하고 편리
// 4. null 문자 ('\0')를 사용하지 않으므로, 문자열의 끝을 자동으로 관리

// strlen
// 1. C 스타일 문자열을 사용하며, null 문자 ('\0')를 기준으로 문자열의 길이를 계산
// 2. 고정된 크기의 배열에 저장되므로, 메모리 관리가 더 복잡
// 3. strlen은 메모리를 하나하나 읽다가 \0 만나면 멈추는 방식이라,
// 널문자('\0')가 없다면 메모리를 막 읽다가 세그멘테이션 오류(segfault) 나기도 함