#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <climits>
#include <cstring>
#include <iomanip>
#include <string>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
#include <functional>
#include <random>
#include <sstream>

#define y0 asdahsdlkahsdad
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define taskname "BACT"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(taskname ".inp", "r"))
    {
        freopen(taskname ".inp", "r", stdin);
        freopen(taskname ".out", "w", stdout);
    }

    int a, b, c, d, preA = -1;
    ll k;
    cin >> a >> b >> c >> d >> k;
    //cout << a << b << c << d << k << '\n';
    while (--k >= 0)
    {
        preA = a;
        a = a * b - c;
        if (a <= 0)
        {
            a = 0;
            break;
        }
        if (a > d)
            a = d;
        if (a == preA)
            break;
    }
    cout << a;

    return 0;
}
