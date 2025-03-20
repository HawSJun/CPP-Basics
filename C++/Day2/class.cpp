/*
	class
	1. 접근제어 지시자(private, public, protected)
	2. 멤버변수 - 속성(보통 private으로 선언하고, public 메서드를 통해 접근)
	3. 멤버함수(메서드) - 기능
*/

//#include <iostream>
//
//using namespace std;
//
//class A {
//public:
//	int m_num;			// 멤버변수(속성)
//
//	void set(int num) {
//		m_num = num;
//	}
//	void print() {		// 멤버함수(기능), 메서드
//		cout << "나는 A 클래스의 인스턴스입니다. "<< "num : " << m_num << endl;
//	}
//};
//int main()
//{
//	A obj;		// ex) int n;		// obj는 A 클래스의 인스턴스
//									// A 클래스의 객체는 obj
//	obj.print();
//	obj.set(10);
//	obj.print();
//	return 0;
//}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class BankAccount {
private:
    string accountHolder;
    int accountNumber;
    double balance;

public:
    BankAccount(int number, double initialBalance, string holder)
        : accountNumber(number), balance(initialBalance), accountHolder(holder) {
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "\n입금 완료: " << amount << "원" << endl;
        }
        else {
            cout << "\n올바른 금액을 입력하세요." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "\n출금 완료: " << amount << "원" << endl;
        }
        else {
            cout << "\n잔액 부족 또는 잘못된 금액." << endl;
        }
    }

    void checkBalance() const {
        cout << "\n계좌번호: " << accountNumber << endl;
        cout << "예금주: " << accountHolder << endl;
        cout << "잔액: " << balance << "원" << endl;
    }

    int getAccountNumber() const {
        return accountNumber;
    }
};

int main() {
    vector<BankAccount> accounts;
    int choice, accNum;
    double amount;
    string name;

    while (true) {
        cout << "\n=== 은행 시스템 ===" << endl;
        cout << "1. 입금" << endl;
        cout << "2. 출금" << endl;
        cout << "3. 잔액 조회" << endl;
        cout << "4. 종료" << endl;
        cout << "선택: ";
        cin >> choice;

        if (choice == 4) {
            cout << "프로그램 종료." << endl;
            break;
        }

        if (choice == 1) {
            cout << "\n계좌 번호 입력: ";
            cin >> accNum;
            cout << "예금주 이름 입력: ";
            cin >> name;
            cout << "입금할 금액 입력: ";
            cin >> amount;
            accounts.emplace_back(accNum, amount, name);
            cout << "입금이 완료되었으며, 계좌가 저장되었습니다." << endl;
        }
        else {
            cout << "\n계좌 번호 입력: ";
            cin >> accNum;

            auto it = find_if(accounts.begin(), accounts.end(), [accNum](const BankAccount& acc) {
                return acc.getAccountNumber() == accNum;
                });

            if (it == accounts.end()) {
                cout << "\n계좌를 찾을 수 없습니다." << endl;
                continue;
            }

            if (choice == 2) {
                cout << "출금할 금액 입력: ";
                cin >> amount;
                it->withdraw(amount);
            }
            else if (choice == 3) {
                it->checkBalance();
            }
            else {
                cout << "잘못된 선택입니다." << endl;
            }
        }
    }
    return 0;
}
