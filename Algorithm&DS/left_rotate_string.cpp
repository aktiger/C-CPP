/*
author:justinzhang
email:uestczhangchao@gmail.com
time:2012-8-19 9:44:46
des.: to left rotate a string,e.g, abcedef->cedefab
*/

#include <iostream>
#include <string>
using namespace std;

void swap_str(string &str, int i, int j)
{
	char c = str[i];
	str[i] = str[j];
	str[j] = c;
}

/*
	This routine is used to reverse a string,e.g,abcd->dcba
*/
void reverse_str(string &str,int start, int end)
{
	for(;start<end;start++,end--)
	{
		swap_str(str, start, end);
	}
}

/*
	This routine is used to left_shift a string by offset  bits,e.g.
	left shift string abcdefg by 2 bits, we get results:cdefgab;
	we first devide the string by two parts,AB, first we reverse A, then we
	reverse B, the we get string A'B',finally, we reverse A'B',That's the result we want;
*/
string &left_rotate_string(string &str, int offset)
{
	int len = str.length();
	cout << len << endl;
	reverse_str(str, 0, offset-1);
	reverse_str(str, offset, len-1);
	reverse_str(str, 0, len-1);
	return str;
}

/*
	This routine is used to right_shift a string by offset  bits,e.g.
	right shift string abcdefg by 2 bits, we get results:fgabcde
*/
string &right_rotate_string(string &str, int offset)
{
	int len = str.length();
	reverse_str(str, 0, len-offset-1);
	reverse_str(str, len-offset, len-1);
	reverse_str(str, 0, len-1);
	return str;
}


int main()
{
	string str;
	cin >> str;
	str = left_rotate_string(str,2);
	cout << str << endl;
	str = right_rotate_string(str,2);
	cout << str << endl;
	return 0;
}




