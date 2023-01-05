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

const int MAX_N = 305, MAX_K = MAX_N - 1 >> 1;

int n, k;
string t;
static bool f[MAX_K][MAX_N][MAX_N][2], s[MAX_N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if (fopen(taskname ".inp", "r")) {
    freopen(taskname ".inp", "r", stdin);
    freopen(taskname ".out", "w", stdout);
  }

  cin >> n >> k >> t;
  for (int a = 1; a <= n; ++a) {
    s[a] = (t[a - 1] == 'B');
    cout << s[a];
  }
  cout << n << ' ' << k << '\n' << t << '\n';
  for (int a = n + 1; a >= 0; --a) {
    for (int b = n + 1; b >= a; --b) f[0][a][b][1] = 1;
  }
  for (int c = 1; c < k; ++c) {
    for (int len = n - 1; len > 0; --len) {
      for (int a = 1, b = 1 + len; b <= n; ++a, ++b) {
        f[c][a][b][0] = f[c - s[a]][a - 1][b][1] || f[c - s[b]][a][b + 1][1];
        f[c][a][b][1] = f[c - s[a]][a - 1][b][0] || f[c - s[b]][a][b + 1][0];
      }
    }
  }
  for (int c = 0; c < k; ++c) {
    for (int a = 1; a <= n; ++a) {
      for (int b = 1; b <= n; ++b) {
        cout << f[c][a][b][0];
      }
      cout << '\n';
    }
    cout << '\n';
  }
  for (int c = 0; c < k; ++c) {
    for (int a = 1; a <= n; ++a) {
      if (f[c][a][a + 1][0]) {
        cout << "YES";
        exit(0);
      }
    }
  }
  cout << "NO";

  return 0;
}
