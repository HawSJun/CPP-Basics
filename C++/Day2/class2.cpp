#include <iostream>

using namespace std;

class AClass {
private:
	int n1;
	int n2;
public:
	AClass(){}			// 디폴트 생성자
	void setData(int n_n1, int n_n2){
		n1 = n_n1;
		n2 = n_n2;
	}
	void getData(){
		cout << "나는 AClas의 인스턴스 입니다. " << "n_n1 : " << n1 << endl;
		cout << "나는 AClas의 인스턴스 입니다. " << "n_n2 : " << n2 << endl;
	}
};

int main()
{
	AClass obj;		// 디폴트 생성자가 호출 됨

	obj.setData(10, 20);
	obj.getData();
	

	return 0;
}