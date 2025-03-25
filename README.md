# CPP-Basics
C++ 기초 개념 정리

### C++ 지역변수
- C++의 지역변수 선언은 함수 내 어디든 삽입이 가능하다.

---

### 함수 오버로딩 (Funciton Overloading)

- C언어에서는 동일한 이름의 함수가 정의되는 것을 허용하지 않는다.
- `다중 정의` : 같은 이름을 가진 함수가 여러 개 존재할 수 있음.
- C와 C++ 함수 오버로딩 차이
    - C++ 에서는 `함수의 이름`, `매개변수의 선언` 두 가지를 이용해서 호출 대상을 찾음
    - C 에서는 `함수의 이름`만 이용해서 호출 대상을 찾음

- 함수 호출 시 전달되는 인자를 통해서 호출하고자 하는 함수의 구분이 가능하기 때문에 **매개변수의 선언형태**가 다르면, 동일한 이름의 함수 정의를 혀용

    ```c++
    int MyFunc(int num)
    {
        num++;
        return num;
    }

    int MyFunc(int a, int b)
    {
        return a + b;
    }

    int main()
    {
        MyFunc(20);         // MyFunc(int num) 함수의 호출
        MyFunc(30, 40);     // MyFunc(int a, int b) 함수의 호출
        return 0;
    }

    void func(int)와 int func(int) 같은 경우, 반환 타입만 다르므로 오버로딩이 불가능!
    ```

---

### 매개변수의 디폴트 값 (Default Value)

- `기본적으로 설정되어 있는 값`
- default 값은 `함수의 선언` 부분에 위치해야 함!

    ```c++
    int MyFunc(int num = 7)     // 함수 호출 시 인자를 전달하지 않으면 7
    {
        return num + 1;
    }

    int main()
    {
        MyFunc();               // 7
        MyFunc(7);              // MyFunc()와 같음
    }
    ```

-  함수에 전달되는 인자가 왼쪽에서부터 오른쪽으로 채워지기 때문에 디폴트값을 오른쪽에서 부터 채움
    
    ```c++
    int Func(int num1, int nu2 = 5, int num3 = 7)

    Func(10);           // Func(10, 5, 7);
    Func(10, 20);       // Func(10, 20, 7); 

    // 디폴트 값이 오른쪽에서 부터 채워졌기 때문에 함수 호출 가능!!

    int Func(int num1 = 3, int nu2 = 5, int num3)

    // 왼쪽부터 디폴트 값이 채워졌기 때문에 디폴트 값을 지정할 수 없다!
    ```

---

### 인라인(inline) 함수

- 인라인 함수는 컴파일러에게 해당 함수를 함수 호출 대신, 그 자리에 코드 삽입하라고 요청하는 것.
- 매크로 함수는 `전처리기`가 처리하지만, 인라인 함수는 `컴파일 단계`에서 처리됨

- **일반 함수 호출**

    ```c++
    int Add(int a, int b) {
        return a + b;
    }

    int main() {
        int result = Add(3, 4);
    }

    main:
        push 4            ; b 인자
        push 3            ; a 인자
        call Add          ; Add 함수로 점프
        mov result, eax   ; 결과 저장

    main() ──▶ Add() ──▶ return result
    ```

 - **인라인 함수 호출**

    ```c++
     inline int Add(int a, int b) {
        return a + b;
    }

    int main() {
        int result = Add(3, 4);
    }

    main:
        mov eax, 3
        add eax, 4
        mov result, eax

    main() ──▶ (함수 코드가 그 자리에 복사됨)
    // 즉, 함수 호출 없이 바로 계산식이 삽입됨 ← 이게 바로 인라인 함수의 핵심!
    ```

- **클래스 외부에서 인라인 함수 정의**

    ```c++
    #include <iostream>

    class MyClass {
    public:
        inline int a(int x);  // 선언만 먼저, inline 명시
    };

    // 클래스 밖에서 정의할 때도 inline 명시
    inline int MyClass::a(int x) {
        return x * 2;
    }

    int main() {
        MyClass obj;
        std::cout << obj.a(5) << std::endl;  // 출력: 10
        return 0;
    }
    ```

- 보통 인라인 함수는 `헤더 파일(.h)` 안에 작성
    - 컴파일 시점에 코드가 복사되어야 하기 때문에 함수의 정의가 호출 전에 보여야 함

### 이름공간(namespace)

- `::` : 범위 지정 연산자

- 동일한 이름공간에 정의된 함수를 호출할 때에는 이름공간을 명시할 필요가 없다.
- 이름공간의 중첩 : 다른 이름공간 안에 삽입될 수 있다.

- using을 이용한 이름공간의 명시
    - using namespace std; : `이름공간 std에 선언된 모든 것에 대해 이름공간 지정의 생략`을 명령

### const

-  `const int* ptr` : 읽기 전용을 가리키는 포인터, 값은 못 바꿈, 포인터는 이동 가능
    
    ```c++
    const int* ptr = &a;
    *ptr = 10;   // 값 변경 불가!
    ptr = &b;    // 다른 주소로 변경 가능
    ```

-  `int* const ptr` : 주소가 고정된 포인터, 값은 바꿀수 있고, 포인터는 못 움직임

    ```c++
    int* const ptr = &a;
    *ptr = 10;   // 값 변경 가능!
    ptr = &b;    // 포인터 자체 변경 불가!
    ```

- `const int* const ptr` : 읽기 전용 값을 가리키는 고정 포인터, 값도 못 바꾸고, 포인터도 못 움직임

    ```c++
    const int* const ptr = &a;
    *ptr = 10;   // 값 변경 불가!
    ptr = &b;    // 주소 변경 불가!
    ```

