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
#define taskname "G"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

const int MAX_N = 6e5;
const int MOD = 1e9 + 7;

static int T, n;
static ll ans, s[MAX_N], s1[MAX_N], s2[MAX_N];
string a;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(taskname".inp", "r")) {
        freopen(taskname".inp", "r", stdin);
        freopen(taskname".out", "w", stdout);
    }

    cin >> T;
    while (--T >= 0) {
        cin >> a;
        // cout << s << '\n';
        n = a.size();
        a = char(0) + a;
        for (int i = 1; i <= n; ++i) {
            a[i] -= 'a' - 1;
            s[i] = (s[i - 1] + a[i]) % MOD;
            s1[i] = (s1[i - 1] + s[i]) % MOD;
            s2[i] = (s2[i - 1] + s[i] * i) % MOD;
        }
        ans = 0;
        for (int j = n; j >= 1; --j) {
            ans = (ans + s[j] * j % MOD * j) % MOD;
            ans = (ans - j * ll(j - 1) / 2 % MOD * s[j] % MOD) % MOD;
            if (ans < 0) ans += MOD;
            ans = (ans - s1[j - 1] * j % MOD) % MOD;
            if (ans < 0) ans += MOD;
            ans = (ans + s2[j - 1]) % MOD;
        }
        cout << ans;
        cout << '\n';
    }

    return 0;
}
