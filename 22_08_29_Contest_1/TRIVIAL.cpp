#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<climits>
#include<cstring>
#include<iomanip>
#include<string>
#include<bitset>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<algorithm>
#include<functional>
#include<random>
#include<sstream>

#define y0 asdahsdlkahsdad
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define taskname "TRIVIAL"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

const int MAX_N = 1e4 + 1;

static int s[MAX_N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(taskname".inp", "r")) {
        freopen(taskname".inp", "r", stdin);
        //freopen(taskname".out", "w", stdout);
    }
//36 6 16 13 28 25 24
    int a, b;
    cin >> a >> b;
//    int sqrtb = sqrt(b);
//    cout << sqrtb << '\n';
    for (int i = 1; i <= b; ++i)
        for (int j = i + i; j <= b; j += i)
            s[j] += i;
    int c, d;
    ld mi = 1e18, ma = -1;
    for (int i = a; i <= b; ++i)
    {
        ld val = s[i] / (ld)i;
        if (val > ma) ma = val, d = i;
        if (val < mi) mi = val, c = i;
        //cout << s[i] << ' ';
    }
    cout << c << ' ' << d;

    return 0;
}
