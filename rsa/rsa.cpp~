#include <algorithm>
#include <iostream>
#include <vector>
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
ll inverse(ll a, ll m)
{
    a = a%m;
    for (ll x=1; x<m; x++)
       if ((a*x) % m == 1)
          return x;
}
ll fast_exp(ll base, ll exp,ll m) {
    ll res=1;
    while(exp>0) {
       if(exp%2==1) res=(res*base)%m;
       base=(base*base)%m;
       exp/=2;
    }
    return res%m;
}
ll encrypt(ll n , ll e, ll plain_text)
{
	
	ll c = fast_exp(plain_text,e,n);
	return c;
}
ll decrypt(ll decrypt_text, ll d, ll n)
{
	ll ans = fast_exp(decrypt_text,d,n);
	return ans;
}

int main()
{
	srand(time(NULL));
	unsigned int lower  = 10;
	unsigned int upper =  200000;
	ll p = random_prime(lower,upper);
	ll q = random_prime(lower,upper);
	cout << "p " << p << " q " << q << endl;
	while(p == q)
	{
		q = random_prime(lower,upper);
	}
	ll plain_text = 13;
	ll n = p*q;
	ll phi = (p-1) * (q-1);
	cout << "phi "<< phi << endl;
	ll e = random_prime(1,p); // e is our p
	cout << "e " << e << endl;
	ll d = inverse(e,phi);
	cout << "d " << d << endl;
	ll encrpyt_text = encrypt(n,e,plain_text);
	cout << encrpyt_text << endl;
	ll decrypt_text = decrypt(encrpyt_text,d,n);
	cout << decrypt_text << endl;
	return 0;
}
