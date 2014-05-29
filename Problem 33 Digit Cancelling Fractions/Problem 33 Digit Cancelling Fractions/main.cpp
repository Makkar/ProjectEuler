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

int gcd(int a, int b)
{
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

int digitInCommon(int a, int b) // a < b && a and b are 2-digit numbers
{
    int ans = 0;
    
    int x1 = a / 10;
    int x2 = a % 10;
    
    int y1 = b / 10;
    int y2 = b % 10;
    
    if (x1 == y1)
        ans = 100 + 10 + x1;
    
    else if (x1 == y2)
        ans = 100 + 20 + x1;
    
    else if (x2 == y1)
        ans = 200 + 10 + x2;
    
    else if (x2 == y2 && x2 != 0)
        ans = 200 + 20 + x2;
    
    return ans;
}

int main()
{
    vector<int> finalNum;
    vector<int> finalDenom;
    
    for (int num = 10; num <= 99; ++num)
    {
        for (int denom = num + 1; denom <= 99; ++denom)
        {
            int d = digitInCommon(num, denom);
            
            if (d)
            {
                int reducedNum, reducedDenom;
                
                if (d / 100 == 1)
                    reducedNum = num % 10;
                else
                    reducedNum = num / 10;
                
                d = d % 100;
                
                if (d / 10 == 1)
                    reducedDenom = denom % 10;
                else
                    reducedDenom = denom / 10;
                
                if (num * reducedDenom == denom * reducedNum)
                {
                    finalNum.push_back(num);
                    finalDenom.push_back(denom);
                }
            }
        }
    }
    
    int prodOfNum = finalNum[0] * finalNum[1] * finalNum[2] * finalNum[3];
    int prodOfDenom = finalDenom[0] * finalDenom[1] * finalDenom[2] * finalDenom[3];
    
    int g = gcd(prodOfNum, prodOfDenom);
    
    cout << prodOfDenom / g << endl;
}