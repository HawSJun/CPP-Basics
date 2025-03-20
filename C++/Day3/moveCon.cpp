/*
	moveconstructor (이동 생성자)
*/

#include <iostream>

int main()
{
	int n = 10;
	int& rn = n;
	const int& ra = 10;			// 레퍼런스, 일반참조, l-value 참조

	int&& rrn = 10;				// r-value 참조

	return 0;
}