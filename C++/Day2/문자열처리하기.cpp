/*
	문자열 처리하기
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main()
{
	char str[20] = "홍길동";
	std::cout << str << std::endl;

	char str2[20];
	// str2 = "김영희";		// str2는 주소라서 문자열을 넣을 수 없다.

	strcpy(str2, "김영희");	// 그래서 문자열 복사를 사용해야한다.
	std::cout << str2 << std::endl;

	// char* str3 = nullptr;
	char str3[100];				// 입력 받을 시 해당 구문 사용

	std::cout << "이름입력 >> ";
	std::cin >> str3;
	std::cout << str3 << std::endl;

	const char* name;					 
	name = "김철수";
	std::cout << name << std::endl;
	// 문자열 리터럴("김철수")을 문자 포인터(const char*)에 저장하는 것이 가능
	// 문자열 리터럴은 메모리 영역(읽기 전용)에 저장됨.
	// const char* 포인터에 문자열의 첫 번째 문자의 주소가 저장됨
	// 즉, name은 "김철수" 문자열이 저장된 메모리 위치를 가리키는 포인터 역할을 함.

	return 0;
}