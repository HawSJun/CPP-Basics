#include <iostream>
using namespace std;

// [1] C++ 참조 방식
void SwapByReference(int* (&ptr1), int* (&ptr2)) {
    int* temp = ptr1;
    ptr1 = ptr2;
    ptr2 = temp;
}

// [2] C 스타일 포인터 방식
void SwapByPointer(int** ptr1, int** ptr2) {
    int* temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main() {

    int a = 100;
    int b = 200;

    int* ptr1 = &a;
    int* ptr2 = &b;

    cout << "=== Before Swap ===" << endl;
    cout << "*ptr1: " << *ptr1 << ", *ptr2: " << *ptr2 << endl;

    // === 참조 방식 호출 ===
    SwapByReference(ptr1, ptr2);            // 참조로 포인터 자체가 바뀜

    cout << "\n=== After SwapByReference ===" << endl;
    cout << "*ptr1: " << *ptr1 << ", *ptr2: " << *ptr2 << endl;

    // 다시 원래대로 바꾸기
    SwapByPointer(&ptr1, &ptr2);            // 참조로 포인터 자체가 바뀜

    cout << "\n=== After SwapByPointer ===" << endl;
    cout << "*ptr1: " << *ptr1 << ", *ptr2: " << *ptr2 << endl;

    return 0;
}