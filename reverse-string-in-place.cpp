// C++ program to reverse a string in-place

#include <iostream>

using namespace std;

void reverseString(string& str)
{
	int strlen = str.length();
 	
	for (int i=0; i < strlen/2; i++) {
		swap(str[i], str[strlen-i-1]);	//-1 to account for null-terminator at the end of the char array
	}
}
 

int main(int argc, char *argv[])
{
	string str = "abcdefgh";
	reverseString(str);
	cout << str;
	return 0;
}
