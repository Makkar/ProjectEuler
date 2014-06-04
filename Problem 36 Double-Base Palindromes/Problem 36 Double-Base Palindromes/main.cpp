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

string intToString(int n)
{
    string ans = "";
    
    while (n > 0)
    {
        ans = char(n%10 + 48) + ans;
        n /= 10;
    }
    
    return ans;
}

bool isPalin(string s)
{
    int n = s.size();
    
    for (int i = 0; i < n-i-1; ++i)
    {
        if (s[i] != s[n-i-1])
        {
            return false;
        }
    }
    return true;
}

bool isPalinNum(int n)
{
    string s = intToString(n);
    return isPalin(s);
}

string decimalToBinary(int n)
{
    string s = "";
    
    while (n > 0)
    {
        s = char((n % 2) + 48) + s;
        n /= 2;
    }
    
    return s;
}

int main()
{
    ll sum = 0;
    
    for (int i = 1; i < MAX; i+=2)
    {
        if (isPalinNum(i) && isPalin(decimalToBinary(i)))
        {
            sum += i;
        }
    }
    
    cout << sum << endl;
}