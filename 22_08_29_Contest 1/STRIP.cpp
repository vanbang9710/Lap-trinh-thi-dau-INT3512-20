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
#define taskname "STRIP"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(taskname".inp", "r")) {
        freopen(taskname".inp", "r", stdin);
        freopen(taskname".out", "w", stdout);
    }

    int n, c, c1 = -2, c2 = -1, len1c = 0, len2c = 0, ans = 0, pos;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> c;
        if (c != c1) {
            if (c != c2) {
                c1 = c2;
                c2 = c;
                len2c = len1c + 1;
                len1c = 1;
            } else {
                ++len2c;
                ++len1c;
            }
        } else {
            swap(c1, c2);
            ++len2c;
            len1c = 1;
        }
        if (len2c > ans) {
            ans = len2c;
            pos = i;
        }
        //cout << c1 << ' ' << c2 << ' ' << len1c << ' ' << len2c << '\n';
    }
    cout << pos - ans + 2 << ' ' << ans;

    return 0;
}
