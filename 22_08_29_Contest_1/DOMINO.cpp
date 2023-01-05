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
#define taskname "DOMINO"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MAX_N = 5e6;
int n;
//int a[MAX_N], b[MAX_N], c[MAX_N];
int a, b;
bitset<MAX_N * 6>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(taskname".inp", "r")) {
        freopen(taskname".inp", "r", stdin);
        freopen(taskname".out", "w", stdout);
    }

    cin >> n;
    for (int i = 0; i < n; ++i) {
//        cin >> a[i] >> b[i];
//        c[i] = a[i] - b[i];
        cin >> a >> b;
        a -= b;
    }


    return 0;
}
