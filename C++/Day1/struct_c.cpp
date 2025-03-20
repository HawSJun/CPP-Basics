/*
	C 구조체
*/

#include <iostream>

typedef struct {
	char name[20];
	int age;
	char job[10];
}Human;

void showHuman(Human ah)
{
	printf("name : %s, age : %d, job : %s", ah.name, ah.age, ah.job);
}
int main()
{
	Human h = { "김철수", 30, "백수" };

	showHuman(h);
	return 0;
}