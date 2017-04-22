#include<iostream>
using namespace std;

//o(n^2) 有空间的开销 有乱码
void replaceStr(char str[],int length)
{
	if(str == NULL || length <= 0) 
		return;
	
	char tmp[length];
	char ins[4] = "%20";
	int j = 0;
	int index = 0;

	for(int i = 0; i<strlen(str);)
	{
		if(str[i] == ' ')
		{
			for(index = 0; index<3; ++index)
			{
				tmp[j] = ins[index];
				j++;
			}
		}
		tmp[j++] = str[i++];
	//	i++;
	//	j++;
	}

	cout<<tmp<<endl;
}
//O(n^2) 在一个字符串里 有覆盖的问题 大量移动元素
void replaceStr1(char* str,int length)
{
	if(str == NULL || length <= 0) 
		return;
	char*  tmp = str;	
	while(*tmp++ != '\0')
	{
		if(*tmp == ' ')
		{
			char* dest = tmp;
			char* src = tmp+4;
			int count = 2;
			while(count--)
				*dest-- = *src--;
		}
	}

	cout<<str<<endl;
}
//在栈区预先分配好空间 访问字符串统一用一种方式访问 要么下标要么指针
void replaceStrOP(char* str,int len)
{
	//len是预留空间长度
	if(str == NULL || len <= 0)
		return;

	//统计空格个数
	int count = 0;
	int length = 0;
	int i = 0;
	while(str[i] != '\0')
	{
		++length;
		if(str[i] == ' ')
			count++;
		++i;
	}

	int newlength = length + count*2;//原来又一个空格
	if(newlength > len)
		return;
	//从后向前拷贝
	int indexlength = length;
	int indexnewlength = newlength;
	while(indexlength >= 0 && indexnewlength > indexlength)
	{
		if(str[indexlength] == ' ')
		{
			str[indexnewlength--] = '0';
			str[indexnewlength--] = '2';
			str[indexnewlength--] = '%';
		}
		else
			str[indexnewlength--] = str[indexlength]; 
		indexlength--;
	}

//	cout<<str<<endl;
}


int main()
{
	char str[20] = "we are happy";
//	char y[] = "sssss"; 
//	char* tmp = new char[strlen(str)*2];
//	for(int i = 0; i<strlen(tmp); ++i)
//	{
//		tmp[i] = 'r'; 
//	}		
//	cout<<tmp<<endl;
//	cout<<str<<endl;
//	cout<<y<<endl;
//	cout<<y<<endl;
//	replaceStrOP(str,20);
//	cout<<str<<endl;
//	replaceStr(str,20);
	replaceStr1(str,20);
	return 0;
}
