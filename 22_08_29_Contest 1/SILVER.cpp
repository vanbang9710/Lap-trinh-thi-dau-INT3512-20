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
#define taskname "SILVER"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(taskname".inp", "r")) {
        freopen(taskname".inp", "r", stdin);
        //freopen(taskname".out", "w", stdout);
    }

    int n, a, ma = -1, ma1 = -2;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        if (a > ma) {
            ma1 = ma;
            ma = a;
        } else if (a > ma1 && a < ma) {
            ma1 = a;
        }
    }
    cout << ma1;

    return 0;
}
