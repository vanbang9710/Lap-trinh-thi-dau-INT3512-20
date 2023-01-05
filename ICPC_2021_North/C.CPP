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
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define y0 asdahsdlkahsdad
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define taskname "C"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if (fopen(taskname ".inp", "r")) {
    freopen(taskname ".inp", "r", stdin);
    freopen(taskname ".out", "w", stdout);
  }

  const int SIZE = 100;

  int Q, n, i, j, k;
  string s;
  static ld a[SIZE][SIZE], ratio;

  cin >> Q;
  while (--Q >= 0) {
    cin >> s;
    // cout << s << '\n';
    n = s.length();
    // for (j = 0; j < n; j++) {
    //     for (k = 0; k <= n + 1; k++)
    //         a[j][k] = 0;
    //     a[j][j] = 1;
    //     a[j][j + 1] = -0.5;
    //     a[j][n + 1] = 1;
    //     char c = (s[j] == '0') ? '1' : '0';
    //     for (k = j; k > 0; --k) {
    //         if (s.substr(0, k) == (s.substr(j - k + 2, k - 1) + c)) {
    //             break;
    //         }
    //     }
    //     a[j][k] += -0.5;
    // }
    // a[n][n] = 1;
    for (int i = 0; i <= n; i++) {
      a[i][i] = 1;
      a[i][n + 1] = (i == n) ? 0 : 1;
    }
    // for (j = 0; j <= n; j++) {
    //   for (k = 0; k <= n + 1; k++) {
    //     cout << a[j][k] << ' ';
    //   }
    //   cout << '\n';
    // }
    for (int i = 0; i < n; i++) {
      string from = s.substr(0, i);
      for (char c = '0'; c <= '1'; c++) {
        string to = from + c;
        for (int j = i + 1; j >= 0; --j) {
          string pref_j = s.substr(0, j);
          // if (to.substr(i + 1 - j, j) == pref_j) {
          if (to.ends_with(pref_j)) {
            a[i][j] -= 0.5;
            break;
          }
        }
      }
    }
    // for (j = 0; j <= n; j++) {
    //   for (k = 0; k <= n + 1; k++) {
    //     cout << a[j][k] << ' ';
    //   }
    //   cout << '\n';
    // }

    cout << setprecision(12) << fixed;
    /* Applying Gauss Jordan Elimination */
    for (i = 0; i <= n; i++) {
      if (a[i][i] == 0.0) {
        cout << "Mathematical Error!";
        exit(0);
      }
      for (j = 0; j <= n; j++) {
        if (i != j) {
          ratio = a[j][i] / a[i][i];
          for (k = 0; k <= n + 1; k++) {
            a[j][k] = a[j][k] - ratio * a[i][k];
          }
        }
        // for (k = 1; k <= n + 1; k++) {
        //   cout << a[j][k] << ' ';
        // }
        // cout << '\n';
      }
      //   cout << '\n';
    }
    cout << a[0][n + 1] / a[0][0] << '\n';
  }

  return 0;
}
