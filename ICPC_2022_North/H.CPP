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
#define taskname "H"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

typedef pair<int, int> TPair;

const int MAX_N = 3e5;

static int Q, x;
// static unsigned int n;
static int n;
multiset<int> c, d;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(taskname".inp", "r")) {
        freopen(taskname".inp", "r", stdin);
        freopen(taskname".out", "w", stdout);
    }

    cin >> Q;
    ld m = 0;
    while (--Q >= 0) {
        string t;
        cin >> t;
        if (t[0] == 'M') {
            x = -1;
            cout << m << '\n';
        } else {
            cin >> x;
            if (t[0] == 'I') {
                ++n;
                if (n > 1 && (ld)x < m) {
                    c.insert(x);
                } else {
                    d.insert(x);
                }
            } else {
                if ((ld)x < m) {
                    auto pos = c.find(x);
                    if (pos != c.end()) {
                        c.erase(pos);
                        --n;
                    }
                } else {
                    auto pos = d.find(x);
                    if (pos != d.end()) {
                        d.erase(pos);
                        --n;
                    }
                }
            }
            if ((int)c.size() > n / 2) {
                int t = *c.rbegin();
                c.erase(c.find(t));
                d.insert(t);
            } else if ((int)d.size() > n - n / 2) {
                int t = *d.begin();
                d.erase(d.find(t));
                c.insert(t);
            }
            if (n % 2) {
                m = *d.begin();
            } else if (n > 0) {
                m = ld((ll)*d.begin() + *c.rbegin()) / 2;
            }
            // for (auto x : c) cout << x << ' ';
            // cout << "|||";
            // for (auto x : d) cout << x << ' ';
            // cout << "|||" << m << '\n';
        }
        // cout << t << ' ' << x << '\n';
    }

    return 0;
}
