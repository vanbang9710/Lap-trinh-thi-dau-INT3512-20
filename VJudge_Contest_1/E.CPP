//
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
#define taskname "E"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

string s;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if (fopen(taskname ".inp", "r")) {
    freopen(taskname ".inp", "r", stdin);
    freopen(taskname ".out", "w", stdout);
  }

  string a, b;
  cin >> a >> b;
  reverse(a.begin(), a.end());
  cout << a << ' ' << b << '\n';
  string t, d = "";
  getline(cin, t);
  for (int i = 0; i < 4; ++i) {
    getline(cin, t);
    cout << t << '\n';
    s = d = "";
    string a_ = a;
    for (char c : t) {
      if (c == ' ') continue;
      if (c == 'i') {
        s.push_back(a_.back());
        a_.pop_back();
      } else {
        d.push_back(s.back());
        s.pop_back();
      }
      cout << c << ' ' << setw(5) << a_ << ' ' << setw(5) << s << ' ' << setw(5) << d << '\n';
    }
  }

  return 0;
}
