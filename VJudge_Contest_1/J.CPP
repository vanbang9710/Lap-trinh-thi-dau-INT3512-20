// https://vjudge.net/problem/UVA-1203/origin Modify set while iterating it
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
#define taskname "J"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

const int MAX_N = 2000;

int n_query;
int q_num[MAX_N], period[MAX_N];

struct TQuery {
  int time;
  int id;
  TQuery(const int time, const int id) : time(time), id(id) {}
};
ostream& operator<<(ostream& os, const TQuery& q) {
  os << q.time << ' ' << q.id;
  return os;
}
auto cmp = [](TQuery a, TQuery b) {
  if (a.time != b.time) return a.time < b.time;
  return q_num[a.id] < q_num[b.id];
};
set<TQuery, decltype(cmp)> se(cmp);

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if (fopen(taskname ".inp", "r")) {
    freopen(taskname ".inp", "r", stdin);
    freopen(taskname ".out", "w", stdout);
  }

  string s;
  int n = 0;
  while (cin >> s) {
    if (s[0] == '#') {
      cin >> n_query;
      // cout << n_query << '\n';
      for (auto it = se.begin(); --n_query >= 0 && it != se.end(); ) {
        // cout << it->time << ' ';
        cout << q_num[it->id] << '\n';
        se.insert(TQuery(it->time + period[it->id], it->id));
        // ++it;
        it = se.erase(it);
      }
      break;
    } else {
      cin >> q_num[n] >> period[n];
      se.insert(TQuery(period[n], n));
      // cout << q_num[n] << ' ' << period[n] << '\n';
      // for (auto& q : se) {
      //   cout << q << ' ';
      // }
      // cout << '\n';
      ++n;
    }
  }

  return 0;
}
