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

const ll MOD = 1e9 + 7;

string a;
static ll n, ans, s1, s2;

ll Pow(ll a, int b) {
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
    freopen(taskname ".ans", "w", stdout);
  }

  cin >> a;
  n = a.size();
  //   cout << s << '\n';
  for (char &c : a) {
    c -= '0';
  }
  for (int i = 0; i < n; ++i) {
    s1 = s2 = 0;
    for (int j = i; j < n; ++j) {
      //   sum = (100 * sum % MOD * sum + 20 * sum * s[j] + s[j] * s[j]) % MOD;
      s1 = (10 * s1 + (ll)a[j]) % MOD;
      //   if ((ans += s1 * s1) >= MOD) ans -= MOD;
      ans = (ans + s1 * s1) % MOD;
      //   cout << s1 << ' ';
    }
    // cout << '\n';
  }
  cout << ans;

  return 0;
}
