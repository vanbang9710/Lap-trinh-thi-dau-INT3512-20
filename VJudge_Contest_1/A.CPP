// DP Digit https://vjudge.net/problem/UVA-417/origin
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

const int MAX_N = 100;
const int N_ALPHA = 26;

string b;
static int f[MAX_N][2][N_ALPHA];
int ans;

int GetF(int pos, bool prefix, int min_d) {
  if (pos >= b.size()) return 1;
  int &f_ = f[pos][prefix][min_d];
  if (f_ != -1) return f_;
  f_ = 0;
  int max_d = prefix ? b[pos] : N_ALPHA - 1;
  for (int d = min_d + 1; d <= max_d; ++d) {
    f_ += GetF(pos + 1, prefix && d == max_d, d);
  }
  return f_;
}

int Calc(string &s) {
  b = s;
  for (char &c : b) {
    c -= 'a';
  }
  memset(&f, -1, sizeof f);
  return GetF(0, 1, -1);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if (fopen(taskname ".inp", "r")) {
    freopen(taskname ".inp", "r", stdin);
    freopen(taskname ".out", "w", stdout);
  }

  vector<int> f_pre(1, 0);
  string s;
  for (int i = 1; i <= MAX_N; ++i) {
    s = string(i, 'z');  // repeat 'z' i times
    f_pre.push_back(Calc(s));
    // cout << f_pre[i] << ' ';
  }
  for (int i = 1; i < f_pre.size(); ++i) {
    f_pre[i] += f_pre[i - 1];
    // cout << f_pre[i] << ' ';
  }
  while (cin >> s) {
    bool flag = 0;
    for (int i = 1; i < s.size(); ++i) {
      if (s[i] <= s[i - 1]) {
        flag = 1;
        break;
      }
    }
    if (flag) {
      cout << "0\n";
      continue;
    }
    int ans = 0;
    ans = f_pre[s.size() - 1] + Calc(s);
    cout << ans << '\n';
  }

  return 0;
}
