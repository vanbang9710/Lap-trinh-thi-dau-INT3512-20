// https://icpc-north22.vnoi.info/problem/p_icpc_m
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
#define taskname "millionplex"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

const int MOD = 1e9 + 7;
const int MAX_N = 1e6 + 9;

string a;
// static int n, s[MAX_N], s3[MAX_N], s4[MAX_N];
static int n, s[MAX_N], s2[MAX_N];
static ll s3, s4;
// s = sum s[i], s2 = sum s[i]^2, s3 = sum s[i] * 10^(n-i), s4 = sum s[i]^2 *
// 100^(n-i)

inline ll Pow(ll a, int b) {
  ll res = 1;
  for (; b > 0; b >>= 1) {
    if (b & 1) res = res * a % MOD;
    a = a * a % MOD;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if (fopen(taskname ".inp", "r")) {
    freopen(taskname ".inp", "r", stdin);
    freopen(taskname ".out", "w", stdout);
  }

  cin >> a;
  n = a.size();
  // cout << a << '\n';
  a = (char)0 + a;
  for (int i = 1; i <= n; ++i) {
    a[i] -= '0';
    s[i] = ((ll)s[i - 1] * 10 + a[i]) % MOD;
    s2[i] = (ll)s[i] * s[i] % MOD;
  }
  ll p = 1, p2 = 1;
  for (int i = n; i >= 0; --i) {
    // s3[i] = (s3[i + 1] + s[i] * p) % MOD;
    s3 = (s3 + s[i] * p) % MOD;
    p = p * 10 % MOD;
    // s4[i] = (s4[i + 1] + Squ(s[i]) * p2) % MOD;
    s4 = (s4 + s2[i] * p2) % MOD;
    p2 = p2 * 100 % MOD;
  }
  ll ans = 0;
  ll im = Pow(10, MOD - 2);
  ll im2 = Pow(100, MOD - 2);
  for (int j = n; j >= 1; --j) {
    s3 = (s3 - s[j]);
    s4 = (s4 - s2[j]);
    ans += s2[j] * j;
    ans -= s[j] * s3 * 2;
    ans += s4;
    if ((ans %= MOD) < 0) ans += MOD;
    s3 = s3 * im % MOD;
    s4 = s4 * im2 % MOD;
    // s3 /= 10;
    // s4 /= 100;
  }
  cout << ans;

  return 0;
}