### 참조자 (Reference)

- 자신이 참조하는 변수를 대신할 수 있는 또 하나의 이름. 즉, 참조자는 별칭

    ```c++
    int* ptr = &num1;       // 변수 num1의 주소 값을 반환해서 포인터 ptr에 저장해라
    int& num2 = num1;       // 변수 num1에 대한 참조자 num2를 선언해라
    ```

- 참조자는 선언과 동시에 초기화해야 한다.

    ```c++
    int a = 10;
    int& ref = a;   // ref는 a의 별명으로 선언됨

    int& ref;     // 컴파일 에러! 참조는 초기화 없이 선언 불가
    ref = a;      // "ref가 a를 참조하게 한다"가 아니라, "ref가 참조하는 대상에 a의 값을 대입"한다는 의미임
    ```

- `상수 레퍼런스로 선언하면 리터럴도 참조 가능하다.`
 
    ```c++
    int& ref = 10;   // 컴파일 에러 (rvalue는 일반 참조 불가)


    const int& ref = 10;        // 임시객체를 저장할 수 있는 공간이 생성

    // 10을 참조하기 위해 컴파일러가 임시 메모리 공간에 10을 복사
    // 그 공간의 주소를 ref가 참조함

    // 일반적인 레퍼런스는 반드시 lvalue(메모리에 존재하는 변수) 를 참조
    ```

- **const 참조자**
   
    ```c++
    void HappyFunc(int& ref)

    int num = 24;
    HappyFunc(num);

    // 함수의 정의와 호출을 보아도 값의 변경 유무를 알 수 없다.
    // 이를 알려면 함수의 몸체 부분을 확인해야 한다.

    void HappyFunc(const int& ref)

    // 함수 내에서 참조자 ref를 이용한 값의 변경은 허용하지 않겠다! 

    - const 참조자 장점
        1. 함수의 원형 선언만 봐도 값의 변경이 일어나지 않음을 판단할 수 있다.
        2. 실수로 인한 값의 변경이 일어나지 않는다.
    ```

- 반환형이 참조형(Reference Type)인 경우

    ```c++
    int& RefFunc(int& ref) {    // int& 를 반환하니까, 참조(주소)를 그대로 돌려줌
        return ref;
    }

    // 함수에서 반환형이 int&면, "참조 자체를 반환" 하겠다는 뜻, 원본 변수에 연결된 상태로 돌아옴.

    int ValFunc(int& ref) {     // nt 를 반환하니까, ref의 값만 복사해서 돌려줌
        return ref;
    }

    // 반환형이 int면, "값만 복사해서 반환"
    ```

- 매개변수는 함수가 호출될 때 선언이 되는 변수이므로, 함수 호출의 과정에서 선언과 동시에 전달되는 대상으로 초기화된다. (인자로 전달되는 값으로 초기화)

- 참조자를 통해 해당 메모리 공간을 참조하게 되는데 함수를 빠져 나가면 함수 안에서 선언된 참조자는 소멸되지만, 참조자가 참조하는 변수는 사라지지 않는다.

### new & delete

- 메모리 동적 할당 및 해제 방법

    ```c++
    int* ptr1 = new int;        // int형 변수의 할당

    int* arr1 = new int[3]      // 길이가 3인 int형 배열의 할당

    delete ptr1;                // int형 변수의 소멸

    delete []arr1               // int형 배열의 소멸
    ```
- new 연산자로 할당된 메모리 공간은 **반드시 delete 함수 호출을 통해 소멸**해야한다!

- **new & delete 와 malloc & free 의 차이점**

    ```c++
    #include <iostream>   // 입출력 스트림 라이브러리 포함
    #include <stdlib.h>   // malloc, free 사용을 위한 표준 라이브러리 포함

    class Simple        // Simple 클래스 정의
    {
    public:
        Simple()    // 생성자
        {
            std::cout << "I'm simple constructor!" << std::endl;
        }
    };

    int main(void)
    {
        // case 1: new 연산자를 이용한 객체 생성
        cout << "case 1: ";
        Simple * sp1 = new Simple;   // new는 객체를 생성하고 생성자를 자동 호출함

        // case 2: malloc 함수 사용
        cout << "case 2: ";
        Simple * sp2 = (Simple*)malloc(sizeof(Simple) * 1); 
        // malloc은 단순히 메모리만 할당하고, 생성자를 호출하지 않음

        cout << endl << "end of main" << endl;

        // 메모리 해제
        delete sp1;    // delete는 메모리 해제 전에 소멸자 호출 (생성자도 호출되었기 때문)
        free(sp2);     // free는 단순히 메모리를 해제하지만, 소멸자 호출 X

        return 0;
    }
    ```
    - malloc & free 는 생성자 및 소멸자가 호출되지 않음
    - new는 객체 생성 시 생성자를 호출하며, delete는 소멸자를 호출함.
    - 반면, malloc은 단순한 메모리 블록을 할당할 뿐, 객체의 생성자 호출을 하지 않음.



### Class

- private
    - 멤버변수, 외부에서 접근 불가 
    - 직접 접근할 수 없고, public 멤버함수를 통해서 접근

- public
    - 멤버함수, 외부에서 접근 가능
    - 실제 함수를 사용하기 위해서는 멤버함수에 대한 정의가 필요
    - 멤버함수 정의 방법
	    - 클래스 안에서 정의
	    - 클래스 밖에서 정의