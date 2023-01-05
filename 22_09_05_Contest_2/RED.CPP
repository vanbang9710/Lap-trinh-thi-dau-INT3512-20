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
#define taskname "RED"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

const int MAX_N = 2e5;
const int MAX_A = 2e5;

int n, k;
static int a[MAX_N], s[MAX_N], cnt[MAX_A];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(taskname".inp", "r")) {
        freopen(taskname".inp", "r", stdin);
        freopen(taskname".out", "w", stdout);
    }

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        s[i] = cnt[a[i]]++;
    }
    // cout << n << ' ' << k << '\n';
    // for (int i = 1; i <= n; ++i)
    //     cout << a[i] << ' ';
    // cout << '\n';
    while (--k >= 0) {
        int i;
        cin >> i;
        // cout << i << ' '; 
        cout << s[i] << ' ' << cnt[a[i]] - s[i] - 1 << '\n';
    }

    return 0;
}
