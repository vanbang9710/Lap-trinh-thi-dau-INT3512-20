// https://vjudge.net/problem/UVA-10227/origin Hash https://vnoi.info/wiki/algo/string/hash.md#%C4%91%C3%A1nh-gi%C3%A1-%C4%91%E1%BB%99-ch%C3%ADnh-x%C3%A1c:~:text=3.-,Ch%E1%BB%8Dn%20modulo,-N%E1%BA%BFu%20b%E1%BA%A1n%20kh%C3%B4ng
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
#define taskname "P"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

const int MAX_P = 1000;
const int N_MOD = 3;
const int MOD[] = {(int)1e9 + 2277, (int)1e9 + 5277, (int)1e9 + 8277,
                   (int)1e9 + 9277};

int BASE;
int pw[N_MOD][MAX_P];  // power = BASE^p

void InitHash() {
  srand(time(NULL));
  BASE = 300 + rand() % 300;
  for (int j = 0; j < N_MOD; ++j) {
    pw[j][0] = 1;
    for (int i = 1; i < MAX_P; ++i) {
      pw[j][i] = (ll)pw[j][i - 1] * BASE % MOD[j];
    }
  }
}
struct THash {
  int val[N_MOD];

  THash() { memset(val, 0, sizeof val); }
  THash(const string& s) {
    memset(val, 0, sizeof val);
    for (int j = 0; j < N_MOD; ++j) {
      for (int i = 0; i < s.size(); ++i) {
        val[j] = (val[j] + (ll)s[i] * pw[j][i]) % MOD[j];
      }
    }
  }

  void add(char c, int pos) {
    for (int j = 0; j < N_MOD; ++j) {
      val[j] = (val[j] + (ll)c * pw[j][pos]) % MOD[j];
    }
  }
  bool operator<(const THash& x) const {
    for (int j = 0; j < N_MOD; ++j) {
      if (val[j] != x.val[j]) return val[j] < x.val[j];
    }
    return false;
  }
  bool operator!=(const THash& x) const {
    for (int j = 0; j < N_MOD; ++j) {
      if (val[j] != x.val[j]) return true;
    }
    return false;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if (fopen(taskname ".inp", "r")) {
    freopen(taskname ".inp", "r", stdin);
    freopen(taskname ".out", "w", stdout);
  }

  InitHash();
  int T;
  cin >> T;
  string s;
  while (--T >= 0) {
    int p, t;
    cin >> p >> t;
    // cout << p << ' ' << t << '\n';
    vector<THash> h(p, THash());
    getline(cin, s);
    while (getline(cin, s) && s.size() > 1) {
      // cout << s << '\n';
      istringstream cin_s(s);
      int i, j;
      cin_s >> i >> j;
      // cout << i << ' ' << j << '\n';
      h[i - 1].add(1, j);
    };
    sort(h.begin(), h.end());
    int ans = !h.empty();
    for (int i = 1; i < h.size(); ++i) {
      if (h[i - 1] != h[i]) ++ans;
    }
    cout << ans << '\n';
    cout << '\n';
  }

  return 0;
}
