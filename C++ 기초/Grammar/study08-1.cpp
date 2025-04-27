#include <iostream>
#include <cstring>

int main()
{
	// 옛날 스타일 방식
	// getline 을 사용하기 전에 cin >> 같은 걸 쓰면 버그 날 수 있다.
	// 버퍼에 \n이 남아 있으면 getline이 \n을 읽어버리기 때문에
	// C++에서  get() 사용하지만, 주로 한 글자 입력, 버퍼 세밀 제어용
	// 여러 글자 한 줄을 입력할 땐 getline() 사용

	const int Size = 15;
	char name1[Size];
	char name2[Size] = "C++programing";

	std::cout << "안녕하세요! 저는 " << name2;
	std::cout << "입니다! 성함이 어떻게되시나요?\n";
	std::cin.getline(name1, Size);

	std::cout << "음, " << name1 << "씨, 당신의 이름은 ";
	std::cout << strlen(name1) << " 자입니다만\n";
	std::cout << sizeof(name1) << " 바이트 크기의 배열에 저장되었습니다.\n";
	std::cout << "이름이 " << name1[0] << "자로 시작하는군요\n";
	name2[3] = '\0';
	std::cout << "제 이름의 처음 세 문자는 다음과 같습니다 : ";
	std::cout << name2 << std::endl;

	return 0;
}

// cin -> 입력 버퍼에서 데이터를 가져온다.
// cout -> 출력 버퍼에 데이터를 모아뒀다가 출력한다.

/*
get()
-> 한 글자 읽기 / 일부 읽기
-> 개행 버퍼에 남김
-> 개행 만나면 멈춤, \n은 스트림에 남김
getline()
-> 한 줄 읽기 / 전체 읽기
-> 개행 버퍼에서 제거
-> 개행 만나면 멈춤, \n까지 소비
*/