			// chinese theorm for n equations
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int gcd(int a , int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}
bool check_relatively_prime(vector<int>a)
{
	for(int i=0 ;i<a.size()-1 ; i++)
	{
		for(int j=i+1 ; j<a.size()-2	 ;j++)
		{
			int x = gcd(a[i],a[j]);
			if( x != 1)
			{
				return false;
			}
		}
		
	}
	return true;
}
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
int main()
{
	int n_eq,x_a,y_a,a_a;	
	cout << "enter the no of equations" << endl;
	cin >> n_eq;
	cout << "the equation is in the form x = a (mod y) " << endl;
	vector<int>a;
	vector<int>y;
	cout << "input is in form a --> y " << endl;
	for(int i=0 ; i<n_eq;  i++)
	{
		cin >> a_a;
		a.push_back(a_a);
		cin >> y_a;
		y.push_back(y_a);
	}
	int M = 1;
	for(int i=0 ;i<n_eq ;i++)
	{
		M = M*y[i];
	}
	if(!check_relatively_prime(y))
	{
		cout << "the modulis must be relatively prime" << endl;
		exit(0);
	}
	cout << "here1" << endl;
	vector<int>m;
	int temp;
	for(int i=0 ;i<n_eq ; i++)
	{
		temp = M/y[i];
		m.push_back(temp);
	}
	vector<int>invi;
	for(int i=0 ; i<n_eq; i++)
	{
		temp = inverse(m[i],y[i]);
		invi.push_back(temp);
	}
	cout << "here2" << endl;
	int ans =0;
	for(int i=0 ; i<n_eq; i++)
	{
		ans = ans + (a[i] * invi[i] * m[i]);
	}
	ans = ans % M;
	cout << "the ans is --> " << ans << endl;
	return 0;
}




