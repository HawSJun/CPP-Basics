/*
	default 매개변수를 여러개 작성할 때는 맨 오른쪽부터 순서대로 작성한다.
*/
#include <iostream>

using namespace std;

int coordinates(int x, int y = 0, int z = 0);			// default 값은 선언(원형)에만 작성한다.

int main()
{
	cout << "(10, 20, 30) : " << coordinates(10, 20, 30) << endl;
	cout << "(10, 20, def) : " << coordinates(10, 20) << endl;
	cout << "(10, def, def) : " << coordinates(10) << endl;

	return 0;
}

int coordinates(int x, int y, int z)
{
	int res = 0;
	res = pow(x, 2) + pow(y, 2) + pow(z, 2);		// 제곱
	return sqrt(res);						// 제곱근
}

// ex) int coordinates(int x= 0, int y = 0, int z);
// 이렇게 작성하면 안됨! 무조건 오른쪽부터
// 함수에 전달되는 인자가 왼쪽에서부터 오른쪽으로 채워지기때문에 
// 디폴트값을 오른쪽에서 부터 채움