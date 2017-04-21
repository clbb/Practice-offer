#include<iostream>
using namespace std;

//饿汉单例模式 类似于全局变量的构造，在进入main之前就已经占有空间
class Singleton
{
public:
	static Singleton*  getSingleton()
	{
		return instance;
	}
private:
	static Singleton* instance;
	Singleton()
	{
		cout<<"Get a Singleton"<<endl;
	}
};
Singleton* Singleton::instance = new Singleton();
/*
//懒汉单例模式 用的时候才构造
class Singleton
{
public:
	static Singleton*  getSingleton()
	{
	//	if(instance == NULL)
	//	{
	//		lock(mutex)	
	//		{
				if(instance == NULL)
				{
					instance = new Singleton();
					cout<<"once"<<endl;
				}
				else
					cout<<"is not once"<<endl;
	//		}
	//	}
		return instance;
	}
private:
	static Singleton* instance;
	Singleton()
	{
		cout<<"Get a Singleton"<<endl;
	}
};
Singleton* Singleton::instance = NULL;
*/

class A
{
public:
	A(){}
	A(int data)
		:_data(data)
	{}
	void get_b()
	{
		cout<<b<<endl;
	}
	static void get_B()
	{
		cout<<b<<endl;
	}
	private:
	int _data;
	static int b;
};
int A::b = 10;

int main()
{
//	Singleton tmp;
//	Singleton* ptr = new Singleton();	
//
//	cout<<"main begin!!"<<endl;
//	Singleton* tmp = Singleton::getSingleton();
//	Singleton* tmp1 = Singleton::getSingleton();
//	cout<<(tmp == tmp1)<<endl;
	
	A a;
	a.get_b();
	a.get_B();
	A::get_B();	

	return 0;
}
