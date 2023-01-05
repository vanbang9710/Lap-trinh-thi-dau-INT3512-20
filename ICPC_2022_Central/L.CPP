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
#define taskname "L"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

typedef pair<double, double> point;
typedef pair<point, double> circle;
#define X first
#define Y second

inline point operator+(point& a, point& b) { return point(a.X + b.X, a.Y + b.Y); }
inline point operator-(point& a, point& b) { return point(a.X - b.X, a.Y - b.Y); }
inline point operator/(point a, double x) { return point(a.X / x, a.Y / x); }
inline double abs(point a) { return sqrt(a.X * a.X + a.Y * a.Y); }

inline point center_from(double bx, double by, double cx, double cy) {
  double B = bx * bx + by * by, C = cx * cx + cy * cy, D = bx * cy - by * cx;
  return point((cy * B - by * C) / (2 * D), (bx * C - cx * B) / (2 * D));
}

inline circle circle_from(point& A, point& B, point& C) {
  point I = center_from(B.X - A.X, B.Y - A.Y, C.X - A.X, C.Y - A.Y);
  return circle(I + A, abs(I));
}

const double EPS = 1e-9;
const int MAX_N = 503;
const circle blank = circle(point(0, 0), -1);

int n, N;
point a[MAX_N * (MAX_N + 1) / 2];
circle ans[MAX_N];
vector<point> T;

inline circle f(int n) {
  if (T.size() == 3 || n == 0) {
    if (T.size() == 0) return blank;
    if (T.size() == 1) return circle(T[0], 0);
    if (T.size() == 2) return circle((T[0] + T[1]) / 2, abs(T[0] - T[1]) / 2);
    return circle_from(T[0], T[1], T[2]);
  }
  circle Result = f(0);
  int len = 0, cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (i > len) {
      // if (T.empty()) ans[cnt] = Result;
      random_shuffle(a + len + 1, a + len + (++cnt));
      len += cnt;
    }
    if (abs(Result.X - a[i]) > Result.Y + EPS) {
      T.push_back(a[i]);
      Result = f(i - 1);
      T.pop_back();
    }
  }
  // if (n + 1 > len && T.empty()) ans[cnt] = Result;
  return Result;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if (fopen(taskname ".inp", "r")) {
    freopen(taskname ".inp", "r", stdin);
    freopen(taskname ".out", "w", stdout);
  }

  cin >> N;
  int n = N * (N + 1) / 2;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].X >> a[i].Y;
  }

  cout << fixed << setprecision(8);
	// vector<point> T;
  circle Result = f(0);
  int len = 0, cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (i > len) {
      random_shuffle(a + len + 1, a + len + (++cnt));
      len += cnt;
    }
    if (abs(Result.X - a[i]) > Result.Y + EPS) {
      T.push_back(a[i]);
      Result = f(i - 1);
      T.pop_back();
    }
    if (i == len) cout << Result.X.X << ' ' << Result.X.Y << ' ' << Result.Y << '\n';
  }
  // for (int i = 1; i <= N; i++) {
  //   auto &c = ans[i];
  //   cout << c.X.X << ' ' << c.X.Y << ' ' << c.Y << '\n';
  // }

  return 0;
}
