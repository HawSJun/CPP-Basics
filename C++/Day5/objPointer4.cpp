#include <iostream>

class MyClass {
public:
	void show() {
		std::cout << "Hello!!" << std::endl;
	}
};
int main()
{
	MyClass* ptr = nullptr;
	//std::cout << "ptr : " << *ptr << std::endl;
	if (ptr != nullptr) ptr->show();
	else std::cout << "ptr is null" << std::endl;

	ptr = new MyClass();
	ptr->show();

	return 0;
}