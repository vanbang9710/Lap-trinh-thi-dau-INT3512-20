#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <climits>
#include <cstring>
#include <iomanip>
#include <string>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
#include <functional>
#include <random>
#include <sstream>

#define y0 asdahsdlkahsdad
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define taskname "CUBE"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

const int FACES = 7;

static int cnt[FACES], cnt1[FACES], ans[FACES];
int a, b, c;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(taskname ".inp", "r"))
    {
        freopen(taskname ".inp", "r", stdin);
        freopen(taskname ".out", "w", stdout);
    }

    cin >> a >> b >> c;
    //cout << a << ' ' << b << ' ' << c << '\n';
    if (b == 1)
        swap(a, b);
    if (a == 1)
    {
        if (b == 1)
        {
            cnt[5] = 1;
        }
        else
        {
            cnt[4] = 2;
            cnt[3] = b - 2;
        }
    }
    else
    {
        cnt[3] = 4;
        cnt[2] = (a - 2 + b - 2) * 2;
        cnt[1] = a * b - cnt[2] - cnt[3];
        // cnt[1] = (a - 2) * (b - 2);
    }
    if (c == 1)
    {
        for (int i = FACES - 1; i > 0; --i)
        {
            ans[i] = cnt[i - 1];
        }
        ans[0] = 0;
    } else {
        for (int i = 1; i < FACES; ++i) {
            cnt1[i - 1] = cnt[i];
        }
        cnt[6] = 0;
        for (int i = 0; i < FACES; ++i) {
            ans[i] = cnt[i] * 2 + cnt1[i] * (c - 2);
        }
    }
    for (int i = 0; i < FACES; ++i) {
        cout << ans[i] << ' ';
    }

    return 0;
}
