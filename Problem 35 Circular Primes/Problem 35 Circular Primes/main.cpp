//         /\_/\
//   _____/ o o \
//  /~____  =ø= /
// (______)__m_m)

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <deque>
#include <set>
#include <map>
#include <utility>
#include <sstream>
#include <stack>
#include <queue>
#include <climits>
#include <limits>
#include <cstring>

#define pb push_back
#define pf push_front
#define all(c) c.begin(), c.end()
#define tr(c, it) \
for(typeof(c.begin()) it = c.begin(); it!=c.end(); ++it)
#define present(container, element) (find(all(container),element) != container.end())
#define present2(c,x) ((c).find(x) != (c).end()) // For maps and set

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const long double PI = 3.141592653589793238462643383;
const ll MOD = 1000000007;
const double EPS = 1e-9; // a==b is abs(a-b)<EPS, a>=b is a>b-EPS, a>b is a>=b+EPS
const int MAX_INT = 2147483647;

using namespace std;

const int MAX = 1000000;
const int MAX2 = 10000000;

vector<bool> isPrime(MAX2 + 1, 1);

void doSieve()
{
    isPrime[0] = false;
    isPrime[1] = false;
    isPrime[2] = true;
    for (int i = 4; i <= MAX2; i+=2)
        isPrime[i] = false;
    
    for (int i = 3; i <= int(sqrt(double(MAX2))) + 1; i += 2)
    {
        for (int j = i * i; j <= MAX2; j += i)
        {
            isPrime[j] = false;
        }
    }
}

int lon(int n)
{
    int ans = 0;
    
    while (n > 0)
    {
        n /= 10;
        ++ans;
    }
    return ans;
}

int main()
{
    doSieve();
    
    int count = 1; // already counting 2
    
    for (int i = 3; i <= MAX; i += 2)
    {
        if (isPrime[i])
        {
            int n = lon(i);
            int j = i;
            
            int ten = 1;
            for (int k = 1; k < n; ++k)
            {
                ten *= 10;
            }
            
            bool flag = true;
            
            for (int k = 1; k < n; ++k)
            {
                int firstDigit = j / ten;
                j = j % ten;
                j = 10 * j + firstDigit;
                
                if (!isPrime[j])
                {
                    flag = false;
                    break;
                }
            }
            
            if (flag)
                ++count;
        }
    }
    
    cout << count << endl;
}