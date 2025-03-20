/*
	StaticTest라는 클래스를 만드는데 멤버변수로는 이름, 전화번호, 주소, 회원번호(cnt)를 가지고
	3개 입력을 받는 생성자를 작성한다. 회원번호는 자동으로 증가시킬 것이기 때문에
	출력 담당의 showmember() 메서드를 구현하시오.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

class StaticTest {
private:
    static int cnt;
    int id;
    char name[20];
    char phone[20];
    char addr[30];

public:
    StaticTest(const char* _name, const char* _phone, const char* _addr) {
        strcpy(name, _name);
        strcpy(phone, _phone);
        strcpy(addr, _addr);

        id = ++cnt;
    }
    void showmember() {
        std::cout << "회원번호 : " << id << std::endl;
        std::cout << "이름 : " << name << ", 전화번호 : " << phone << ", 주소 : " << addr << std::endl;
        std::cout << "------------------------------\n";
    }
};

int StaticTest::cnt = 0;

int main() {
    StaticTest m1("홍길동", "010-1111-2222", "부산");
    m1.showmember();

    StaticTest m2("김영희", "010-2222-2222", "서울");
    m2.showmember();

    StaticTest m3("김철수", "010-3333-3333", "대구");
    m3.showmember();

    return 0;
}
