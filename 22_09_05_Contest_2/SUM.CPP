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
#define taskname "SUM"

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

    int n;
    cin >> n;
    int x = sqrt(n); // Find x_max: 1 + 2 + 3 +... + x + (x - 1) + (x - 2) +... + 1 <= n <=> x^2 - n <= 0
    int remain = n - x * x;
    int ans = x * 2 - 1 + (remain + x - 1) / x;
    // cout << n << '\n'
    //      << x << ' ' << remain << '\n';
    cout << ans;

    return 0;
}
