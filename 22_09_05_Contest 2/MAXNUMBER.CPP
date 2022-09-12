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
#define taskname "MAXNUMBER"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

const int MAX_D = 10;

static string a, b, ans;
static int cntA[MAX_D], cntB[MAX_D];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if (fopen(taskname ".inp", "r")) {
    freopen(taskname ".inp", "r", stdin);
    freopen(taskname ".out", "w", stdout);
  }

  cin >> a >> b;
  // cout << a << '\n' << b << '\n';
  for (char c : a) {
    ++cntA[c - '0'];
  }
  for (char c : b) {
    ++cntB[c - '0'];
  }
  for (int i = MAX_D - 1; i >= 0; --i) {
    if (cntA[i] > 0 && cntB[i] > 0) {
      ans.append(min(cntA[i], cntB[i]), i + '0');
    }
  }
  if (ans.empty()) {
    ans = "No solution";
  } else {
    if (ans[0] == '0') ans.resize(1, '0');
  }
  cout << ans;

  return 0;
}
