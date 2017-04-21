#include<iostream>
using namespace std;

class String
{
public:
	String(char* str = "")
		:_str(new char[strlen(str)+1])
	{
		strcpy(_str,str);
	}

	String(const String& str)
		:_str(new char[strlen(str._str)+1])
	{
		strcpy(_str,str._str);
	}

	String& operator=(String str)
	{
		String tmp(str._str);
		swap(_str,str._str);
		return *this;
	}
	~String()
	{
		if(_str != NULL)
			delete []_str;
	}
	void Getstr()
	{
		cout<<_str<<endl;
	}
	
private:
	char* _str;
};
int main()
{
	char* str = "aa";
	String s(str);
	String d;
	d = s;
	cout<<"d";
	d.Getstr();
	cout<<"s";
	s.Getstr();
	return 0;
}
