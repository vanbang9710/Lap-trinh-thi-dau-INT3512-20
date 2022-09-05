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
#define taskname "MAXDIFF"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

const int MAX_N = 2e5 + 1;

static int s[MAX_N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(taskname".inp", "r")) {
        freopen(taskname".inp", "r", stdin);
        freopen(taskname".out", "w", stdout);
    }

    int n;
    string str;
    cin >> n >> str;
    char a = str[0];
//    for (int i = 0; i < n; ++i) {
//        cout << (int)str[i] << ' ';
//    }
//    cout << (int)a << '\n';
    int maxs = 0, mins = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        if (str[i] != a) s[i + 1] = s[i] + 1;
        else s[i + 1] = s[i] - 1;
        if (mins > s[i]) mins = s[i];
        if (maxs < s[i]) maxs = s[i];
//        cout << mins << ' ' << maxs << ' ' << s[i + 1] << '\n';
        int temp = abs(s[i + 1] - mins);
        if (temp > ans) ans = temp;
        temp = abs(s[i + 1] - maxs);
        if (temp > ans) ans = temp;
    }
    cout << ans;

    return 0;
}
