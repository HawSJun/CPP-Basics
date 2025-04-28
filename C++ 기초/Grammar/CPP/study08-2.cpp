#include <iostream>
using namespace std;

int main() {
    // 문제 발생!!
    // 나이 입력하고 엔터(\n) 쳐서 엔터 문자가 cin 스트림에 남아 있음.
    // cin.get(name, 20); 호출했는데 \n을 바로 만나서 읽을 게 없음.

    int age;
    char name[20];

    cout << "나이를 입력하세요: ";
    cin >> age;              // 숫자 입력 (ex: 20)
    
    cout << "이름을 입력하세요: ";
    cin.get(name, 20);       // 이름 입력

    cout << "나이: " << age << endl;
    cout << "이름: " << name << endl;

    return 0;
}

// cin.ignore() = 입력 무시(엔터 포함해서 여러 글자 무시 가능)
// cin.get() = 입력 하나 읽어오기(엔터 제거용으로 1글자 읽는 것도 가능

// ex) cin.ignore(1000, '\n');  ->  버퍼에서 최대 1000글자까지 읽고, \n 만나면 멈춤 
