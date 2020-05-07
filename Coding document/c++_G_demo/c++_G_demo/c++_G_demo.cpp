#include <iostream>
using namespace std;

//指针和引用的区别：定义、参数传递、底层联系
void Pointers_And_References()
{
	int a = 10;
	int* p = &a;
	int& r = a;
	cout << "指针是一个变量，分配存储单元，引用是别名，与原变量共享存储单元" << endl;
	cout << "指针地址：" << &p << "  指针值：" << p<<" 指针指向的变量值：" << *p << endl;
	cout << "引用地址：" << &r << " 引用值：" << r << endl;
	cout << "变量地址：" << &a << " 变量值：" << a << endl;

}
//二级指针地址转换
void SecondaryPointer()
{
	int a = 10;
	int* p1 = &a;
	int** p2 = &p1;

	cout << "变量a的地址：" << &a << " 变量a的值：" << a << endl;
	cout << "变量p1的地址：" << &p1 << " 变量p1的值：" << p1 << endl;
	cout << "变量p2的顶层地址：" << &p2 << " 变量p2值：" << p2 << " 变量p2的二层地址：" << *p2 << " 指向的值：" << **p2 << endl;
}


int main()
{
	SecondaryPointer();
}
