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


//Const使用之道  const始终修饰离自己最近的一项
class A final //final防止类被继承
{
public:
	int data;
public:
	A(int data) :data(data) {}
	~A() {}
	virtual void f() final //final防止虚函数被重写，override显式声明重写虚函数
	{ 
		cout << "Base::f" << endl; 
	}
	//不允许函数返回值为可修改的左值
	const int& const_test1()
	{
		return data;
	}

	//不允许函数实参被修改
	void const_re(const int& re)
	{
		//对re修改将不能通过编译
		cout << re << endl;
	}

	//const 修饰成员函数， 根本上是修饰了this指针。const对象只能被const函数调用
	void constfun() const
	{
		cout << "this is a const function" << endl;
	}
};

//函数返回值是否为可修改的左值
void const_return()
{
	A A_test(2);
	//A_test.const_test1() = 100; 成员函数加上const修饰，不允许再被赋值
	cout << A_test.const_test1() << endl;
}

//const对象只能被const函数使用
void constFun()
{
	const A test(3);
	test.constfun();
}


//static使用之道

static int svar; //将全局变量使用static修饰，将可见范围限制在当前文件
static int test() {} //将函数使用static修饰，将可见范围限制在当前文件
int test2()
{
	int tvar; //将局部变量使用static修饰，生命周期提升至程序生命周期一致，只在当前函数可见
}


class B
{
public:
	static int testvar; //static修饰类成员变量，数据保存在全局数据区，为类实例共享的数据
	//static修饰成员函数，不含this指针，类使用，只能操作static成员变量
	static int testfun1()
	{
		static int test3; //静态局部变量的初始化是原子操作的（c++11）
	}
};

//类初始化与清理
class C
{
public:
	int c;
public:
	C()
	{
		cout << "无参构造函数" << endl;
	}
	C(int t)
	{
		cout << t << " 有参构造函数" << endl;
	}
	C(const C& t)
	{
		c = t.c;
		cout << "拷贝构造函数" << endl;
	}
	~C()
	{
		cout << "析构函数" << endl;
	}
};
//调用无参构造函数
void testC1()
{
	C c;
}
//调用有参构函数
void testC2()
{
	C c(10);
	C c1 = C(20);//匿名对象显式初始化
	C c2 = C(c1); //拷贝构造
	C c3 = 10;// C c3 = C(10),隐式转换（单个参数时）
	C c4 = c2;// C c4 = C(c2),隐式转换（单个参数时）
}
//构造拷贝函数被调用的时机
//使用一个已经创建完毕的对象来初始化一个新对象
//值传递的方式给函数参数传值
//以值方式返回局部对象
void testC3()
{
	C c1 = C(100);
	C c2 = C(c1);
	C c3 = c2;
}
void testC4(C c)
{
	cout << c.c << endl;
}
C testC4()
{
	C c1;
	return c1;
}

//深浅拷贝：如果属性有在堆区开辟的，一定要自己提供拷贝构造函数，防止浅拷贝带来的问题(重复释放同一地址)
class D
{
public:
	int d;
	int* p;
public:
	D(const D& d)
	{
		this->d = d.d;
		p = new int(*d.p);
	}
};

int main()
{
	constFun();
}
