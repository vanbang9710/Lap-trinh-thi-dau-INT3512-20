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
#define taskname "POWER2"

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
    vector<ll> ans;
    cin >> n;
    while (--n >= 0)
    {
        ll a;
        cin >> a;
        ld log2A = log2(a);
        if (ceil(log2A) == floor(log2A))
            ans.push_back(a);
    }
    sort(ans.begin(), ans.end());
    if (ans.empty())
        cout << "No";
    for (ll &a : ans)
        cout << a << ' ';

    return 0;
}
