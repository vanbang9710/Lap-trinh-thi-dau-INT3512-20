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
#include<numeric>

#define y0 asdahsdlkahsdad
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define taskname "ROW"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

const int MAX_N = 3e5 + 2, MAX_C = 6;

int n, q;
static int s[MAX_N][MAX_C];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(taskname".inp", "r")) {
        freopen(taskname".inp", "r", stdin);
        freopen(taskname".out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int w, h, c;
        cin >> w >> h >> c;
        for (int j = 1; j <= MAX_C; ++j) {
            s[i][j] = s[i - 1][j];
        }
        s[i][c] += w * h;
    }
    cin >> q;
    while (--q >= 0) {
        int i, j, c;
        cin >> i >> j >> c;
        cout << s[j][c] - s[max(i - 1, 0)][c] << '\n';
    }

    return 0;
}
