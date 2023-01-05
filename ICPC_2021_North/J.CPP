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
#define taskname "J"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

const ll MAX_N = 200;

int n;
ll M;
ll a[MAX_N], b[MAX_N];

bool Chk(ll d) {
    ll sum = M;
    for (int i = 0; i < n; ++i) {
        ll cycle = d / (b[i] + 1);
        ll r = d - cycle;
        //cout << sum << ' ' << r << '\n';
        if ((ld)sum / a[i] <= r) return true;
        sum -= r * a[i];
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(taskname".inp", "r")) {
        freopen(taskname".inp", "r", stdin);
        freopen(taskname".out", "w", stdout);
    }

    cin >> n >> M;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        // cout << a[i] << ' ' << b[i] << '\n';
    }
    ll l = 1, r = 3 * M;
    while (l <= r) {
        ll m = ((l + r) >> 1);
        if (Chk(m)) r = m - 1;
        else l = m + 1;
    }
    cout << l;
    // cout << Chk(11);

    return 0;
}
