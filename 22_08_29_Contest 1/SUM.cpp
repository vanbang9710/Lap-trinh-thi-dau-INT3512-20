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
#define taskname "SUM"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

const int MAX_N = 9;

int n = 8, sum = 0, ans = -1e7;
static int a[MAX_N];
int b[MAX_N][MAX_N];

bool Chk(int i, int j) {
    for (int x = 1; x < i; ++x)
        if (a[x] == j || abs(x - i) == abs(a[x] - j))
            return false;
    return true;
}

void Try(int i) {
    if (i > n)
    {
        if (sum > ans)
        {
            ans = sum;

        }
        return;
    }
    for (int j = 1; j <= n; ++j)
    {
        if (Chk(i, j))
        {
            a[i] = j;
            sum += b[i][j];
            Try(i + 1);
            sum -= b[i][j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(taskname".inp", "r"))
    {
        freopen(taskname".inp", "r", stdin);
        freopen(taskname".out", "w", stdout);
    }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> b[i][j];
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 1; j <= n; ++j)
//            cout << b[i][j] << ' ';
//        cout << '\n';
//    }
    Try(1);
    cout << ans;

    return 0;
}
