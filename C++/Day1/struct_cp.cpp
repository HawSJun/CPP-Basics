/*
	C++ 구조체
*/

#include <iostream>

typedef struct human{
	char name[20];
	int age;
	char job[10];

	void showHuman()
	{
		printf("name : %s, age : %d, job : %s", name, age, job);
	}
}Human;


int main()
{
	Human h = { "김철수", 30, "백수" };

	//showHuman(h);
	h.showHuman();

	return 0;
}