								//^^ multiplicative inverse^^//
								// total keys possible --> (MOD-1)
								// easily breakable

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
// global defination of key
#define KEY 2
#define MOD 26
int inverse(int n1,int mod)
{
	int in= 0,t=0,r=0;
	int r1 = mod;
	int r2 = n1;
	int t1 = 0;
	int t2 = 1;
	int q = 0;
	while(r2 > 0)
	{
		q = r1/r2;
		r = r1 - (q*r2);
		r1 = r2;
		r2 = r;
		t = t1 - (q*t2);
		t1 = t2;
		t2 = t;
	}
	if(r1 == 1)
	{
		in = t1; 
	}
	return in;
}
string encrypt(string str)
{
	for(int i=0 ; i<str.size() ; i++)
	{
		int x = str[i];
		x = x-97;
		x = x * KEY;
		x = x%MOD;
		x = x + 97;
		str[i] = x;
	}
	return str;
}
string decrypt(string str)
{
	for(int i=0 ;i<str.size() ; i++)
	{
		int x = str[i];
		x = x-97;
		int xx = inverse(KEY,MOD);
		if(xx == 0)
		{
			return "gcd nahi male harami"; 
		}
		while(xx < 0)
			xx = xx + 26;
		cout << xx <<endl;
		x = x * xx;
		x = x % MOD;
		x = x + 97;
		str[i] = x;
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