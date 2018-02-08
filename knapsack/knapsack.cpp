					//knapsack cryptosystem
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;
typedef long long int ll;
int main()
{
	ll sz,temp;
	cout << "enter the size of the message" << endl;
	cin >> sz;
	vector<ll>mess;
	for(ll i=0 ; i<sz ; i++)
	{
		cin >> temp;
		mess.push_back(temp);
	}
	// choosing of super increasing tuple
	vector<ll>sit;
	temp = (rand() % 10)+1;
	sit.push_back(temp);
	int sum = sum + temp;
	for(ll i=1 ;i<sz ; i++)
	{
		temp = (rand() % (sum+1))+(sum+10);
		sit.push_back(temp);
		sum = sum + temp;
	}
	
	return 0;
	
}
