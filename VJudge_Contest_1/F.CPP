// F UVA-11111 https://vjudge.net/problem/UVA-11111/origin Stack
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
#define taskname "F"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

const int MAX_N = 1e6;

int sz[MAX_N];   // size
int cap[MAX_N];  // capacity
stack<int> st;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if (fopen(taskname ".inp", "r")) {
    freopen(taskname ".inp", "r", stdin);
    freopen(taskname ".out", "w", stdout);
  }

  string s;
  while (getline(cin, s)) {
    // cout << s << '\n';
    istringstream cin_s(s);
    int i = -1;
    bool flag = 1;  // answer
    while (cin_s >> sz[++i]) {
      // cout << sz[i] << ' ';
      if (sz[i] < 0) {
        st.push(i);
        cap[i] = -sz[i];
      } else {
        if (st.empty() || sz[st.top()] != -sz[i] || cap[st.top()] <= 0) {
          flag = 0;
          break;
        } else {
          st.pop();
          if (!st.empty()) {
            cap[st.top()] -= sz[i];
          }
        }
      }
    }
    if (!st.empty()) {
      flag = 0;
      do {
        st.pop();
      } while (!st.empty());
    }
    cout << (flag ? ":-) Matrioshka!" : ":-( Try again.") << '\n';
  }

  return 0;
}
