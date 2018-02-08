#include "primes.h"
#include "random.h"
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
typedef long long int ll; 
unsigned int random_integer(unsigned int lower, unsigned int upper){
    return std::rand() % (upper - lower + 1) + lower;
}

//utility function for computing base^power % modulus quickly
unsigned int pow_mod(unsigned int in_base, unsigned int power, unsigned int modulus){
    if (power == 0){
        return 1;
    }
    unsigned long y = 1;
    unsigned long base = in_base; //allowing overflow to avoid some nastiness
    while (power > 1){
        if (power % 2 == 0){
            base = ((base % modulus) * (base % modulus)) % modulus;
            power = power / 2;
        } else {
            y = (y * base) % modulus;
            base = ((base % modulus) * (base % modulus)) % modulus;
            power = (power - 1)/2;
        }
    }
    return ((base % modulus) * (y % modulus)) % modulus;;
}

//This is the Miller-Rabin primality test
bool is_prime_miller_rabin(unsigned int n){
    if (n == 2){
        return true;
    }
    if (n % 2 == 0){
        return false;
    }
    unsigned int bases[3] = {2, 7, 61};
    unsigned int d = n-1;
    int s = 0;
    //Goal is to find d and s such that n-1 = 2^s * d (d is odd)
    //So d & 1 == 0 implies that the lowest bit is 0 (so 2 divides it)
    while ((d & 1) == 0) { 
        d >>= 1; 
        s++; 
    }
    int i = 0;
    int j = 0;
    unsigned int a = 0;
    unsigned int test_result = 0;
    for (i = 0; i < 3; ++i){
        a = std::min(n-2, bases[i]);
        test_result = pow_mod(a, d, n);
        if (test_result == 1){
            continue;
        } 
        if (test_result == n - 1){
            continue;
        }
        for (j = 1; j < s; j++){
            test_result = pow_mod(test_result, 2, n);
            if (test_result == 1){
                return false;
            }
            if (test_result == n-1){
                break;
            }
        }
        if (j == s){
            return false;
        }
    }
    return true;  
};

//this is the brute force version
bool is_prime_brute_force(unsigned int n){
    unsigned int cutoff = n-1; //BETTER if cutoff = int(std::sqrt(n));
    for(int i = 2; i <= cutoff; i++){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}

//just a wrapper so I can quickly change methods
bool is_prime(unsigned int n){
    return is_prime_miller_rabin(n);
}

//the handler for the outside world
unsigned int random_prime(unsigned int lower, unsigned int upper){
    unsigned int potential_prime = random_integer(lower, upper);
    int steam_valve = 0;
    int cutoff = 500;
    
    while (!is_prime(potential_prime) && steam_valve < cutoff){
        potential_prime = random_integer(lower, upper);
        steam_valve++;
    }
    
    if (steam_valve >= cutoff){
        return 0;
    }
    
    return potential_prime;
}
void print_vec(vector<ll>vec)
{
	for(ll i=0 ; i<vec.size() ; i++)
		cout << vec[i] << " ";
	cout << endl;
}
ll encrpyt(vector<ll>mess, vector<ll>B)
{
	ll sum = 0;
	for(int i=0 ; i<mess.size() ; i++)
	{
		sum = sum + (mess[i] * B[i]);
	}	
	return sum;
}
ll inverse(ll n1,ll mod)
{
	ll in= 0,t=0,r=0;
	ll r1 = mod;
	ll r2 = n1;
	ll t1 = 0;
	ll t2 = 1;
	ll q = 0;
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
void decrypt_fun(vector<ll>&decrypt_data,vector<ll>a,ll r, ll q,ll encrypt_data)
{
	ll decrypt_text = (encrypt_data*inverse(r,q))%q;
    for(int i=a.size()-1 ; i>=0 ; i--)
    {
    	if(decrypt_text >= a[i])
    	{
    		decrypt_data.push_back(1);
    		decrypt_text = decrypt_text-a[i];
    	}
    	else
    		decrypt_data.push_back(0);
    }
}
int main(){
    
    srand(time(NULL));
    
    unsigned int lower = 100; //= 1000000000;
    unsigned int upper = 2000; //= 2000000000;
    ll r= random_prime(lower, upper);
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
	ll q = sum + (rand()%100)+1;
	vector<ll>B;
	for(ll i=0 ; i<sz ; i++)
	{
		temp = (sit[i]*r) % q;
		B.push_back(temp);
	}
	// a,q,r--> private key
	// b -> public key
    ll encrypt_data = encrpyt(mess,B);
    cout << "encrypt_data " << encrypt_data << endl;
    vector<ll>decrypt_data;
    decrypt_fun(decrypt_data,sit,r,q,encrypt_data);
    reverse(decrypt_data.begin(),decrypt_data.end());
    print_vec(decrypt_data);

    return 0;
}
