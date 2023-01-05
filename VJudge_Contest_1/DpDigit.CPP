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
#define taskname "A"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int T;
ll f[16][2][136], a;
string b;
stringstream cnv;

inline ll Getf(int pos, bool prefix, int sum) {
  if (pos >= b.size()) return sum;
  if (f[pos][prefix][sum] != -1) return f[pos][prefix][sum];
  ll res = 0;
  int limit = prefix ? b[pos] : 9;
  for (int d = 0; d <= limit; ++d)
    res += Getf(pos + 1, prefix && d == limit, sum + d);
  return f[pos][prefix][sum] = res;
}

inline void Solve() {
  cin >> a >> b;
  for (char& c : b) c -= '0';
  memset(&f, -1, sizeof f);
  ll ans = Getf(0, 1, 0);
  if (a == 0) {
    cout << ans << '\n';
    return;
  }
  cnv << --a << '\n';
  cnv >> b;
  for (char& c : b) c -= '0';
  memset(&f, -1, sizeof f);
  ans -= Getf(0, 1, 0);
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if (fopen(taskname ".inp", "r")) {
    freopen(taskname ".inp", "r", stdin);
    freopen(taskname ".out", "w", stdout);
  }

  cin >> T;
  for (int i = 1; i <= T; ++i) Solve();
  return 0;
}
