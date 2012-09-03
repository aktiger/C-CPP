/*
Author:	Justinzhang
Email:	uestczhangchao@gmail.com
Time:	2012-9-3 12:56:55
Desc:	for the purpose of reviewing copy constructor and assian operator, const etc.
		still remember the benefit from DR. Dai, who teach me C++ when i was still a freshman.
		Best regard to her~
*/

#include <iostream>
#include <cassert>
using namespace std;

class String
{
	public:
		String(const char *str =NULL);
		String(const String &other);
		String & operator =(const String &other);
		~String(void);
		friend ostream & operator <<(ostream &scout, const String &str);
	private:
		char *m_data;
};

String::String(const char *str)
{
	if(str == NULL)
	{
		m_data = new char[1];
		m_data[0] = '\0';
	}
	else
	{
		m_data = new char[strlen(str)+1];
		strcpy(m_data, str);
	}
}

String::~String(void)
{
	delete [] m_data;
}

String::String(const String &other)
{
	m_data = new char[strlen(other.m_data)+1];
	assert(m_data);
	strcpy(m_data, other.m_data);
}

String & String::operator=(const String &other)
{
	if(this == &other)
		return *this;
	delete [] m_data;
	m_data = new char[strlen(other.m_data)+1];
	strcpy(m_data, other.m_data);
	return *this;
}
 ostream & operator << (ostream &scout, const String & str)
{
	scout << str.m_data << endl;
	return scout;
}


int main()
{
	String s1("hello");
	cout<< s1 << endl;
	String s2(s1);
	cout << s2 << endl;
	String s3 = s1;
	cout << s3 << endl;
	return 0;
}

