#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define y0 asdahsdlkahsdad
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define taskname "CANDY"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

const int MAX_N = 2e5, MAX_M = 5e3 * 2;

static int n, ans, ans1;
static int a[MAX_N], cnt[MAX_M];

template <typename T>
struct TBIT {
  T lab[MAX_M];
  int n, p;
  inline void Init(int N) {
    n = N;
    fill(lab + 1, lab + 1 + n, 0);
    // copy(a + 1, a + 1 + n, lab + 1);
    // for (int x = 1; x <= n; ++x)
    //     for (int y = x - 1, q = x & y; y > q; y &= y - 1)
    //         lab[x] += lab[y];
    p = 1;
    while ((p << 1) <= n) p <<= 1;
  }
  inline void Update(int i, T val) {
    for (; i <= n; i += i & -i) lab[i] += val;
  }
  inline T Get(int i) {
    T ans = 0;
    for (; i > 0; i &= i - 1) ans += lab[i];
    return ans;
  }
  inline int Find(T t) {
    int x = 0;
    for (int p1 = p; p1 > 0; p1 >>= 1) {
      int y = x + p1;
      if (y <= n && lab[y] <= t) x = y, t -= lab[y];
    }
    return x;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if (fopen(taskname ".inp", "r")) {
    freopen(taskname ".inp", "r", stdin);
    freopen(taskname ".out", "w", stdout);
  }

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (++cnt[a[i]] == 1) ++ans1;
  }
  TBIT<int> BIT;
  BIT.Init(MAX_M - 1);
  for (int i = n - 1; i >= 0; --i) {
    int point = BIT.Get(a[i]);
    if (point > 0) {
      ans = max(ans, a[i] + point);
    }
    BIT.Update(a[i], 1);
  }
  if (ans == 0) ans = ans1;
  cout << ans;

  return 0;
}
