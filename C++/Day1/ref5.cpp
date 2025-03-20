/*
	출력인 경우 : 일반 변수
*/

#include <iostream>

using namespace std;


int func(int anum)		// 참조를 받지않으면 num의 값을 복사해서 사용하므로 실제 num 값은 증가하지 않음
// int func(int& anum)	 // 참조를 받으면 실제 num의 값이 1증가해서 리턴함!
{
	anum++;
	return anum;
}
int main()
{
	int num = 10;
	int res = func(num);
	//int& res = func(num);		// 함수가 끝나면 사라져 버려서 res는 anum의 별칭이라서 에러가 나옴

	//const int& res = func(num);		// 임시 객체로 바뀌고 임시로 공간이 할당되면서 거기에 참조되는 이름을 붙이면 됨 

	cout << "res : " << res << endl;

	return 0;
}