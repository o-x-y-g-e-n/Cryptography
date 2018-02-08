										// ^^ Additive Cypher ^^ //

													// too weak to fight
													// total keys possible --> 25

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
// global defination of key
#define KEY 3
string encrypt(string str)
{

	for(int i=0 ;i<str.size() ; i++)
	{
		int x = str[i];
		x = x - 97;
		x = ((x + KEY)%26);
		x = x+ 97;
		char c = x;
		str[i] = c;
	}
	return str;
}
string decrypt(string str)
{
	for(int i=0 ;i<str.size() ; i++)
	{
		int x = (int)str[i];
		x = x - 97;
		x = (x - KEY);
		while(x < 0)
			x = (x + 26);
		x = x%26;
		x = x + 97;
		str[i] = (char)x;
	}
	return str;
}
int main()
{
	cout << "enter the string" << endl;
	string str,en_str,de_str;
	cin >> str;
	en_str = encrypt(str);
	cout << "Encrypted string is " << en_str << endl;
	de_str = decrypt(en_str);
	cout << "Decrypted string is " << de_str << endl;
	return 0;
}
