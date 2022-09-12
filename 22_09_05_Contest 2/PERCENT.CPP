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
#define taskname "PERCENT"

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

    const int MAX_TYPE = 5;

    int n, type[MAX_TYPE];

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> type[0];
        int g = type[0];
        for (int j = 1; j < MAX_TYPE; ++j) {
            cin >> type[j];
            g = gcd(g, type[j]);
        }
        cout << 100 / g << '\n';
    }

    return 0;
}
